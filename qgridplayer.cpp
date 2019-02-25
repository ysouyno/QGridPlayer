#include "qgridplayer.h"
#include "ui_qgridplayer.h"

QGridPlayer::QGridPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QGridPlayer)
{
    ui->setupUi(this);
}

QGridPlayer::~QGridPlayer()
{
    delete ui;
}
