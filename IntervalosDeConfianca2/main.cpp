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


void interval(std::vector<double>& data){
    int minimum;
    int maximum;
    int quantidade = data.size();
    ordena(data);
    minimum = data[0];
    maximum = data[quantidade-1];
    cout << "O valor minimo e maximo do intervalo sao respectivamente: " << minimum << " e " << maximum;
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

double t_distribution_pdf(double x, int v){
    double pi = 3.14;
    double st1 = tgamma(v+1/2)/ (sqrt(v*pi) * tgamma(v/2));
    double st2 = pow(1 + (pow(x,2)/v), -(v+1/2));
    double distribuition_t = st1 * st2;
    return distribuition_t;
}

double t_distribution_cdf(double x, int v){
    double st1 = 0.5 + x * tgamma(v+1/2);
    double st2;

}

int main(){
    std::vector <double> data {148,170,155,131};
    int tamanho = data.size();
    double x1, x2, v;

    cout << "Digite o ponto X1: ";
    cin >> x1;

    cout << "Digite o ponto X2: ";
    cin >> x1;

    cout << "Digite o grau de liberdade v: " << endl;
    cin >> v;


    cout << endl;
    cout << "Media dos dados e: " << mean(data) << endl;
    cout << "A variancia dos dados e: " << variance(data) << endl;
    cout << "O desvio padrao dos dados e: " << std_dev(data) << endl;
    cout << "O intervalo de confianca para x e: " << t_distribution_pdf(x1,v) << endl;


    return 0;
}
