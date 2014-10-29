#include<iostream>
#include<vector>
using namespace std;
class producto
{
public:
    long id;
    int cantvendidas;
public:
    producto() {}
    producto(long ida, int cant)
    {
        id=ida;
        cantvendidas=cant;
    }
};
int main()
{
    int c;
    cout<<"Ingrese numero de posciones: ";
    cin>>c;
    producto x[50][50][50];
    for(int i=0; i<c; i++)
    {
        for(int j=0; j<c; j++)
        {
            for(int k=0; k<c; k++)
            {
                long id;
                int cant;
                cout<<"Ingrese id del producto "<<k<< " de la sucursal "<<j<<" el dia "<<i<<": ";
                cin>>id;
                cout<<"Ingrese Cantidad vendida del producto "<<k<< " de la sucursal "<<j<<" el dia "<<i<<": ";
                cin>>cant;
                producto aux(id,cant);
                x[i][j][k]=aux;
            }
        }
    }
    cout<<"Lista de los más vendidos cada dia en cada sucursal: \n";
    for(int i=0; i<c; i++)
    {
        for(int j=0; j<c; j++)
        {
            producto ret = x[i][j][0];
            for(int k=1; k<c; k++)
            {
                if(ret.cantvendidas<x[i][j][k].cantvendidas)
                    ret = x[i][j][k];
            }
            cout<<"El producto más venido en el dia "<<i<<" en la sucursal "<<j<<" es el de ID: "<<ret.id<<endl;
        }
    }
    return 0;
}
