#ifndef QGRIDPLAYER_H
#define QGRIDPLAYER_H

#include <QWidget>
#include <QtWidgets>
#include "gridlayout.h"
#include "mediaplayer.h"

namespace Ui {
class QGridPlayer;
}

class QGridPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit QGridPlayer(QWidget *parent = nullptr);
    ~QGridPlayer();

public slots:
    void openFiles();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private:
    Ui::QGridPlayer *ui;
    GridLayout *gridLayout;
    VideoWidget *videoWidget;
    QVector<MediaPlayer *> mediaPlayerVec;
};

#endif // QGRIDPLAYER_H
