#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_addButtom_clicked();

    void on_updateButton_clicked();

    void on_deleteButton_clicked();

    void on_itemDoubleClickedSlot();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
