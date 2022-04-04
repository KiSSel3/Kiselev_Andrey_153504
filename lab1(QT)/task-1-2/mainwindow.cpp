#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scn = new QGraphicsScene();
    ui->graphicsView->setScene(scn);

    ui->radioButton->setChecked(true);

    if (ui->radioButton->isChecked()) {
        scn->clear();
        sh = new triangle();
        scn->addItem(sh);
        sh->m_angle = 0;
         ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));

    }
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    currentFigure = "triangle";

    rectDlg = new QDialog(this);

    InputWidth = new QLabel("Ширина:", rectDlg); InputWidth->adjustSize();
    InputHeight = new QLabel("Высота:", rectDlg); InputHeight->adjustSize();
    LE_Height = new QLineEdit(rectDlg);
    LE_Width = new QLineEdit(rectDlg);

    triangDlg = new QDialog(this);

    InputX1 = new QLabel("X1: ", triangDlg); InputX1->adjustSize();
    InputX2 = new QLabel("X2: ", triangDlg); InputX2->adjustSize();
    InputX3 = new QLabel("X3: ", triangDlg); InputX3->adjustSize();
    InputY1 = new QLabel("Y1: ", triangDlg); InputY1->adjustSize();
    InputY2 = new QLabel("Y2: ", triangDlg); InputY2->adjustSize();
    InputY3 = new QLabel("Y3: ", triangDlg); InputY3->adjustSize();
    LE_X1 = new QLineEdit(triangDlg);
    LE_X2 = new QLineEdit(triangDlg);
    LE_X3 = new QLineEdit(triangDlg);
    LE_Y1 = new QLineEdit(triangDlg);
    LE_Y2 = new QLineEdit(triangDlg);
    LE_Y3 = new QLineEdit(triangDlg);

    circleDlg = new QDialog(this);
    InputR = new QLabel("Радиус: ", circleDlg); InputR->adjustSize();
    LE_R = new QLineEdit(circleDlg);

    squareDlg = new QDialog(this);
    InputA = new QLabel("Сторона: ",squareDlg); InputA->adjustSize();
    LE_A = new QLineEdit(squareDlg);

    rhombDlg = new QDialog(this);
    Inputr = new QLabel("Радиус: ",rhombDlg); InputA->adjustSize();
    LE_r = new QLineEdit(rhombDlg);

    ovalDlg= new QDialog(this);
    InputOvalR = new QLabel("R: ",ovalDlg); InputOvalR->adjustSize();
    InputOvalr = new QLabel("r: ",ovalDlg); InputOvalr->adjustSize();
    LE_ovalR = new QLineEdit(ovalDlg);
    LE_ovalr = new QLineEdit(ovalDlg);

    starDlg = new QDialog(this);
    InputStarTier = new QLabel("Level: ",starDlg); InputStarTier->adjustSize();
    InputStarR = new QLabel("R: ",starDlg); InputStarR->adjustSize();
    InputStarr = new QLabel("r: ",starDlg); InputStarr->adjustSize();
    LE_starTier = new QLineEdit(starDlg);
    LE_starR = new QLineEdit(starDlg);
    LE_starr = new QLineEdit(starDlg);

    hexDlg = new QDialog(this);
    InputHexR = new QLabel("R:", hexDlg); InputHexR->adjustSize();
    LE_HexR = new QLineEdit(hexDlg);

}


MainWindow::~MainWindow()
{
    delete rectDlg; delete triangDlg; delete circleDlg; delete squareDlg; delete  rhombDlg; delete  ovalDlg; delete  starDlg; delete  hexDlg;
    delete InputWidth; delete  InputHeight;
    delete InputX1; delete InputX2; delete InputX3; delete InputY1; delete InputY2; delete InputY3;
    delete InputR; delete InputA; delete Inputr; delete InputOvalR; delete InputOvalr;
    delete InputStarTier; delete InputStarR; delete InputStarr; delete InputHexR;
    delete LE_Width; delete LE_Height;
    delete LE_X1; delete LE_X2; delete LE_X3; delete LE_Y1; delete LE_Y2; delete LE_Y3;
    delete LE_R; delete LE_A; delete LE_r; delete LE_ovalR; delete LE_ovalr;
    delete LE_starTier; delete LE_starR; delete LE_starr; delete LE_HexR;
    delete Enter;
    delete ui;
}

void MainWindow::on_radioButton_clicked(bool checked)
{
    if(checked) {
        scn->clear();
        sh = new triangle();
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        ui->rotateSlider->setValue(0);
        currentFigure = "Triangle: ";
        ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));
    }
}


void MainWindow::on_radioButton_2_clicked(bool checked)
{
    if(checked) {
        scn->clear();
        sh = new Circle();
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        ui->rotateSlider->setValue(0);
        currentFigure = "circle";
      ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));

    }
}

void MainWindow::on_radioButton_3_clicked(bool checked)
{
    if(checked) {
        scn->clear();
        sh = new Rhomb();
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        ui->rotateSlider->setValue(0);
        currentFigure = "Romb: ";
        ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));


    }
}


void MainWindow::on_radioButton_4_clicked(bool checked)
{
    if(checked) {
        scn->clear();
        sh = new Square();
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        ui->rotateSlider->setValue(0);
        currentFigure = "Square: ";
         ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));


    }
}

void MainWindow::on_radioButton_5_clicked(bool checked)
{
    if(checked) {
        scn->clear();
        sh = new Rectangle();
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        ui->rotateSlider->setValue(0);
        currentFigure = "Rectangle: ";
        ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));
    }
}


void MainWindow::on_radioButton_6_clicked(bool checked)
{
    if(checked) {
        scn->clear();
        sh = new Star();
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        ui->rotateSlider->setValue(0);
        currentFigure = "Star: ";
        ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));
    }
}


void MainWindow::on_radioButton_7_clicked(bool checked)
{
    if(checked) {
        scn->clear();
        sh = new Hexagon();
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        ui->rotateSlider->setValue(0);
        currentFigure = "Hexagon: ";
        ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));


    }
}


void MainWindow::on_radioButton_8_clicked(bool checked)
{
    if(checked) {
        scn->clear();
        sh = new Oval();
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        ui->rotateSlider->setValue(0);
        currentFigure = "Ellipse: ";
         ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));

    }
}

void MainWindow::on_btnRect_clicked()
{
    if (currentFigure == "Rectangle: ") {
        rectDlg->setModal(true);
        rectDlg->resize(160, 120);

        InputWidth->move(5, 5);
        InputHeight->move(5, 55);
        LE_Width->resize(65, 35);
        LE_Height->resize(65, 35);
        LE_Width->move(75, 5);
        LE_Height->move(75, 45);

        Enter = new QPushButton("Ввод ", rectDlg); Enter->adjustSize();
        Enter->move(50,90);
        connect(Enter, SIGNAL(clicked()), this, SLOT(createRect()));
        rectDlg->show();


    } else if (currentFigure == "Triangle: ") {

        triangDlg->setModal(true);
        triangDlg->resize(300, 180);


        InputX1->move(40, 5);
        InputX2->move(40, 50);
        InputX3->move(40, 95);
        InputY1->move(180, 5);
        InputY2->move(180, 50);
        InputY3->move(180,95);

        LE_X1->resize(50, 30);
        LE_X2->resize(50, 30);
        LE_X3->resize(50, 30);
        LE_Y1->resize(50, 30);
        LE_Y2->resize(50, 30);
        LE_Y3->resize(50, 30);

        LE_X1->move(70, 5);
        LE_X2->move(70, 50);
        LE_X3->move(70, 95);
        LE_Y1->move(200, 5);
        LE_Y2->move(200, 50);
        LE_Y3->move(200, 95);

        Enter = new QPushButton("Ввод ", triangDlg); Enter->adjustSize();
        Enter->move(120, 140);
        connect(Enter, SIGNAL(clicked()), this, SLOT(createTriang()));
        triangDlg->show();
    } else if (currentFigure == "Circle: ") {
        circleDlg->setModal(true);
        circleDlg->resize(300, 300);

        InputR->move(100, 130);

        LE_R->resize(60, 30);

        LE_R->move(170, 130);

        Enter = new QPushButton("Ввод ", circleDlg); Enter->adjustSize();
        Enter->move(150, 200);
        connect(Enter, SIGNAL(clicked()), this, SLOT(createCircle()));
        circleDlg->show();
    } else if (currentFigure == "Square: ") {
        squareDlg->setModal(true);
        squareDlg->resize(300, 300);

        InputA->move(100, 130);

        LE_A->resize(60, 30);

        LE_A->move(170, 130);

        Enter = new QPushButton("Ввод ", squareDlg); Enter->adjustSize();
        Enter->move(150, 200);
        connect(Enter, SIGNAL(clicked()), this, SLOT(createSquare()));
        squareDlg->show();

    } else if (currentFigure == "Romb: ") {
        rhombDlg->setModal(true);
        rhombDlg->resize(300, 300);

        Inputr->move(100, 130);

        LE_r->resize(60, 30);

        LE_r->move(170, 130);

        Enter = new QPushButton("Ввод ", rhombDlg); Enter->adjustSize();
        Enter->move(150, 200);
        connect(Enter, SIGNAL(clicked()), this, SLOT(createRhomb()));
        rhombDlg->show();
    } else if (currentFigure == "Ellipse: ") {
        ovalDlg->setModal(true);
        ovalDlg->resize(300, 300);
        InputOvalR->move(100, 100);
        InputOvalr->move(100, 150);
        LE_ovalR->resize(60, 30);
        LE_ovalr->resize(60, 30);
        LE_ovalR->move(170, 100);
        LE_ovalr->move(170, 140);

        Enter = new QPushButton("Ввод ", ovalDlg); Enter->adjustSize();
        Enter->move(150, 200);
        connect(Enter, SIGNAL(clicked()), this, SLOT(createOval()));
        ovalDlg->show();
    } else if (currentFigure == "Star(*5): ") {
        starDlg->setModal(true);
        starDlg->resize(300, 400);

        InputStarTier->move(100, 100);
        InputStarR->move(100, 150);
        InputStarr->move(100, 200);
        LE_starTier->resize(60, 30);
        LE_starR->resize(60, 30);
        LE_starr->resize(60,30);

        LE_starTier->move(170, 100);
        LE_starR->move(170, 150);
        LE_starr->move(170, 200);

        Enter = new QPushButton("Ввод ", starDlg); Enter->adjustSize();
        Enter->move(150, 300);
        connect(Enter, SIGNAL(clicked()), this, SLOT(createStar()));
        starDlg->show();
    } else if (currentFigure == "Hexagon: ") {
        hexDlg->setModal(true);
        hexDlg->resize(300, 300);

        InputHexR->move(100, 130);

        LE_HexR->resize(60, 30);

        LE_HexR->move(170, 130);

        Enter = new QPushButton("Ввод ", hexDlg); Enter->adjustSize();
        Enter->move(150, 200);
        connect(Enter, SIGNAL(clicked()), this, SLOT(createHex()));
        hexDlg->show();
    }
}

void MainWindow::createRect()
{
    QString strHeight = LE_Height->text();
    QString strWidth = LE_Width->text();

    QRegularExpression reg("^\\d+\\d?\\d?$");
    QRegularExpressionMatch matchHeight = reg.match(strHeight);
    QRegularExpressionMatch matchWidth = reg.match(strWidth);

    if (!matchHeight.hasMatch() || !matchWidth.hasMatch())
        QMessageBox::critical(rectDlg,  "", "Некорректный ввод!");
    else {
        rectDlg->close();
        double width = strWidth.toDouble();
        double height = strHeight.toDouble();
        scn->clear();
        sh = new Rectangle(width, height);
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        scn->update();
        ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));


    }
}

void MainWindow::createTriang()
{
    QString strX1 = LE_X1->text();
    QString strX2 = LE_X2->text();
    QString strX3 = LE_X3->text();

    QString strY1 = LE_Y1->text();
    QString strY2 = LE_Y2->text();
    QString strY3 = LE_Y3->text();


    QRegularExpression reg("^\\d+\\d?\\d?$");
    QRegularExpressionMatch matchX1 = reg.match(strX1);
    QRegularExpressionMatch matchX2 = reg.match(strX2);
    QRegularExpressionMatch matchX3 = reg.match(strX3);
    QRegularExpressionMatch matchY1 = reg.match(strY1);
    QRegularExpressionMatch matchY2 = reg.match(strY2);
    QRegularExpressionMatch matchY3 = reg.match(strY3);

    if (!matchX1.hasMatch() || !matchX2.hasMatch() || !matchX3.hasMatch() ||
            !matchY1.hasMatch() || !matchY2.hasMatch() || !matchY3.hasMatch() )
        QMessageBox::critical(triangDlg, "", "Некорректный ввод!");
    else {
        triangDlg->close();
        double x1 = strX1.toDouble();
        double x2 = strX2.toDouble();
        double x3 = strX3.toDouble();
        double y1 = strY1.toDouble();
        double y2 = strY2.toDouble();
        double y3 = strY3.toDouble();
        scn->clear();
        sh = new triangle(x1, x2, x3, y1, y2, y3);
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        scn->update();
      ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));

    }
}

void MainWindow::createCircle()
{

    QString strR = LE_R->text();

    QRegularExpression reg("^\\d+\\d?\\d?$");
    QRegularExpressionMatch matchR = reg.match(strR);

    if (!matchR.hasMatch())
        QMessageBox::critical(circleDlg,  "", "Некорректный ввод!");
    else {
        circleDlg->close();
        double radius = strR.toDouble();
        scn->clear();
        sh = new Circle(radius);
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        scn->update();
        ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));


    }
}

void MainWindow::createSquare()
{
    QString strA = LE_A->text();

    QRegularExpression reg("^\\d+\\d?\\d?$");
    QRegularExpressionMatch matchA = reg.match(strA);

    if (!matchA.hasMatch())
        QMessageBox::critical(squareDlg,  "", "Некорректный ввод!");
    else {
        squareDlg->close();
        double a = strA.toDouble();
        scn->clear();
        sh = new Square(a);
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        scn->update();
        ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));


    }
}

void MainWindow::createRhomb()
{
    QString strr = LE_r->text();

    QRegularExpression reg("^\\d+\\d?\\d?$");
    QRegularExpressionMatch matchr = reg.match(strr);

    if (!matchr.hasMatch())
        QMessageBox::critical(rhombDlg,  "", "Некорректный ввод!");
    else {
        rhombDlg->close();
        double r = strr.toDouble();
        scn->clear();
        sh = new Rhomb(r);
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        scn->update();
       ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));


    }
}

void MainWindow::createOval()
{
    QString strOvalR = LE_ovalR->text();
    QString strOvalr = LE_ovalr->text();

    QRegularExpression reg("^\\d+\\d?\\d?$");
    QRegularExpressionMatch matchOvalR = reg.match(strOvalR);
    QRegularExpressionMatch matchOvalr = reg.match(strOvalr);

    if (!matchOvalR.hasMatch() || !matchOvalr.hasMatch())
        QMessageBox::critical(ovalDlg,  "", "Некорректный ввод!");
    else {
        ovalDlg->close();
        double R = strOvalR.toDouble();
        double r = strOvalr.toDouble();
        scn->clear();
        sh = new Oval(R, r);
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        scn->update();
       ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));


    }
}

void MainWindow::createStar()
{
    QString strStarTier = LE_starTier->text();
    QString strStarR = LE_starR->text();
    QString strStarr = LE_starr->text();

    QRegularExpression reg("^\\d+\\d?\\d?$");
    QRegularExpressionMatch matchStarTier = reg.match(strStarTier);
    QRegularExpressionMatch matchStarR = reg.match(strStarR);
    QRegularExpressionMatch matchStarr = reg.match(strStarr);

    if (!matchStarR.hasMatch() || !matchStarr.hasMatch() || !matchStarTier.hasMatch()) {

        QMessageBox::critical(starDlg,  "", "Некорректный ввод!");
    }
    else {
        starDlg->close();
        int tier = strStarTier.toInt();
        double R = strStarR.toDouble();
        double r = strStarr.toDouble();
        scn->clear();
        sh = new Star(tier, R, r);
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        scn->update();
        ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));


    }
}

void MainWindow::createHex()
{
    QString strHexR = LE_HexR->text();

    QRegularExpression reg("^\\d+\\d?\\d?$");
    QRegularExpressionMatch matchHexR = reg.match(strHexR);

    if (!matchHexR.hasMatch())
        QMessageBox::critical(hexDlg, "", "Некорректный ввод!");
    else {
        hexDlg->close();
        double r = strHexR.toDouble();
        scn->clear();
        sh = new Hexagon(r);
        scn->addItem(sh);
        ui->horizontalSlider->setValue(100);
        scn->update();
        ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S) + "  Периметр: "+QString::number(sh->m_P));


    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    sh->m_scale = (value / 100.0);
    scn->update();

 ui->statusbar->showMessage(" Площадь: "+QString::number(sh->m_S * value / 100) + "  Периметр: "+QString::number(sh->m_P * value / 100));

}

void MainWindow::on_rotateSlider_valueChanged(int value)
{
    sh->m_angle = value;
    scn->update();
}




void MainWindow::on_leftBtn_clicked()
{
    sh->m_center_x -= 30;
    sh->sc_center_x -=30;
    scn->update();
}


void MainWindow::on_bottomBtn_clicked()
{
    sh->m_center_y += 30;
    sh->sc_center_y +=30;
    scn->update();
}


void MainWindow::on_rightBtn_clicked()
{
    sh->m_center_x += 30;
    sh->sc_center_x +=30;
    scn->update();
}


void MainWindow::on_upperBtn_clicked()
{
    sh->m_center_y -= 30;
    sh->sc_center_y -=30;
    scn->update();
}
void MainWindow::on_canvaButton_clicked()
{
    QDialog *canvasWnd = new QDialog(this);
    canvasWnd->setModal(true);

    canvasWnd->resize(1000, 800);

    canva *canvas = new canva(canvasWnd);
    canvas->resize(1000, 800);
    canvas->SetDraw(true);
    canvasWnd->show();
}




