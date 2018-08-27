  #include <iostream>
  #include <vector>
  using namespace std;
   int main()
  {
    vector <int> notas(5);
    vector <string> alumnos(5);
    int s_notas=0;
    for(int i=0;i<5;i++)
    {
        cin>>alumnos[i]>>notas[i];
        alumnos.push_back(alumnos[i]);
        notas.push_back(notas[i]);
        s_notas=s_notas+notas[i];

    }
    cout<<"El promedio es "<<s_notas/5<<endl;
    cout<<endl;
    int promedio=s_notas/5;
    cout<<"Los alumnos con puntajes bajos son: "<<endl;
    cout<<endl;
    for(int l=0;l<5;l++)
    {
        if(promedio>notas[l])
        {
            cout<<alumnos[l]<<" No aceptado "<<endl;
        }
    }
    cout<<endl;
    cout<<"Los alumnos con la puntuacion mas alta son: "<<endl;

    for(int k=0;k<5;k++)
    {
        if(promedio<notas[k])
        {
            cout<<alumnos[k]<<endl;
        }
    }

}