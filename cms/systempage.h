#ifndef SYSTEMPAGE_H
#define SYSTEMPAGE_H

#include <QMainWindow>
#include <QListWidget>
#include <QStackedWidget>

namespace Ui {
class SystemPage;
}

class SystemPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit SystemPage(QWidget *parent = nullptr);
    ~SystemPage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SystemPage *ui;

    QListWidget* m_leftMenu;
    QStackedWidget* m_contentStack;
    QWidget* createChartPage();      // 创建第一个图表页面
    QWidget* createEmptyPage(const QString& text); // 创建空白页
};

#endif // SYSTEMPAGE_H
