#include "tabbar.h"
#include <QDebug>

TabBar::TabBar(QWidget *parent)
    :QWidget(parent)
{
    setFixedHeight(30);

    currentTabIndex = 0;
    tabNameSize = 11;

    QFont font;
    font.setPointSize(tabNameSize);
    fontMetrics = new QFontMetrics(font);

    layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    QPixmap iconPixmap = QPixmap(":/image/logo.svg");
    iconLabel = new QLabel();
    iconLabel->setFixedSize(24, 24);
    iconLabel->setScaledContents(true);
    iconLabel->setPixmap(iconPixmap);

    //layout->addWidget(iconLabel);
    //layout->addStretch();

    tabNames.insert(0, "首页");
    tabNameWidths.insert(0, fontMetrics->width("首页"));
    tabNames.insert(1, "词典");
    tabNameWidths.insert(1, fontMetrics->width("词典"));
    tabNames.insert(2, "翻译");
    tabNameWidths.insert(2, fontMetrics->width("翻译"));
}

void TabBar::mousePressEvent(QMouseEvent *e)
{
    int prevActiveIndex = currentTabIndex;
    int width = 44 + tabNameWidths[0];

    if (e->x() < width) {
        currentTabIndex = 0;
    }else if (e->x() < width * 2) {
        currentTabIndex = 1;
    }else if (e->x() < width * 3) {
        currentTabIndex = 2;
    }

    if (currentTabIndex != prevActiveIndex) {
        emit switchTab(currentTabIndex);

        repaint();
    }
}
void TabBar::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int tabX = 30;
    int tabNameLeftPadding = 10;
    int tabNameRightPadding = 10;
    int tabNameTopPadding = 5;

    painter.drawPixmap(QRect(0, 5, 24, 24), QPixmap(":/image/logo.svg"));

    for (int i=0; i<3; ++i) {
        QString tabName = tabNames[i];
        int tabNameWidth = tabNameWidths[i];
        int width = tabNameLeftPadding + tabNameWidth + tabNameRightPadding;

        if (i == currentTabIndex) {
            painter.setPen(QPen(QColor("#2CA7F8")));
        }else {
            painter.setPen(QPen(QColor("#FFFFFF")));
        }

        painter.drawText(QRect(tabX + tabNameLeftPadding, tabNameTopPadding, width - tabNameLeftPadding, rect().height() - tabNameTopPadding), Qt::AlignLeft | Qt::AlignTop, tabName);

        if (i == currentTabIndex) {
            QPainterPath tabUnderlinePath;
            tabUnderlinePath.addRect(QRectF(tabX, rect().height() - 2, width, 2));
            painter.fillPath(tabUnderlinePath, QColor("#2CA7F8"));
        }

        tabX += width;
    }

}
