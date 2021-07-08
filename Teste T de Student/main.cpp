#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
Nome: Loham Santos da Silva
Disciplina: Metodologia de Pesquisa em computação - PCC103
Tópico: "Dispersao"
*/

//procedimento que ordena o vetor passado por referência.
void ordena(std::vector<double>& data){
int temp;
int tamanho = data.size();

    for(int i=0; i<tamanho; i++){
        for(int j=0; j<tamanho-1; j++){
            if (data[j] > data[j+1]) {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

//função que mostra a media
double mean(const std::vector<double>& data){
double datas = 0;

//acumula-se a soma do valores do vetor
    for(int i=0; i<data.size(); i++){
        datas = datas + data[i];
    }

//retorna o somatorio divido pela quantidade
    return datas/data.size();
}

double variance(const std::vector<double>& data){
    double media = mean(data);
    int quantidade = data.size();
    double variancia = 0.0;

    for (int i=0; i<quantidade; i++){

        variancia = variancia + pow((data[i] - media),2);
    }

    return variancia/quantidade;

}
double std_dev(const std::vector<double>& data){
    return sqrt(variance(data));
}

double grau_de_liberdade(){

}

double estatistica(){

}



int main(){
    std::vector <double> amostra1 {148,170,155,131};
    std::vector <double> amostra2 {190,290,340,451};
    int tamanho = amostra1.size();


    cout << endl;
    cout << "Media da amostra 1 e: " << mean(amostra1) << endl;
    cout << "Media da amostra 2 e: " << mean(amostra2) << endl;
    cout << "O desvio padrao da amostra 1 e: " << std_dev(amostra1) << endl;
    cout << "O desvio padrao da amostra 2 e: " << std_dev(amostra2) << endl;

    return 0;
}
