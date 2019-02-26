#include "mediaplayer.h"

MediaPlayer::MediaPlayer(QObject *parent, QMediaPlayer::Flags flags)
    : QMediaPlayer(parent, flags)
{
    videoWidget = new VideoWidget;
    setVideoOutput(videoWidget);

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, static_cast<int>(duration() / 1000));
    connect(slider, &QSlider::sliderMoved, this, &MediaPlayer::seek);

    connect(this, &QMediaPlayer::durationChanged, this, &MediaPlayer::durationChanged);
    connect(this, &QMediaPlayer::positionChanged, this, &MediaPlayer::positionCHanged);
}

VideoWidget *MediaPlayer::getVideoWidget() const
{
    return videoWidget;
}

QSlider *MediaPlayer::getSlider() const
{
    return slider;
}

void MediaPlayer::setUrlAndPlay(const QUrl &url)
{
    setMedia(url);
    play();
}

void MediaPlayer::seek(int seconds)
{
    setPosition(seconds * 1000);
}

void MediaPlayer::durationChanged(qint64 duration)
{
    slider->setMaximum(static_cast<int>(duration / 1000));
}

void MediaPlayer::positionCHanged(qint64 progress)
{
    if (!slider->isSliderDown()) {
        slider->setValue(static_cast<int>(progress / 1000));
    }
}
