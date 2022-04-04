#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "rhomb.h"
#include "square.h"
#include "star.h"
#include "hexagon.h"
#include "oval.h"
#include <canva.h>

#include<math.h>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QSlider>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QGraphicsScene *scn;
    Shape* sh = nullptr;
    //Dialog
    QDialog *rectDlg, *triangDlg, *circleDlg, *squareDlg, *rhombDlg, *ovalDlg, *starDlg, *hexDlg;
    QLabel *InputWidth, *InputHeight,
    *InputX1, *InputX2, *InputX3, *InputY1, *InputY2, *InputY3,
    *InputR, *InputA, *Inputr, *InputOvalR, *InputOvalr,
    *InputStarTier, *InputStarR, *InputStarr, *InputHexR;
    QLineEdit *LE_Width, *LE_Height,
    *LE_X1, *LE_X2, *LE_X3, *LE_Y1, *LE_Y2, *LE_Y3,
    *LE_R, *LE_A, *LE_r, *LE_ovalR, *LE_ovalr,
    *LE_starTier, *LE_starR, *LE_starr, *LE_HexR;
    QPushButton *Enter;

    QString currentFigure;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void createRect();
    void createTriang();
    void createCircle();
    void createSquare();
    void createRhomb();
    void createOval();
    void createStar();
    void createHex();

    void on_radioButton_clicked(bool checked);
    void on_radioButton_2_clicked(bool checked);
    void on_radioButton_5_clicked(bool checked);

    void on_radioButton_3_clicked(bool checked);

    void on_radioButton_4_clicked(bool checked);

    void on_radioButton_6_clicked(bool checked);

    void on_radioButton_7_clicked(bool checked);

    void on_radioButton_8_clicked(bool checked);

    void on_horizontalSlider_valueChanged(int value);

    void on_btnRect_clicked();

    void on_rotateSlider_valueChanged(int value);

    void on_upperBtn_clicked();

    void on_leftBtn_clicked();

    void on_bottomBtn_clicked();

    void on_rightBtn_clicked();

    void on_canvaButton_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
