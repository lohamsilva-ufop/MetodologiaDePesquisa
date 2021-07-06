#include <iostream>
#include <vector>
#include <math.h>


/*
Nome: Loham Santos da Silva
Disciplina: Metodologia de Pesquisa em computação - PCC103
Tópico: "Médias não são tudo"
*/

using namespace std;

//procedimento que mostra o vetor
void mostraVetorOrdenado(std::vector<double>& data){
int tamanho = data.size();

    for(int i=0; i<tamanho; i++){
        std::cout << data[i] << ",";
    }
}

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

double normal_distribution_pdf(double x, double mu, double std_dev){
     double PI = 3.14;
     double E = 2.71;


    double std_dev_q = pow(std_dev,2);
    double dn = (2 * PI) * std_dev_q;
    double st1 = sqrt(dn);


    double pt = pow(x-mu,2)/2*std_dev_q;
    double st2 = pow(E,-pt);

    double s = 1/st1 * st2;

    return s;
}


double normal_distribution_pdf(double x){
     double PI = 3.14;
     double E = 2.71;
     double mu = 0;
     double std_dev = 1;


    double std_dev_q = pow(std_dev,2);
    double st1 = (2 * PI) * std_dev_q;
    st1 = sqrt(st1);


    double st2 = pow(x-mu,2)/2*std_dev_q;
    st2 = pow(E,-st2);

    double s = 1/st1 * st2;



    return s;
}

int main(){

    std::vector <double> data {4,5,8,9,15,7,89,45,7,18,14,13,12,14,25,50,69,17,14,16,94};
    double media = mean(data);
    double desvio_padrao = std_dev(data);
    double x;

    cout << "Digite o ponto X: ";
    cin >> x;

    std::cout << "A media dos dados e: " << mean(data) << std::endl;
    std::cout << "Desvio padrao: " << desvio_padrao << std::endl;

    std::cout << "Distribuicao normal 1: " << normal_distribution_pdf(x, media, desvio_padrao) << std::endl;
    std::cout << "Distribuicao normal 2: " << normal_distribution_pdf(x) << std::endl;

    std::cout << std::endl;
    std::cout << "Vetor ordenado: ";
    ordena(data);
    mostraVetorOrdenado(data);

    return 0;
}
