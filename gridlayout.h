#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include <QGridLayout>
#include <QVector>
#include <QBoxLayout>

class GridLayout : public QGridLayout
{
public:
    GridLayout();

public:
    void add(QWidget *widget);
    void add(QWidget *widget, QWidget *slider);

public slots:
    void relayout();

private:
    QVector<QWidget *> widgetVec;
    QVector<QVBoxLayout *> verticalLayoutVec;
};

#endif // GRIDLAYOUT_H
