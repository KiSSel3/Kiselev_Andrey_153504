#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(WIDTH, HEIGHT);

    table = new QTableWidget(this);

    table->resize(WIDTH, HEIGHT);

    calculate_btn = new QPushButton(this);

    QFont font;
    font.setPixelSize(15);
    calculate_btn->setFont(font);

    calculate_btn->setText("Вычислить");

    calculate_btn->move(WIDTH - 150, HEIGHT - 55);

    connect(calculate_btn, SIGNAL(clicked()), this, SLOT(CalculateExpr()));

    table->setRowCount(ROWS);
    table->setColumnCount(7);

    for (short i = 0; i < 7; ++i)
        table->setColumnWidth(i, 1070/7);

    table->setHorizontalHeaderLabels({"Выражение", "a", "b", "c", "d", "e", "Результат"});

    SetExpressions();


    for (short ROW = 0; ROW < 15; ++ROW) {

        std::string infix = table->item(ROW, 0)->text().toStdString();

        double a = table->item(ROW, 1)->text().toDouble();

        double b = table->item(ROW, 2)->text().toDouble();

        double c = table->item(ROW, 3)->text().toDouble();

        double d = table->item(ROW, 4)->text().toDouble();

        double e = table->item(ROW, 5)->text().toDouble();

        Expression polish(infix, a, b, c, d, e);

        CreateItem(polish.result(), ROW, 6);

    }

}

MainWindow::~MainWindow()
{
}

void MainWindow::CalculateExpr()
{

    std::string infix;
    double a, b, c, d, e;

    QTableWidgetItem *itm = table->item(ROWS - 1, 0);

    if (!itm)
        return;

    infix = table->item(ROWS - 1, 0)->text().toStdString();

    itm = table->item(ROWS - 1, 1);

    if (!itm)
       a = 0;
    else
        a = table->item(ROWS - 1, 1)->text().toDouble();

    itm = table->item(ROWS - 1, 2);

    if (!itm)
       b = 0;
    else
        b = table->item(ROWS - 1, 2)->text().toDouble();

    itm = table->item(ROWS - 1, 3);

    if (!itm)
        c = 0;
    else
        c = table->item(ROWS - 1, 3)->text().toDouble();

    itm = table->item(ROWS - 1, 4);

    if (!itm)
        d = 0;
    else
        d = table->item(ROWS - 1, 4)->text().toDouble();

    itm = table->item(ROWS - 1, 5);

    if (!itm)
        e = 0;
    else

    e = table->item(ROWS - 1, 5)->text().toDouble();

    Expression expr(infix, a, b, c, d, e);
    CreateItem(expr.result(), 15, 6);

}

void MainWindow::SetExpressions() {

    CreateItem("a/(b-c)*(d+e)", 0, 0);   CreateItem("8.6", 0, 1);   CreateItem("2.4", 0, 2);   CreateItem("5.1", 0, 3);   CreateItem("0.3", 0, 4);   CreateItem("7.9", 0, 5);

    CreateItem("(a+b)*(c-d)/e", 1, 0);   CreateItem("7.4", 1, 1);   CreateItem("3.6", 1, 2);   CreateItem("2.8", 1, 3);   CreateItem("9.5", 1, 4);   CreateItem("0.9", 1, 5);

    CreateItem("a-(b+c*d)/e", 2, 0);   CreateItem("3.1", 2, 1);   CreateItem("5.4", 2, 2);   CreateItem("0.2", 2, 3);   CreateItem("9.6", 2, 4);   CreateItem("7.8", 2, 5);

    CreateItem("a/b-((c+d)*e)", 3, 0);   CreateItem("1.2", 3, 1);   CreateItem("0.7", 3, 2);   CreateItem("9.3", 3, 3);   CreateItem("6.5", 3, 4);   CreateItem("8.4", 3, 5);

    CreateItem("a*(b-c+d)/e", 4, 0);   CreateItem("9.7", 4, 1);   CreateItem("8.2", 4, 2);   CreateItem("3.6", 4, 3);   CreateItem("4.1", 4, 4);   CreateItem("0.5", 4, 5);

    CreateItem("(a+b)*(c-d)/e", 5, 0);   CreateItem("0.8", 5, 1);   CreateItem("4.1", 5, 2);   CreateItem("7.9", 5, 3);   CreateItem("6.2", 5, 4);   CreateItem("3.5", 5, 5);

    CreateItem("a*(b-c)/(d+e)", 6, 0);   CreateItem("1.6", 6, 1);   CreateItem("4.9", 6, 2);   CreateItem("5.7", 6, 3);   CreateItem("0.8", 6, 4);   CreateItem("2.3", 6, 5);

    CreateItem("a/(b*(c+d))-e", 7, 0);   CreateItem("8.5", 7, 1);   CreateItem("0.3", 7, 2);   CreateItem("2.4", 7, 3);   CreateItem("7.9", 7, 4);   CreateItem("1.6", 7, 5);

    CreateItem("(a+(b/c-d))*e", 8, 0);   CreateItem("5.6", 8, 1);   CreateItem("7.4", 8, 2);   CreateItem("8.9", 8, 3);   CreateItem("3.1", 8, 4);   CreateItem("0.2", 8, 5);

    CreateItem("a*(b+c)/(d-e)", 9, 0);   CreateItem("0.4", 9, 1);   CreateItem("2.3", 9, 2);   CreateItem("6.7", 9, 3);   CreateItem("5.8", 9, 4);   CreateItem("9.1", 9, 5);

    CreateItem("a-(b/c*(d+e))", 10, 0);   CreateItem("5.6", 10, 1);   CreateItem("3.2", 10, 2);   CreateItem("0.9", 10, 3);   CreateItem("1.7", 10, 4);   CreateItem("4.8", 10, 5);

    CreateItem("(a-b)/(c+d)", 11, 0);   CreateItem("0.3", 11, 1);   CreateItem("6.7", 11, 2);   CreateItem("8.4", 11, 3);   CreateItem("9.5", 11, 4);   CreateItem("1.2", 11, 5);

    CreateItem("a/(b+c-d*e)", 12, 0);   CreateItem("7.6", 12, 1);   CreateItem("4.8", 12, 2);   CreateItem("3.5", 12, 3);   CreateItem("9.1", 12, 4);   CreateItem("0.2", 12, 5);

    CreateItem("a*(b-c)/(d+e)", 13, 0);   CreateItem("0.5", 13, 1);   CreateItem("6.1", 13, 2);   CreateItem("8.9", 13, 3);   CreateItem("2.4", 13, 4);   CreateItem("7.3", 13, 5);

    CreateItem("(a+b*c)/(d-e)", 14, 0);   CreateItem("9.1", 14, 1);   CreateItem("0.6", 14, 2);   CreateItem("2.4", 14, 3);   CreateItem("3.7", 14, 4);   CreateItem("8.5", 14, 5);
}
