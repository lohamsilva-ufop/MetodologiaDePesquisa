#include <iostream>
#include <vector>


void mostraVetorOrdenado(std::vector<double>& data){
int tamanho = data.size();

    for(int i=0; i<tamanho; i++){
        std::cout << data[i] << ",";
    }

}

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

double mean(const std::vector<double>& data){
double datas = 0;
    for(int i=0; i<data.size(); i++){
        datas = datas + data[i];
    }

    return datas/data.size();
}

double mode(const std::vector<double>& data){

int contador = 0;
int maior = 0;
double dado;

    for(int i=0; i<data.size(); i++){
        for(int j=0; j<data.size(); j++){
            if(data[i] == data[j]){
                contador = contador + 1;
            }
        }
        if (contador > maior){
            maior = contador;
            dado = data[i];
        }
        contador = 0;
    }

    return dado;
}

double percentile(std::vector<double> &data, int p){
int tamanho = data.size();
double percentil;

//ordena o vetor
   ordena(data);

//calcula o percentil (encontra a posicao que esta o elemento)
    if(tamanho%2 == 0){
        percentil = (p * tamanho)/100;
        return data[percentil];
    } else {
        percentil = (p * (tamanho+1))/100;
        percentil = (data[percentil] + data[percentil+1])/2;
        return percentil;

    }

}

double median(std::vector<double>& data) {
    return percentile(data, 50);
}


int main()
{
    std::vector <double> data {4,5,8,9,15,7,89,45,7,18,14,13,12,14,25,50,69,17,14,16,94};


    std::cout << "A media dos dados e: " << mean(data) << std::endl;
    std::cout << "O valor que mais aparece (moda) e: " << mode(data) << std::endl;
    std::cout << "O percentil de 40 por cento dos dados e: " << percentile(data,40) << std::endl;
    std::cout << "A mediada dos dados e: " << median(data) << std::endl;

    std::cout << std::endl;
    std::cout << "Vetor ordenado: ";
    mostraVetorOrdenado(data);


    return 0;
}
