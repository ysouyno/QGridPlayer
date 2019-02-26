#include "gridlayout.h"

#include <QtMath>

GridLayout::GridLayout()
{

}

void GridLayout::add(QWidget *widget)
{
    addWidget(widget);
    widgetVec.push_back(widget);
    relayout();
}

void GridLayout::add(QWidget *widget, QWidget *slider)
{
    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(widget);
    vlayout->addWidget(slider);
    verticalLayoutVec.push_back(vlayout);

    if (1 == verticalLayoutVec.size()) {
        qInfo("grid 1");
        addLayout(verticalLayoutVec.at(0), 0, 0);
    }
    else if (2 == verticalLayoutVec.size()) {
        qInfo("grid 2");
        addLayout(verticalLayoutVec.at(1), 0, 1);
    }
    else if (3 == verticalLayoutVec.size()) {
        qInfo("grid 3");
        addLayout(verticalLayoutVec.at(2), 1, 0);
    }
    else if (4 == verticalLayoutVec.size()) {
        qInfo("grid 4");
        addLayout(verticalLayoutVec.at(3), 1, 1);
    }
}

void GridLayout::relayout()
{
    int widgets_count = count();
    qInfo("current grid layout count: %d", widgets_count);
    if (!widgets_count) {
        return;
    }

    int max_row_count =
            static_cast<int>(ceil(sqrt(static_cast<double>(widgets_count))));

    for (int i = 0; i < widgets_count; ++i) {
        addWidget(widgetVec.at(i), i / max_row_count, i % max_row_count);
    }
}
