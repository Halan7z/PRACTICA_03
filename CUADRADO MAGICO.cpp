#include<iostream>
using namespace std;
int main ()
{
    int n;
    cout<<"Ingrese el valor de n, si la matriz es (n x n): ";cin>>n;
    int Matriz[n][n];
    int valor=2,fila=0,columna=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            Matriz[i][j]=0;
    }
    Matriz[0][0]=1;
    while(valor<=n*n)
    {
        bool libre=false;
        while(true)
        {
            if(fila==n-1)
                fila=0;
            else
                fila++;
            if(columna==n-1)
                columna=0;
            else
                columna++;
            if(Matriz[fila][columna]==0)
            {
                libre=true;
            }
            else
            {
                if(fila==n-1)
                    fila=0;
                else
                    fila++;
                if(columna==0)
                    columna=n-1;
                else
                    columna--;
                if(Matriz[fila][columna]==0)
                {
                    libre=true;
                }
            }
            if(libre)
            {
                Matriz[fila][columna]=valor;
                valor++;
                break;
            }
        }

    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<Matriz[i][j]<<"  ";
        cout<<"\n";
    }
    return 0;
}
