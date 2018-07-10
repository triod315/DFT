#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <function.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*QVector<double> calc_ampl(QVector<std::complex<double>> arr)
{
    QVector<double> result(arr.count());
    for (int i=0;i<arr.count();i++)
        result[i]=std::abs(arr[i])/arr.count();
    return result;
}
*/
double min(QVector<double> arr)
{
    double min = arr[0];
    for (int i=1;i<arr.count();i++)
        if (arr[i]<min) min = arr[i];
    return min;
}

double max(QVector<double> arr)
{
    double max = arr[0];
    for (int i=1;i<arr.count();i++)
        if (arr[i]>max) max = arr[i];
    return max;
}

QVector<double> calc_freq(int n, double lenght)
{
    QVector<double> result(n);
    for (int i=0;i<n;i++)
        result[i]=i/lenght;
    return result;
}

void MainWindow::on_pushButton_clicked()
{
    ui->function_plot->addGraph();

    int size=1001;

    QVector<double> x(size), y(size);

    for (int i=0;i<size;i++)
    {
        x[i]=i/25.0-1;
        y[i]=std::sin(x[i])+std::sin(ui->doubleSpinBox->value()*x[i])+std::sin(ui->doubleSpinBox->value()*x[i]*M_PI/18);
    }

    function func(x,y);



    ui->function_plot->graph(0)->setData(func.getX(),func.getY());

    ui->function_plot->xAxis->setLabel("x");
    ui->function_plot->yAxis->setLabel("y");

    ui->function_plot->xAxis->setRange(x[0],x[size-1]);
    ui->function_plot->yAxis->setRange(min(y)-2,max(y)+2);

    ui->function_plot->replot();

   // QVector<function::complex> tem_arr=function::DFT(y,y.count());

    QVector<double> ampl=func.calc_dft_ampl();

    QVector<double> freq=calc_freq(x.count(),x[size-1]-x[0]);

    ui->amplitude_plot->addGraph();
    ui->amplitude_plot->graph(0)->setData(freq,ampl);
    ui->amplitude_plot->yAxis->setLabel("Amplitude");
    ui->amplitude_plot->xAxis->setLabel("Frequency");

    ui->amplitude_plot->xAxis->setRange(freq[0],freq[size/2-1]);
    ui->amplitude_plot->yAxis->setRange(min(ampl)-2,max(ampl)+2);
    ui->amplitude_plot->replot();


    QVector<double> phase=func.calc_phase();

    ui->phase_plot->addGraph();
    ui->phase_plot->graph(0)->setData(freq,phase);
    ui->phase_plot->xAxis->setLabel("Frequency");
    ui->phase_plot->yAxis->setLabel("Phase");

    ui->phase_plot->xAxis->setRange(freq[0],freq[size/2-1]);
    ui->phase_plot->yAxis->setRange(min(phase)-2,max(phase)+2);
    ui->phase_plot->replot();
}

void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::exit();
}
