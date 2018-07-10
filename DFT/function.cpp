#include "function.h"
#include <math.h>

# define M_PI 3.14159265358979323846

function::function()
{

}


function::complex::complex(double real, double imag)
{
    this->real=real;
    this->imag=imag;
}

function::complex::complex()
{
    this->real=0;
    this->imag=0;
}

/*QVector<std::complex<double>> function::double_array_to_complex_arr(QVector<double> arr)
{
    QVector<std::complex<double>> out_arr(arr.count());
    for (int i=0;i<arr.count();i++)
    {
        out_arr[i]=arr[i];
    }
    return out_arr;
}

QVector<double> function:: complex_array_to_qvector(QVector<std::complex<double> > arr)
{
    QVector<double> out_arr(arr.count());
    for (int i=0;i<arr.count();i++)
    {
        out_arr[i]=arr[i].real();
    }
    return out_arr;
}*/

function::function(QVector<double> x,QVector<double> y)
{
    if (x.count()==y.count())
    {
        this->x_array=x;
        this->y_array=y;
        points_count=x.count();
    }
    else
    {
        throw "different count of elements in X array and Y array";
    }
}

QVector<double> function::getX()
{
    return  x_array;
}

QVector<double> function::getY()
{
    return y_array;
}

QVector<double> function::calc_phase()
{
    int N=y_array.count();
    QVector<function::complex> tmp_arr=DFT(y_array,N);
    QVector<double> result(N);

    for (int i=0;i<N;i++)
    {
        if (std::abs(tmp_arr[i].real)<1e-5)
        {
            if (tmp_arr[i].imag>1e-5)
                result[i]=90;
            if (std::abs(tmp_arr[i].imag)<1e-5)
                result[i]=0;
            if ((tmp_arr[i].imag<0) && (std::abs(tmp_arr[i].imag)>1e-5))
                result[i]=-90;
        }
        else
            result[i]=std::atan2(tmp_arr[i].imag,tmp_arr[i].real)*180/M_PI;
    }

    return result;

}

QVector<double> function::calc_dft_ampl()
{
    int N=y_array.count();
    QVector<function::complex> tmp_arr=DFT(y_array,N);
    QVector<double> result(N);

    for (int i=0;i<N;i++)
    {
        result[i]=std::sqrt(tmp_arr[i].real*tmp_arr[i].real+tmp_arr[i].imag*tmp_arr[i].imag)/(N/2);
    }

    return result;
}


 QVector<function::complex> function::DFT(QVector<double> in_array, int N)
{

    complex s;
    static QVector<complex> out_array(N);

    for (int i=0;i<N;i++)
    {
        s.real=0;
        s.imag=0;
        for (int j=0;j<N;j++)
        {
            s.real+=in_array[j]*M_PI*std::cos(2*M_PI*i*j/N);
            s.imag-=in_array[j]*M_PI*std::sin(2*M_PI*i*j/N);
        }
        out_array[i].real=s.real;
        out_array[i].imag=s.imag;
    }

    return out_array;

}
