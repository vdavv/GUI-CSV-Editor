#include "logowindow.h"
#include "ui_logowindow.h"
#include <QPainter>
#include <QPainterPath>
#include <QLinearGradient>
#include <QFont>
#include <QRandomGenerator>

LogoWindow::LogoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogoWindow)
{
    ui->setupUi(this);
    // You can add the logo in the .ui file or set it here programmatically
}

LogoWindow::~LogoWindow()
{
    delete ui;
}


void LogoWindow::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    // Set the background gradient
    QLinearGradient bgGradient(0, 0, width(), height());
    bgGradient.setColorAt(0, Qt::white);
    bgGradient.setColorAt(1, Qt::blue);
    painter.setBrush(bgGradient);
    painter.drawRect(0, 0, width(), height());

    // Create the worm-like decorations in the background
    const int numberOfWorms = 10; // Number of worms
    for (int i = 0; i < numberOfWorms; ++i)
    {
        QPainterPath path;
        qreal startX = QRandomGenerator::global()->bounded(static_cast<qreal>(width()));
        qreal startY = QRandomGenerator::global()->bounded(static_cast<qreal>(height()));
        path.moveTo(startX, startY);

        for (int j = 0; j < 5; ++j) { // 5 segments per worm
            qreal ctrl1X = QRandomGenerator::global()->bounded(static_cast<qreal>(width()));
            qreal ctrl1Y = QRandomGenerator::global()->bounded(static_cast<qreal>(height()));
            qreal ctrl2X = QRandomGenerator::global()->bounded(static_cast<qreal>(width()));
            qreal ctrl2Y = QRandomGenerator::global()->bounded(static_cast<qreal>(height()));
            qreal endX = QRandomGenerator::global()->bounded(static_cast<qreal>(width()));
            qreal endY = QRandomGenerator::global()->bounded(static_cast<qreal>(height()));
            path.cubicTo(ctrl1X, ctrl1Y, ctrl2X, ctrl2Y, endX, endY);
        }

        QLinearGradient wormGradient(startX, startY, path.currentPosition().x(), path.currentPosition().y());
        wormGradient.setColorAt(0, Qt::darkGreen);
        wormGradient.setColorAt(1, Qt::lightGray);
        painter.setBrush(wormGradient);
        painter.setPen(Qt::NoPen);

        QPainterPathStroker stroker;
        stroker.setWidth(20); // Width of the worm body
        QPainterPath wormBodyPath = stroker.createStroke(path);

        painter.drawPath(wormBodyPath);

        // Draw eyes on the worm
        painter.setBrush(Qt::white);
        painter.setPen(Qt::black);
        painter.drawEllipse(QPointF(startX, startY), 3, 3);
        painter.drawEllipse(path.currentPosition(), 3, 3);
    }

    QFont font("Arial", 150, QFont::Bold);
    painter.setFont(font);
    painter.setPen(QPen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    QFontMetrics fm(font);
    int textWidthCSV = fm.horizontalAdvance("CSV");
    int textHeightCSV = fm.height();

    painter.drawText((width() - textWidthCSV) / 2, height() / 2 + fm.ascent() / 2, "CSV");

    // Draw the EDITOR text below the CSV text
    QFont fontEditor("Arial", 100, QFont::Bold);
    painter.setFont(fontEditor);

    QFontMetrics fmEditor(fontEditor);
    int textWidthEditor = fmEditor.horizontalAdvance("EDITOR");

    int editorTextX = (width() - textWidthEditor) / 2;
    int editorTextY = height() / 2 + textHeightCSV / 2 + fmEditor.ascent() + 2;  // 50 is the margin between CSV and EDITOR

    painter.drawText(editorTextX, editorTextY, "EDITOR");
}


