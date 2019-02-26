#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QMediaPlayer>
#include <QSlider>
#include "videowidget.h"

class MediaPlayer : public QMediaPlayer
{
public:
    MediaPlayer(QObject *parent = nullptr, Flags flags = Flags());

public:
    VideoWidget *getVideoWidget() const;
    QSlider *getSlider() const;
    void setUrlAndPlay(const QUrl &url);

public slots:
    void seek(int seconds);
    void durationChanged(qint64 duration);
    void positionCHanged(qint64 progress);

private:
    VideoWidget *videoWidget;
    QSlider *slider;
};

#endif // MEDIAPLAYER_H
