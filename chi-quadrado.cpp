#include<bits/stdc++.h>

#define _1k 1000
#define _10k 10000
#define _100k 100000
#define _100 100
#define freq_Esperada _100k

using namespace std;

int main(){
    long long int elemento;
    double chi_quadrado = 0.0;
    vector<long long int> freq_Observada;

    freq_Observada.assign(10,0LL);
    while(cin>>elemento){
        // cout<<ignore<<elemento<<endl;
        freq_Observada[elemento]++;
    }
    cout<<"frequencia do 0: "<<freq_Observada[0]<<endl;
    cout<<"frequencia do 1: "<<freq_Observada[1]<<endl;
    cout<<"frequencia do 2: "<<freq_Observada[2]<<endl;
    cout<<"frequencia do 3: "<<freq_Observada[3]<<endl;
    cout<<"frequencia do 4: "<<freq_Observada[4]<<endl;
    cout<<"frequencia do 5: "<<freq_Observada[5]<<endl;
    cout<<"frequencia do 6: "<<freq_Observada[6]<<endl;
    cout<<"frequencia do 7: "<<freq_Observada[7]<<endl;
    cout<<"frequencia do 8: "<<freq_Observada[8]<<endl;
    cout<<"frequencia do 9: "<<freq_Observada[9]<<endl;
    cout<<freq_Esperada<<endl;
    for(int i=0; i<10; i++){
        chi_quadrado += ((pow(freq_Observada[i]-freq_Esperada, 2))/(freq_Esperada));
    }
    cout<<endl;
    cout<<"CHI QUADRADO: "<<chi_quadrado<<endl;
}
