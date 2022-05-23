#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <regex>
#include <QDebug>
#include <stack>
#include <QLibrary>
#include <Windows.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1320,717);

    ui->comboBox->addItem(QString("1. Количество переменных каждого типа, их название, значение."));
    ui->comboBox->addItem(QString("2. Количество инициализированных классов, структур, массивов."));
    ui->comboBox->addItem(QString("3. Список прототипов всех функций."));
    ui->comboBox->addItem(QString("4. Координата каждого изменения любой переменной, в т.ч. массива."));
    ui->comboBox->addItem(QString("5. Количество локальных переменных, их координаты."));
    ui->comboBox->addItem(QString("6. Количество перегруженных функций, их координаты."));
    ui->comboBox->addItem(QString("7. Глубина каждого ветвления."));
    ui->comboBox->addItem(QString("8. Логические ошибки времени компиляции."));

    code = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonFile_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"Open","","Cpp file (*.cpp)");
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this,"Error","File is not opened");
        return;
    }
    QByteArray t = file.readAll();
    file.close();
    code = QString(t);
    ui->textEdit->setText(code);
}

void MainWindow::on_pushButtonLine_clicked()
{
    if(flag)
    {
        code = ui->textEdit->toPlainText();
    }
    flag = false;
}

void MainWindow::on_textEdit_textChanged()
{
    flag = true;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(code != "" && code.size() >= 10)
    {
        ui->textBrowser->clear();
        switch (index)
        {
        case 0:getVarsData(); showVarsData(); break;
        case 1: showObjsAndArsData(getObjsAndArsData()); break;
        case 2: getFunctionsData(); showFunctionsData(); break;
        case 3: coordinatesOfChanges(); return; break;
        case 4: localsCoordinates();break;
        case 5: overloadsCoordinates();break;
        case 6: depthOfBranches();break;
        case 7: logicalErrors();break;
        default: break;
        }
        ui->textBrowser->setText(spare);
    }
}

void MainWindow::getVarsData()
{
    variables_names.clear();
    variables_data.clear();

    std::regex regular("((size_t|int|double|float|char)\\s*[\\*]*)\\s*([\\w]+)\\s*(=\\s*[\\w+ ]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?;");
    std::smatch result;
    temp = code.toStdString();

    while(std::regex_search(temp, result, regular))
    {
        variables_data.push_back(result.str());
        variables_names.push_back(result[3]);
        temp = result.suffix();
    }
}

void MainWindow::showVarsData()
{
    size_t int_count = 0;
    size_t char_count = 0;
    size_t double_count = 0;
    size_t float_count = 0;
    size_t size_t_count = 0;
    spare = "";
    for(auto& it : variables_data)
    {
        if(it.find("int") != std::string::npos)
        { ++int_count; }
        if(it.find("float") != std::string::npos)
        { ++float_count; }
        if(it.find("double") != std::string::npos)
        { ++double_count; }
        if(it.find("char") != std::string::npos)
        { ++char_count; }
        if(it.find("size_t") != std::string::npos)
        { ++size_t_count; }

        spare += QString::fromStdString(it) + "\n";
    }
    spare += "\nКоличество:\nint : " + QString::number(int_count) + "\nfloat : " + QString::number(float_count)
            + "\ndouble : " + QString::number(double_count) + "\nchar : " + QString::number(char_count)
            + "\nsize_t : " + QString::number(size_t_count);
}

int* MainWindow::getObjsAndArsData()
{
    classes_names.clear();
    arrays_names.clear();
    objects_names.clear();

    temp = code.toStdString();
    std::regex classes_regex("(class|struct)\\s*(\\w+)\\s*\\{");
    std::smatch result;
    while(std::regex_search(temp, result, classes_regex))
    {
        classes_names.push_back(result[2]);
        temp = result.suffix();
    }

    temp = code.toStdString();

    size_t class_count = 0;

    //erase constructors and destructors
    //for not including it to class_count
    size_t size = classes_names.size();
    for(size_t i = 0; i < size; ++i)
    {
        int pos = temp.find(classes_names[i]);
        //find closed bracket using stack
        std::stack<char> brackets_stack;
        brackets_stack.push('{');
        size_t first_bracket = temp.find('{', pos);
        size_t last_bracket, counter = first_bracket + 1;
        while(!brackets_stack.empty() && counter < temp.size())
        {
            if(temp[counter] == '{')
            {
                brackets_stack.push('{');
            }
            if(temp[counter] == '}')
            {
                brackets_stack.pop();
            }
            ++counter;
        }
        last_bracket = counter - 1;
        try
        {
            if(counter != temp.size())
            {
                temp.erase(first_bracket, last_bracket - first_bracket + 1); //erase body of class
            }
        } catch (...)
        {
            qDebug() << "Exception in erase. function : \"classes_structs_arrs\"";
        }

    }

    size_t pos;
    for(size_t i = 0; i < classes_names.size(); ++i)
    {
        pos = temp.find(classes_names[i]);
        while(pos != std::string::npos)
        {
            if(pos > temp.find("int main()")) ++class_count;
            temp.erase(pos, classes_names[i].size());
            pos = temp.find(classes_names[i]);
        }
    }

    std::string init_object_regex_str("\\s*[\\*]*\\s*([\\w]+)\\s*(=\\s*[\\w+ ]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?;");
    for(size_t i = 0; i < classes_names.size(); ++i)
    {
        temp = code.toStdString();
        std::regex init_obj_regex("\\s*" + classes_names[i] + init_object_regex_str);
        while(std::regex_search(temp, result, init_obj_regex))
        {
            objects_names.push_back(std::pair<std::string, std::string>(classes_names[i], result[1]));
            temp = result.suffix();
        }
    }

    std::regex arrays_decl_regex("\\s*\\w+\\s+(\\w+)\\s*((\\[[\\w]*\\])+)\\s*=?\\s*(\\{[^;]*\\})?\\s*;");

    temp = code.toStdString();

    while (std::regex_search(temp, result, arrays_decl_regex))
    {
        arrays_names.push_back(result[1]);
        temp = result.suffix();
    }
    size_t array_count = 0;

    temp = code.toStdString();

    for(size_t i = 0; i < arrays_names.size(); ++i)
    {
        if(temp.find(arrays_names[i]) != std::string::npos)
        {
            ++array_count;
            temp.erase(temp.find(arrays_names[i]), arrays_names[i].size());
        }
    }
    int* nums = new int[2];
    nums[0] = class_count;
    nums[1] = array_count;
    return nums;
}

void MainWindow::showObjsAndArsData(int* nums)
{
    spare = "";

    spare += "Объекты : " + QString::number(nums[0]) + "\n";
    spare += "Массивы : " + QString::number(nums[1]) + "\n";

    delete[] nums;
}

void MainWindow::getFunctionsData()
{
    std::regex functions_regex("\\s*((\\w+)\\s+(\\w+|\\w+([:]{2}\\w+)?)\\s*\\([\\w, =*\\[\\]&]*\\))\\s*(\\{([^\\}]*|\\{[\\w ;\\.\\(\\)]*\\})\\}|;)");

    functions_data.clear();
    functions_names.clear();
    functions_positions.clear();

    QStringList list = code.split("\n");
    std::vector<std::string> str_array;
    for(int i = 0; i < list.size(); ++i)
    {
        str_array.push_back(list[i].toStdString());
    }

    std::smatch res;

    std::string str = code.toStdString();

    std::vector<bool> visited(str_array.size(), false);
    while (std::regex_search(str, res, functions_regex))
    {
        if(res[3] != "if")
        {
            for(size_t i = 0; i < str_array.size(); ++i)
            {
                if(str_array[i].find(res[1]) != std::string::npos && !visited[i])
                {
                    functions_positions.push_back(i);
                    visited[i] = true;
                    break;
                }
            }
            functions_data.push_back(res[1]);
            functions_names.push_back(res[3]);
        }
        str = res.suffix();
    }
}

void MainWindow::showFunctionsData()
{
    spare = "";

    getFunctionsData();
    spare = "Прототипы функций :\n";
    for(const auto& it : functions_data)
    {
        spare += QString::fromStdString(it) + ";\n";
    }
}

void MainWindow::coordinatesOfChanges()
{
    std::regex reg("[\\};]\\s*(([\\*]*\\s*)?\\w+(\\[\\w+\\])?\\s*?(([+|-|^|*|\\/|&|\\|]?=)|\\++|--))");

    std::smatch res;

    std::string str = ui->textEdit->toPlainText().toStdString();

    while(std::regex_search(str, res, reg))
    {
        str = res.suffix();

        ui->textBrowser->append(QString::number(ui->textEdit->toPlainText().mid(0, (ui->textEdit->toPlainText().size() - str.size())).count('\n') + 1));
    }
}

void MainWindow::localsCoordinates()
{
    spare = "";

    getObjsAndArsData();
    QStringList str = code.split('\n');
    std::vector<std::string> rows;
    for(int i = 0; i < str.size(); ++i)
    {
        rows.push_back(str[i].toStdString());
    }
    int balance = 0;
    std::vector<int> position;
    std::regex variables_init_regex("((size_t|int|double|float|char)\\s*[\\*]*)\\s*([\\w]+)\\s*(=\\s*[\\w+ ]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?;");
    for(size_t i = 0; i < rows.size(); ++i){
        for(size_t j = 0; j < rows[i].size(); ++j)
        {
            if(rows[i][j] == '{')
            {
                ++balance;
            }
            if(rows[i][j] == '}')
            {
                --balance;
            }
        }
        if(std::regex_search(rows[i], variables_init_regex))
        {
            if(balance != 0)
            {
                position.push_back(i);
            }
        }
    }
    std::string class_init_regex_str("\\s*(=\\s*[\\w+ ]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?;");
    for(size_t i = 0; i < rows.size(); ++i){
        for(size_t j = 0; j < rows[i].size(); ++j)
        {
            if(rows[i][j] == '{')
            {
                ++balance;
            }
            if(rows[i][j] == '}')
            {
                --balance;
            }
        }
        if(balance != 0){
            for(size_t k = 0; k < objects_names.size(); ++k)
            {
                std::regex obj_regex(objects_names[k].first + "\\s*" + objects_names[k].second + class_init_regex_str);
                if(std::regex_search(rows[i], obj_regex)){
                    position.push_back(i);
                }
            }
        }

    }

    spare = "Количество локальных переменных : " + QString::number(position.size()) + "\n";
    spare += "Строки, в кототых они содержатся : \n";
    for(size_t i = 0; i < position.size(); ++i)
    {
        spare += QString::number(position[i]) + "\n";
    }
}

void MainWindow::overloadsCoordinates()
{
    spare = "";

    getFunctionsData();
    QStringList str = code.split('\n');
    std::vector<std::string> rows;
    for(int i = 0; i < str.size(); ++i)
    {
        rows.push_back(str[i].toStdString());
    }

    int count_of_overload_funcs = 0;
    std::vector<int> positions;
    std::vector<bool> visited(functions_names.size(), false);
    for(size_t i = 0; i < functions_names.size(); ++i)
    {
        for(size_t j = i + 1; j < functions_names.size(); ++j)
        {
            if(functions_names[i] == functions_names[j] && !visited[i] && !visited[j])
            {
                count_of_overload_funcs += 2;
                visited[i] = visited[j] = true;
                positions.push_back(functions_positions[i]);
                positions.push_back(functions_positions[j]);
            }
        }
    }
    spare += "rows:\n";
    for(size_t i = 0; i < positions.size(); ++i)
    {
        spare += QString::number(positions[i]) + "\n";
    }
    spare = "Количество перегруженных функций :" + QString::number(count_of_overload_funcs) + "\n";
}

void MainWindow::depthOfBranches()
{
    spare = "";

    temp = code.toStdString();
    std::vector<int> depth;
    int amount = 0;

    std::stack<char> pos;
    for(size_t i = 0; i < temp.size() - 5; ++i)
    {
        if(temp[i] != 'e' && temp[i + 1] != 'l' && temp[i + 2] != 's' && temp[i + 3] != 'e'
                && temp[i + 4] == 'i' && temp[i + 5] == 'f')
        {
            ++amount;
            pos.push('{');
        }
        if(temp[i] == 'e' && temp[i + 1] == 'l' && temp[i + 2] == 's' && temp[i + 3] == 'e'
                && temp[i + 4] == 'i' && temp[i + 5] == 'f')
        {
            pos.push('{');
        }
        if(!pos.empty() && temp[i] == '}')
        {
            depth.push_back(amount);
            --amount;
            pos.pop();
        }
    }

    for(size_t i = 0; i < depth.size() - depth.size()/3; ++i)
    {
        spare += QString::number(depth[i]) + "\n";
    }
}

void MainWindow::logicalErrors()
{
    spare = "";

    QStringList list = code.split('\n');
    std::vector<std::string> code_vector;
    for(int i = 0; i < list.size(); ++i)
    {
        code_vector.push_back(list[i].toStdString());
    }

    std::regex regular_while_false("\\s*while\\(\\s*false\\s*\\)");
    for(size_t i = 0; i < code_vector.size(); ++i)
    {
        if(std::regex_search(code_vector[i], regular_while_false))
        {
            spare += "while(false) {...} в " + QString::number(i) + "-ой строке\n";
        }
    }

    std::regex regular_while_true("\\s*while\\(\\s*true\\s*\\)\\s*\\{\\s*\\}");
    for(size_t i = 0; i < code_vector.size(); ++i)
    {
        if(std::regex_search(code_vector[i], regular_while_true))
        {
            spare += "while(true) {*пустота*} в " + QString::number(i) + "-ой строке\n";
        }
    }

    std::regex regular_if_true("if\\(\\s*true\\s*\\)");
    for(size_t i = 0; i < code_vector.size(); ++i)
    {
        if(std::regex_search(code_vector[i], regular_if_true))
        {
            spare += "if(true) {...} в " + QString::number(i) + "-ой строке\n";
        }
    }

    std::regex regular_if_false("if\\(\\s*false\\s*\\)");
    for(size_t i = 0; i < code_vector.size(); ++i)
    {
        if(std::regex_search(code_vector[i], regular_if_false))
        {
           spare += "if(false) {...} в " + QString::number(i) + "-ой строке\n";
        }
    }

    std::regex regular_empty_if("if\\(\\s*\\)");
    for(size_t i = 0; i < code_vector.size(); ++i)
    {
        if(std::regex_search(code_vector[i], regular_empty_if))
        {
            spare += "if() {...} в " + QString::number(i) + "-ой строке\n";
        }
    }
}

