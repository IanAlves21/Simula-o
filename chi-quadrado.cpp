#include<bits/stdc++.h>

#define _1k 1000
#define _10k 10000
#define _100k 100000
#define _100 100
#define freq_Esperada _100k

using namespace std;

int main(){
    long long int elemento, ignore;
    double chi_quadrado = 0.0;
    vector<long long int> freq_Observada;

    freq_Observada.assign(10,0LL);
    while(cin>>elemento){
        // cout<<ignore<<elemento<<endl;
        freq_Observada[elemento]++;
    }
    cout<<"Distribuição de "<<(freq_Esperada*10)<<"elementos"<<endl<<endl;
    cout<<"Frequencia do 0: "<<freq_Observada[0]<<endl;
    cout<<"Frequencia do 1: "<<freq_Observada[1]<<endl;
    cout<<"Frequencia do 2: "<<freq_Observada[2]<<endl;
    cout<<"Frequencia do 3: "<<freq_Observada[3]<<endl;
    cout<<"Frequencia do 4: "<<freq_Observada[4]<<endl;
    cout<<"Frequencia do 5: "<<freq_Observada[5]<<endl;
    cout<<"Frequencia do 6: "<<freq_Observada[6]<<endl;
    cout<<"Frequencia do 7: "<<freq_Observada[7]<<endl;
    cout<<"Frequencia do 8: "<<freq_Observada[8]<<endl;
    cout<<"Frequencia do 9: "<<freq_Observada[9]<<endl<<endl;
    cout<<"Frequencia esperada: "<<freq_Esperada<<endl;
    for(int i=0; i<10; i++){
        chi_quadrado += ((pow(freq_Observada[i]-freq_Esperada, 2))/(freq_Esperada));
    }
    cout<<endl;
    cout<<"teste do CHI-QUADRADO: "<<chi_quadrado<<endl;
}
