#include <iostream>
#include <vector>

/*
Nome: Loham Santos da Silva
Disciplina: Metodologia de Pesquisa em computação - PCC103
Tópico: "O Significado de média"
*/


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

//função que verifica a moda
double mode(const std::vector<double>& data){

int contador = 0;
int maior = 0;
double dado;

    for(int i=0; i<data.size(); i++){
        for(int j=0; j<data.size(); j++){
            if(data[i] == data[j]){
                //se o valor na posição i se repete em j, contador soma 1
                contador = contador + 1;
            }
        }
        //se o contador é maior que o ultimo contador (maior)
        if (contador > maior){
            //maior atualiza e o dado é capturado
            maior = contador;
            dado = data[i];
        }
        //contador é zerado para contar de novo
        contador = 0;
    }

    //retorna o dado
    return dado;
}

//função que calcula o percentil
double percentile(std::vector<double> &data, int p){
int tamanho = data.size();
double percentil;

//ordena o vetor
   ordena(data);

//calcula o percentil (encontra a posicao que esta o elemento)

    percentil = (p * tamanho)/100;

//se o percentil é par, soma com o proximo e divide por 2
    if((int) percentil%2 == 0){
         percentil = (data[percentil] + data[percentil])/2;
        return percentil;
    } else { //se o percentil é impar, retorne o elemento naquela posição
        return data[percentil];
    }
//fonte do calculo: http://www.bessegato.com.br/PUC/iec_transp_02.pdf
}

//funcao que verifica a mediana (o valor que esta no meio). Retorna o percentil de 50% da amostra
double median(std::vector<double>& data) {
    return percentile(data, 50);
}


int main()
{
    std::vector <double> data {4,5,8,9,15,7,89,45,7,18,14,13,12,14,25,50,69,17,14,16,94};


    std::cout << "A media dos dados e: " << mean(data) << std::endl;
    std::cout << "O valor que mais aparece (moda) e: " << mode(data) << std::endl;
    std::cout << "O percentil de 70 por cento dos dados e: " << percentile(data,70) << std::endl;
    std::cout << "A mediada dos dados e: " << median(data) << std::endl;

    std::cout << std::endl;
    std::cout << "Vetor ordenado: ";
    mostraVetorOrdenado(data);


    return 0;
}
