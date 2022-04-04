#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class movingRect : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    movingRect(int speed = 2);

protected:
    int speed;

    QTimer* animationTimerDown;
    QTimer* animationTimerUp;
    QTimer* animationTimerRight;
    QTimer* animationTimerLeft;

private slots:
    void startMoveDown();
    void moveDown();
    void stopMoveDown();

    void startMoveUp();
    void moveUp();
    void stopMoveUp();

    void startMoveLeft();
    void moveLeft();
    void stopMoveLeft();

    void startMoveRight();
    void moveRight();
    void stopMoveRight();
};



class signalmanElement : public movingRect{
    Q_OBJECT

public:
    signalmanElement(int width,int height);

    void sigHand(int width,int height, int x =0,int y=0);
};



class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGraphicsScene* scene;

    QPushButton* up;
    QPushButton* down;
    QPushButton* left;
    QPushButton* right;
    QPushButton* signL;
    QPushButton* signR;

    signalmanElement* body;
    signalmanElement* neck;
    signalmanElement* head;
    signalmanElement* leftLeg;
    signalmanElement* rightLeg;
    signalmanElement* leftHand;
    signalmanElement* rightHand;

private slots:
    void sigLeftHand();
    void sigRightHand();
    //signalmanElement*
    //signalmanElement*
};
#endif // MAINWINDOW_H
