#ifndef QGRIDPLAYER_H
#define QGRIDPLAYER_H

#include <QWidget>

namespace Ui {
class QGridPlayer;
}

class QGridPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit QGridPlayer(QWidget *parent = nullptr);
    ~QGridPlayer();

private:
    Ui::QGridPlayer *ui;
};

#endif // QGRIDPLAYER_H
