#include "qgridplayer.h"
#include "ui_qgridplayer.h"

QGridPlayer::QGridPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QGridPlayer)
{
    ui->setupUi(this);

    setAcceptDrops(true);

    gridLayout = new GridLayout;
    setLayout(gridLayout);

    QAction *openAction = new QAction("&Open", this);
    openAction->setShortcut(tr("Ctrl+O"));
    connect(openAction,
            &QAction::triggered,
            this,
            &QGridPlayer::openFiles
            );
    addAction(openAction);

    QAction *relayoutAction = new QAction("&Relayout", this);
    relayoutAction->setShortcut(tr("Ctrl+R"));
    connect(relayoutAction,
            &QAction::triggered,
            gridLayout,
            &GridLayout::relayout
            );
    addAction(relayoutAction);

    QAction *quitAction = new QAction("E&xit", this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction,
            SIGNAL(triggered()),
            qApp,
            SLOT(quit())
            );
    addAction(quitAction);

    setContextMenuPolicy(Qt::ActionsContextMenu);
}

QGridPlayer::~QGridPlayer()
{
    delete ui;
}

void QGridPlayer::openFiles()
{
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Files"));
    fileDialog.setFileMode(QFileDialog::ExistingFiles);

    QStringList supportedMimeTypes = QMediaPlayer::supportedMimeTypes();
    if (!supportedMimeTypes.isEmpty())
        fileDialog.setMimeTypeFilters(supportedMimeTypes);

    fileDialog.setDirectory(
                QStandardPaths::standardLocations(
                    QStandardPaths::MoviesLocation).value(
                    0,
                    QDir::homePath()
                    )
                );
    if (fileDialog.exec() == QDialog::Accepted) {
        QList<QUrl> files = fileDialog.selectedUrls();
        for (int i = 0; i < files.length(); ++i) {
            MediaPlayer *video =
                    new MediaPlayer(this, QMediaPlayer::VideoSurface);
            video->setUrlAndPlay(fileDialog.selectedUrls().at(i));
            gridLayout->add(video->getVideoWidget(), video->getSlider());
            mediaPlayerVec.push_back(video);
        }
    }
}

void QGridPlayer::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/uri-list")) {
        event->acceptProposedAction();
    }
}

void QGridPlayer::dropEvent(QDropEvent *event)
{
    QList<QUrl> files = event->mimeData()->urls();
    if (files.isEmpty()) {
        return;
    }

    foreach (QUrl file, files) {
        qInfo("%s", file.toLocalFile().toStdString().c_str());

        MediaPlayer *video =
                new MediaPlayer(this, QMediaPlayer::VideoSurface);
        video->setUrlAndPlay(file);
        gridLayout->add(video->getVideoWidget(), video->getSlider());
        mediaPlayerVec.push_back(video);
    }
}
