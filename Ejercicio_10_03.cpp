// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 07/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 10

// Problema planteado: Queremos realizar una encuesta a 10 personas, en esta encuesta indicaremos el sexo.....
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    const int numPersonas=10;
    int encuesta[numPersonas][3]; // Matriz para almacenar sexo, estado laboral y sueldo
    for (int i = 0; i < numPersonas; i++)
    {
        encuesta[i][0]=rand()%2+1; // 1=masculino, 2=femenino
        encuesta[i][1]=rand()%2+1; // 1=si trabaja, 2=no trabaja
        encuesta[i][2]=(encuesta[i][1]==1)?rand()%1401+600:0; // Sueldo entre 600 y 2000 si trabaja, 0 si no trabaja
    }
    int hombres=0, mujeres=0, hombresTrabajan=0, mujeresTrabajan=0;
    int sueldoHombresTrabajan=0, sueldoMujeresTrabajan=0;
    for (int i=0; i<numPersonas; i++)
    {
        if (encuesta[i][0]==1)
        {
            hombres++;
            if (encuesta[i][1]==1)
            {
                hombresTrabajan++;
                sueldoHombresTrabajan+=encuesta[i][2];
            }
        }
        else
        {
            mujeres++;
            if (encuesta[i][1]==1)
            {
                mujeresTrabajan++;
                sueldoMujeresTrabajan+=encuesta[i][2];
            }
        }
    }
    double porcentajeHombres=(hombres*100.0)/numPersonas;
    double porcentajeMujeres=(mujeres*100.0)/numPersonas;
    double porcentajeHombresTrabajan=(hombresTrabajan*100.0)/hombres;
    double porcentajeMujeresTrabajan=(mujeresTrabajan*100.0)/mujeres;
    double promedioSueldoHombresTrabajan=(hombresTrabajan==0)?0:sueldoHombresTrabajan/hombresTrabajan;
    double promedioSueldoMujeresTrabajan=(mujeresTrabajan==0)?0:sueldoMujeresTrabajan/mujeresTrabajan;
    cout<<"Porcentaje de hombres: "<<porcentajeHombres<<"%"<<endl;
    cout<<"Porcentaje de mujeres: "<<porcentajeMujeres<<"%"<<endl;
    cout<<"Porcentaje de hombres que trabajan: "<<porcentajeHombresTrabajan<<"%"<<endl;
    cout<<"Porcentaje de mujeres que trabajan: "<<porcentajeMujeresTrabajan<<"%"<<endl;
    cout<<"Sueldo promedio de los hombres que trabajan: "<<promedioSueldoHombresTrabajan<<endl;
    cout<<"Sueldo promedio de las mujeres que trabajan: "<<promedioSueldoMujeresTrabajan<<endl;
    return 0;
}

