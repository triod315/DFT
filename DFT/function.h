#ifndef FUNCTION_H
#define FUNCTION_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>


class function
{
private:
    QVector<double> y_array;
    QVector<double> x_array;
    int points_count;
public:

    struct complex
    {
        double real;
        double imag;
        complex(double real, double imag);

        complex();
    };

    function();
    function(QVector<double> x_array,QVector<double> y_array); //set array of x and y

    QVector<double> getX();

    QVector<double> getY();

    //static QVector<double> complex_array_to_qvector(QVector<std::complex<double>> arr);
    //static QVector<std::complex<double>> double_array_to_complex_arr(QVector<double> arr);
    static QVector<function::complex> DFT(QVector<double> in_array, int N);

    QVector<double> calc_phase();
    QVector<double> calc_dft_ampl();
};

#endif // FUNCTION_H
