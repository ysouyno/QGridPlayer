#include "clickableslider.h"

ClickableSlider::ClickableSlider(QWidget *parent)
    : QSlider(parent)
{
}

ClickableSlider::ClickableSlider(Qt::Orientation orientation, QWidget *parent)
    : QSlider(orientation, parent)
{
}

void ClickableSlider::mousePressEvent(QMouseEvent *ev)
{
    QSlider::mousePressEvent(ev);

    double pos = static_cast<double>(ev->pos().x()) / width();
    int seconds = static_cast<int>(pos * maximum());
    qInfo("pos().x(): %d, width: %d, max: %d, min: %d, seconds: %d",
          ev->pos().x(), width(), maximum(), minimum(), seconds);

    setValue(seconds);
    emit sliderClicked(seconds);
}
