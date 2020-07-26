#include <iostream> 
using namespace std;


void torre(int p, string t1, string t2, string t3)
{
    if (p == 1) //mueve el plato p-1 de t1 a t2 
    {
        cout << "plato 1 de torre " << t1 << " a torre " << t2<<"\n";
        return;
    }
    
    torre(p - 1, t1, t3, t2); // mueve el ultimo plato de t1 a t3

    cout << "plato " << p << " de torre " << t1 << " a torre " << t2<<"\n";
    
    torre(p - 1, t3, t2, t1); //mueve el plato p-1 de t2 a t3 
}

int main()
{
    int n;
    cout << "ingresa cantidad de platos: ";
    cin >> n;// Numero de platos
    torre(n, "t1", "t2", "t3"); // las torres
    cout << "terminado";
}
