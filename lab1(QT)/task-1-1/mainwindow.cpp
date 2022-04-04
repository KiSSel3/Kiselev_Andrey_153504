#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent): QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    scene= new QGraphicsScene(0,0,801,601,this);
    ui->graphicsView->setScene(scene);
    scene -> addRect(scene -> sceneRect());

    body = new signalmanElement(50,100);
    body->setPos(200,200);

    neck = new signalmanElement(10,10);
    neck->setPos(220,190);

    head = new signalmanElement(24,24);
    head->setPos(213,166);

    leftHand = new signalmanElement(10,70);
    leftHand->setPos(190,200);

    rightHand = new signalmanElement(10,70);
    rightHand->setPos(250,200);

    leftLeg= new signalmanElement(10,90);
    leftLeg->setPos(210,300);

    rightLeg= new signalmanElement(10,90);
    rightLeg->setPos(230,300);

    scene->addItem(leftLeg);
    scene->addItem(rightLeg);
    scene->addItem(rightHand);
    scene->addItem(leftHand);
    scene->addItem(neck);
    scene->addItem(body);
    scene->addItem(head);

    up = new QPushButton(this);
    down = new QPushButton(this);
    left = new QPushButton(this);
    right = new QPushButton(this);
    signR = new QPushButton(this);
    signL = new QPushButton(this);

    up->setGeometry(QRect(50,5,40,20));
    up->setText("Up");
    scene->addWidget(up);

    down->setGeometry(QRect(50,30,40,20));
    down->setText("Down");
    scene->addWidget(down);

    left->setGeometry(QRect(5,30,40,20));
    left->setText("Left");
    scene->addWidget(left);

    right->setGeometry(QRect(95,30,40,20));
    right->setText("Right");
    scene->addWidget(right);

    signR->setGeometry(QRect(91,55,44,20));
    signR->setText("R Hand");
    scene->addWidget(signR);

    signL->setGeometry(QRect(1,55,44,20));
    signL->setText("L Hand");
    scene->addWidget(signL);

    connect(up,SIGNAL(pressed()),leftLeg,SLOT(startMoveUp()));
    connect(up,SIGNAL(pressed()),rightLeg,SLOT(startMoveUp()));
    connect(up,SIGNAL(pressed()),rightHand,SLOT(startMoveUp()));
    connect(up,SIGNAL(pressed()),leftHand,SLOT(startMoveUp()));
    connect(up,SIGNAL(pressed()),neck,SLOT(startMoveUp()));
    connect(up,SIGNAL(pressed()),body,SLOT(startMoveUp()));
    connect(up,SIGNAL(pressed()),head,SLOT(startMoveUp()));

    connect(up,SIGNAL(released()),leftLeg,SLOT(stopMoveUp()));
    connect(up,SIGNAL(released()),rightLeg,SLOT(stopMoveUp()));
    connect(up,SIGNAL(released()),rightHand,SLOT(stopMoveUp()));
    connect(up,SIGNAL(released()),leftHand,SLOT(stopMoveUp()));
    connect(up,SIGNAL(released()),neck,SLOT(stopMoveUp()));
    connect(up,SIGNAL(released()),body,SLOT(stopMoveUp()));
    connect(up,SIGNAL(released()),head,SLOT(stopMoveUp()));

    connect(down,SIGNAL(pressed()),leftLeg,SLOT(startMoveDown()));
    connect(down,SIGNAL(pressed()),rightLeg,SLOT(startMoveDown()));
    connect(down,SIGNAL(pressed()),rightHand,SLOT(startMoveDown()));
    connect(down,SIGNAL(pressed()),leftHand,SLOT(startMoveDown()));
    connect(down,SIGNAL(pressed()),neck,SLOT(startMoveDown()));
    connect(down,SIGNAL(pressed()),body,SLOT(startMoveDown()));
    connect(down,SIGNAL(pressed()),head,SLOT(startMoveDown()));

    connect(down,SIGNAL(released()),leftLeg,SLOT(stopMoveDown()));
    connect(down,SIGNAL(released()),rightLeg,SLOT(stopMoveDown()));
    connect(down,SIGNAL(released()),rightHand,SLOT(stopMoveDown()));
    connect(down,SIGNAL(released()),leftHand,SLOT(stopMoveDown()));
    connect(down,SIGNAL(released()),neck,SLOT(stopMoveDown()));
    connect(down,SIGNAL(released()),body,SLOT(stopMoveDown()));
    connect(down,SIGNAL(released()),head,SLOT(stopMoveDown()));

    connect(left,SIGNAL(pressed()),leftLeg,SLOT(startMoveLeft()));
    connect(left,SIGNAL(pressed()),rightLeg,SLOT(startMoveLeft()));
    connect(left,SIGNAL(pressed()),rightHand,SLOT(startMoveLeft()));
    connect(left,SIGNAL(pressed()),leftHand,SLOT(startMoveLeft()));
    connect(left,SIGNAL(pressed()),neck,SLOT(startMoveLeft()));
    connect(left,SIGNAL(pressed()),body,SLOT(startMoveLeft()));
    connect(left,SIGNAL(pressed()),head,SLOT(startMoveLeft()));

    connect(left,SIGNAL(released()),leftLeg,SLOT(stopMoveLeft()));
    connect(left,SIGNAL(released()),rightLeg,SLOT(stopMoveLeft()));
    connect(left,SIGNAL(released()),rightHand,SLOT(stopMoveLeft()));
    connect(left,SIGNAL(released()),leftHand,SLOT(stopMoveLeft()));
    connect(left,SIGNAL(released()),neck,SLOT(stopMoveLeft()));
    connect(left,SIGNAL(released()),body,SLOT(stopMoveLeft()));
    connect(left,SIGNAL(released()),head,SLOT(stopMoveLeft()));

    connect(right,SIGNAL(pressed()),leftLeg,SLOT(startMoveRight()));
    connect(right,SIGNAL(pressed()),rightLeg,SLOT(startMoveRight()));
    connect(right,SIGNAL(pressed()),rightHand,SLOT(startMoveRight()));
    connect(right,SIGNAL(pressed()),leftHand,SLOT(startMoveRight()));
    connect(right,SIGNAL(pressed()),neck,SLOT(startMoveRight()));
    connect(right,SIGNAL(pressed()),body,SLOT(startMoveRight()));
    connect(right,SIGNAL(pressed()),head,SLOT(startMoveRight()));

    connect(right,SIGNAL(released()),leftLeg,SLOT(stopMoveRight()));
    connect(right,SIGNAL(released()),rightLeg,SLOT(stopMoveRight()));
    connect(right,SIGNAL(released()),rightHand,SLOT(stopMoveRight()));
    connect(right,SIGNAL(released()),leftHand,SLOT(stopMoveRight()));
    connect(right,SIGNAL(released()),neck,SLOT(stopMoveRight()));
    connect(right,SIGNAL(released()),body,SLOT(stopMoveRight()));
    connect(right,SIGNAL(released()),head,SLOT(stopMoveRight()));

    connect(signR,SIGNAL(clicked()),this,SLOT(sigRightHand()));
    connect(signL,SIGNAL(clicked()),this,SLOT(sigLeftHand()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::sigLeftHand() {
    static int number = 0;

    if(number==0) {
        leftHand->sigHand(70,10,-60);
        ++number;
    } else if(number==1){
        leftHand->sigHand(10,70,0,-60);
        ++number;
    }else if(number==2){
        leftHand->sigHand(10,70);
        number= 0;
    }
}

void MainWindow::sigRightHand() {
    static int number = 0;

    if(number==0) {
        rightHand->sigHand(70,10);
        ++number;
    }else if(number==1){
        rightHand->sigHand(10,70,0,-60);
        ++number;
    } else if(number==2){
        rightHand->sigHand(10,70);
        number= 0;
    }
}

movingRect::movingRect(int speed) : speed(speed) {
    animationTimerRight = new QTimer(this);
    animationTimerRight->start(1000/30);
    animationTimerRight->stop();
    connect(animationTimerRight,SIGNAL(timeout()),this,SLOT(moveRight()));

    animationTimerDown = new QTimer(this);
    animationTimerDown->start(1000/30);
    animationTimerDown->stop();
    connect(animationTimerDown,SIGNAL(timeout()),this,SLOT(moveDown()));

    animationTimerUp = new QTimer(this);
    animationTimerUp->start(1000/30);
    animationTimerUp->stop();
    connect(animationTimerUp,SIGNAL(timeout()),this,SLOT(moveUp()));

    animationTimerLeft = new QTimer(this);
    animationTimerLeft->start(1000/30);
    animationTimerLeft->stop();
    connect(animationTimerLeft,SIGNAL(timeout()),this,SLOT(moveLeft()));

}

void movingRect::startMoveDown() {
    animationTimerDown->start();
}

void movingRect::moveDown() {
    moveBy(0,speed);
}

void movingRect::stopMoveDown() {
    animationTimerDown->stop();
}

void movingRect::startMoveUp() {
    animationTimerUp->start();
}

void movingRect::moveUp() {
    moveBy(0,-speed);
}

void movingRect::stopMoveUp() {
    animationTimerUp->stop();
}

void movingRect::startMoveLeft() {
    animationTimerLeft->start();
}

void movingRect::moveLeft() {
    moveBy(-speed,0);
}

void movingRect::stopMoveLeft() {
    animationTimerLeft->stop();
}

void movingRect::startMoveRight() {
    animationTimerRight->start();
}

void movingRect::moveRight() {
    moveBy(speed,0);
}

void movingRect::stopMoveRight() {
    animationTimerRight->stop();
}

signalmanElement::signalmanElement(int width, int height) {
    setRect(0,0,width,height);
}

void signalmanElement::sigHand(int width, int height,int x,int y)
{
    setRect(x,y,width,height);

}
