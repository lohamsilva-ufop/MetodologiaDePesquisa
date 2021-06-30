#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
/*
Nome: Loham Santos da Silva
Disciplina: Metodologia de Pesquisa em computa��o - PCC103
T�pico: "Dispersao"
*/

//procedimento que ordena o vetor passado por refer�ncia.
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

//fun��o que mostra a media
double mean(const std::vector<double>& data){
double datas = 0;

//acumula-se a soma do valores do vetor
    for(int i=0; i<data.size(); i++){
        datas = datas + data[i];
    }

//retorna o somatorio divido pela quantidade
    return datas/data.size();
}


void interval(const std::vector<double>& data, int minimum, int maximum){
    double sub = maximum - minimum;
    double intervalo = sub / 5;
    double valor = minimum;
    vector <vector <double>> interv;
    cout << "Intervalo: " << valor;

    /* while (valor < maximum){
        valor = valor + intervalo;
        cout << valor << endl;

        for(int i=0; i<data.size(); i++){
                vector <double> it;


            if(data[i] < valor){
                contador = contador + 1;
                it.push_back()
            }
        }*/
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

int main(){
    std::vector <double> data {148,170,155,131};
    int tamanho = data.size();

    interval(data, 4, 94);
    cout << endl;
    cout << "Media dos dados e: " << mean(data) << endl;
    cout << "A variancia dos dados e: " << variance(data) << endl;
    cout << "O desvio padrao dos dados e: " << std_dev(data) << endl;


    return 0;
}
