#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
Nome: Loham Santos da Silva
Disciplina: Metodologia de Pesquisa em computação - PCC103
Tópico: "Intervalos de Confiança"
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

double normal_distribution_cdf(double x1, double x2, double mu, double std_dev){
    double z1 = x1-mu/std_dev*sqrt(2);
    double ic1 = 0.5 * (1+ erf(z1));


    double z2 = x2-mu/std_dev*sqrt(2);
    double ic2 = 0.5 * (1+ erf(z2));

    double p = ic1/ic2;
    return p;
}

double normal_distribution_cdf(double x1, double x2){
    double mu = 0;
    double std_dev = 1;

    double z1 = x1-mu/std_dev*sqrt(2);
    double ic1 = 0.5 * (1+ erf(z1));


    double z2 = x2-mu/std_dev*sqrt(2);
    double ic2 = 0.5 * (1+ erf(z2));

    double p = ic1/ic2;
    return p;

}

double normal_distribution_cdf(double x, double mu, double std_dev){
    double z = x-mu/std_dev*sqrt(2);
    double ic = 0.5 * (1+ erf(z));
    return ic;
}

double normal_distribution_cdf(double x){
    double mu = 0;
    double std_dev = 1;
    double z = x-mu/std_dev*sqrt(2);
    double ic = 0.5 * (1+ erf(z));
    return ic;
}

int main(){
    std::vector <double> data {148,170,155,131};
    int tamanho = data.size();
    double x1;
    double x2;

    cout << "Digite o valor do ponto X1: ";
    cin >> x1;

    cout << "Digite o valor do ponto X2: ";
    cin >> x1;

    double mu = mean(data);
    double dp = std_dev(data);
    cout << "Media dos dados e: " << mu << endl;
    cout << "O desvio padrao dos dados e: " << dp << endl;
    cout << "O intervalo de confianca para o ponto x1 e: " << normal_distribution_cdf(x1,mu,dp) << endl;
    cout << "O intervalo de confianca para o ponto x1 sem media e desvio padrao e: " << normal_distribution_cdf(x1) << endl;
    cout << "O intervalo de confianca para os pontos x1 e x2 sao: " << normal_distribution_cdf(x1,x2,mu,dp) << endl;
    cout << "O intervalo de confianca para o ponto x1 sem media e desvio padrao e: " << normal_distribution_cdf(x1,x2) << endl;

    return 0;
}
