#include<bits/stdc++.h>

using namespace std;

int main(){
    srand(time(NULL));
    for(int i=0; i<1000000; i++){
        printf("%d\n",(rand()%10));
    }

    return 0;
}
