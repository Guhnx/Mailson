#include <iostream>

using namespace std;

int SomaImpares(int num){
    int numImpares = 0;
    for(int i=0; i<=num; i++){
        if((i % 2) == 1){
            numImpares += i;
        }
    }
    return numImpares;
}

int main(){
    int num;
    cout << "Insira um valor: ";
    cin >> num;
    
    if(num >= 0){
        int result = SomaImpares(num);
        cout << "Resultado: " << result;
    } else {
        cout << "Numero nao e positivo" << endl;
    }
}