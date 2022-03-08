#include "widget.h"
#include "./ui_widget.h"
#include <QButtonGroup>
#include <QDate>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("臭骚批学生信息管理系统");

    QButtonGroup* genderGroup = new QButtonGroup();
    genderGroup->addButton(ui->man);
    genderGroup->addButton(ui->woman);

    QButtonGroup* graduateGroup = new QButtonGroup();
    graduateGroup->addButton(ui->postExam);
    graduateGroup->addButton(ui->findJob);

    QButtonGroup* jobGroup = new QButtonGroup();
    jobGroup->addButton(ui->cppPro);
    jobGroup->addButton(ui->javaPro);
    jobGroup->addButton(ui->webPro);
    jobGroup->setExclusive(false);

    ui->infoTable->setColumnCount(7);
    ui->infoTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->infoTable->setHorizontalHeaderLabels(QStringList() << "学号" << "姓名" << "性别"
                    << "入学年份"  << "专业班级" << "毕业情况" << "就业意向");
    ui->infoTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->infoTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->infoTable->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(ui->infoTable, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(on_itemDoubleClickedSlot()));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addButtom_clicked()
{
    int rowCount = ui->infoTable->rowCount();
    ui->infoTable->insertRow(rowCount);

    ui->infoTable->setItem(rowCount, 0, new QTableWidgetItem(ui->stuID->text()));
    ui->infoTable->setItem(rowCount, 1, new QTableWidgetItem(ui->stuName->text()));
    QString genderStr = ui->man->isChecked() ? ui->man->text() : ui->woman->text();
    ui->infoTable->setItem(rowCount, 2, new QTableWidgetItem(genderStr));
    ui->infoTable->setItem(rowCount, 3, new QTableWidgetItem(ui->timeIntoCollege->date().toString("yyyy-MM-dd")));
    ui->infoTable->setItem(rowCount, 4, new QTableWidgetItem(ui->majority->currentText()));

    QString graduateInfo;
    if(ui->postExam->isChecked()) {
        graduateInfo += ui->postExam->text();
    }
    if(ui->findJob->isChecked()) {
        graduateInfo += ui->findJob->text();
    }
    ui->infoTable->setItem(rowCount, 5, new QTableWidgetItem(graduateInfo));

    QString jobStr;
    if(ui->cppPro->isChecked()) {
        jobStr += ui->cppPro->text() + "/";
    }
    if(ui->javaPro->isChecked()) {
        jobStr += ui->javaPro->text() + "/";
    }
    if(ui->webPro->isChecked()) {
        jobStr += ui->webPro->text() + "/";
    }
    ui->infoTable->setItem(rowCount, 6, new QTableWidgetItem(jobStr));

}


void Widget::on_updateButton_clicked()
{
    int sel = ui->infoTable->currentRow();
    if(sel < 0) {
        return;
    }


    ui->infoTable->setItem(sel, 0, new QTableWidgetItem(ui->stuID->text()));
    ui->infoTable->setItem(sel, 1, new QTableWidgetItem(ui->stuName->text()));
    QString genderStr = ui->man->isChecked() ? ui->man->text() : ui->woman->text();
    ui->infoTable->setItem(sel, 2, new QTableWidgetItem(genderStr));
    ui->infoTable->setItem(sel, 3, new QTableWidgetItem(ui->timeIntoCollege->date().toString("yyyy-MM-dd")));
    ui->infoTable->setItem(sel, 4, new QTableWidgetItem(ui->majority->currentText()));

    QString graduateInfo;
    if(ui->postExam->isChecked()) {
        graduateInfo += ui->postExam->text() + "/";
    }
    if(ui->findJob->isChecked()) {
        graduateInfo += ui->findJob->text() + "/";
    }
    ui->infoTable->setItem(sel, 5, new QTableWidgetItem(graduateInfo));

    QString jobStr;
    if(ui->cppPro->isChecked()) {
        jobStr += ui->cppPro->text() + "/";
    }
    if(ui->javaPro->isChecked()) {
        jobStr += ui->javaPro->text() + "/";
    }
    if(ui->webPro->isChecked()) {
        jobStr += ui->webPro->text() + "/";
    }
    ui->infoTable->setItem(sel, 6, new QTableWidgetItem(jobStr));
}


void Widget::on_deleteButton_clicked()
{
    int sel = ui->infoTable->currentRow();
    if(sel < 0) {
        return;
    }
    ui->infoTable->removeRow(sel);
}

void Widget::on_itemDoubleClickedSlot() {
    int sel = ui->infoTable->currentRow();
    if(sel < 0) {
        return;
    }
    ui->stuID->setText(ui->infoTable->item(sel, 0)->text());
    ui->stuName->setText(ui->infoTable->item(sel, 1)->text());
    if(ui->infoTable->item(sel, 2)->text() == ui->man->text()) {
        ui->man->setChecked(true);
    } else if(ui->infoTable->item(sel, 2)->text() == ui->woman->text()) {
        ui->woman->setChecked(true);
    }

    QDate schoolDate = QDate::fromString(ui->infoTable->item(sel, 3)->text(), "yyyy-MM-dd");
    ui->timeIntoCollege->setDate(schoolDate);
    ui->majority->setCurrentText(ui->infoTable->item(sel, 4)->text());

    ui->postExam->setChecked(false);
    ui->findJob->setChecked(false);
    if(-1 != ui->infoTable->item(sel, 5)->text().indexOf(ui->postExam->text())) {
        ui->postExam->setChecked(true);
    }
    if(-1 != ui->infoTable->item(sel, 5)->text().indexOf(ui->findJob->text())) {
        ui->findJob->setChecked(true);
    }

    ui->cppPro->setChecked(false);
    ui->javaPro->setChecked(false);
    ui->webPro->setChecked(false);
    if(-1 != ui->infoTable->item(sel, 6)->text().indexOf(ui->cppPro->text())) {
        ui->cppPro->setChecked(true);
    }
    if(-1 != ui->infoTable->item(sel, 6)->text().indexOf(ui->javaPro->text())) {
        ui->javaPro->setChecked(true);
    }
    if(-1 != ui->infoTable->item(sel, 6)->text().indexOf(ui->webPro->text())) {
        ui->webPro->setChecked(true);
    }
}
