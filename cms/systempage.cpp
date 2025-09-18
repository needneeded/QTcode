#include "systempage.h"
#include "ui_systempage.h"
#include <QBarCategoryAxis>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QLabel>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QPieSeries>
#include <QtCharts/QCategoryAxis>

// 使用 QtCharts 命名空间
QT_CHARTS_USE_NAMESPACE

SystemPage::SystemPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SystemPage)
{
    ui->setupUi(this);

    // 初始化左侧菜单
    m_leftMenu = new QListWidget(this);
    m_leftMenu->setFixedWidth(150);
    m_leftMenu->addItem("首页");
    m_leftMenu->addItem("页面2");
    m_leftMenu->addItem("页面3");

    // 初始化右侧内容区域
    m_contentStack = new QStackedWidget(this);

    // 设置主布局
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->addWidget(m_leftMenu, 1);
    mainLayout->addWidget(m_contentStack, 4);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);

    // 添加页面
    m_contentStack->addWidget(createChartPage());
    m_contentStack->addWidget(createEmptyPage("这是页面2"));
    m_contentStack->addWidget(createEmptyPage("这是页面3"));

    // 连接信号槽：点击菜单切换页面
    connect(m_leftMenu, &QListWidget::currentRowChanged,
            m_contentStack, &QStackedWidget::setCurrentIndex);
}

SystemPage::~SystemPage()
{
    delete ui;
}

void SystemPage::on_pushButton_clicked()
{
    this->hide();

    this->parentWidget()->show();

}

QWidget* SystemPage::createChartPage()
{
    QWidget* page = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout(page);

    // 折线图 - 季度销售统计
    QLineSeries* lineSeries = new QLineSeries();
    lineSeries->setName("季度销售额");
    lineSeries->append(QPointF(0, 150));
    lineSeries->append(QPointF(1, 200));
    lineSeries->append(QPointF(2, 250));
    lineSeries->append(QPointF(3, 300));

    QChart* lineChart = new QChart();
    lineChart->addSeries(lineSeries);
    lineChart->createDefaultAxes();
    lineChart->setTitle("季度销售统计");

    QChartView* lineChartView = new QChartView(lineChart);
    layout->addWidget(lineChartView);

    // 柱状图 - 上半年销售统计
    QBarSet* barSet = new QBarSet("销售额");
    *barSet << 100 << 120 << 180 << 200 << 210 << 230;

    QBarSeries* barSeries = new QBarSeries();
    barSeries->append(barSet);

    QChart* barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("上半年销售统计");

    QStringList months = {"一月", "二月", "三月", "四月", "五月", "六月"};
    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(months);
    barChart->setAxisX(axisX, barSeries);
    barChart->createDefaultAxes();

    QChartView* barChartView = new QChartView(barChart);
    layout->addWidget(barChartView);

    // 饼图 - 水果销售统计
    QPieSeries* pieSeries = new QPieSeries();
    pieSeries->append("苹果", 40);
    pieSeries->append("香蕉", 30);
    pieSeries->append("橙子", 20);
    pieSeries->append("葡萄", 10);

    QChart* pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("水果销售统计");

    QChartView* pieChartView = new QChartView(pieChart);
    layout->addWidget(pieChartView);

    return page;
}

QWidget* SystemPage::createEmptyPage(const QString& text)
{
    QWidget* page = new QWidget;
    QLabel* label = new QLabel(text, page);
    label->setAlignment(Qt::AlignCenter);
    QVBoxLayout* layout = new QVBoxLayout(page);
    layout->addWidget(label);
    return page;
}
