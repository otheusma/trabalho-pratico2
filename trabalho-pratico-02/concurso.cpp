#include <iostream>
#include "concurso.h"

using namespace std;

int operator-(horario inicio, horario fim) {
	return ((fim.hor * 60 + fim.min) - (inicio.hor * 60 + inicio.min));
}

// utiliza o operador << para exibir variaveis do tipo horario
ostream& operator<<(ostream& os, horario h) {
	return os << h.hor << ":" << h.min;
}

// utiliza o operador >> para ler variaveis do tipo horario
istream& operator>>(istream& is, horario &h) {
	is >> h.hor;
	is.ignore();
	is >> h.min;
	return is;
}

// exibe na tela as informações de um vetor de questao
void exibirQuestao(questao vet[], int pos) {
		cout << " (" << vet[pos].dificuldade << ") ";
		cout << vet[pos].inicio << " as ";
		cout << vet[pos].fim;
		cout << " (" << (vet[pos].inicio - vet[pos].fim) << " min)";
		cout << '\n';
}

// calcula a média aritimética da dificuldade e tempo das questões
media calcularMedia(questao vet[], int tam, int indice, int passo) {
	media temp{};
	for (int i = indice; i < tam; i = i + passo) {
		temp.mediaDificuldade += vet[i].dificuldade;
		temp.mediaTempo += (vet[i].inicio - vet[i].fim);
	}
	temp.mediaDificuldade /= (tam / passo);
	temp.mediaTempo /= (tam / passo);
	return temp;
}

// exibe um mesmo caractere N vezes e quebra a linha
void exibirCaractere(char ch, int tam) {
	for (int i = 0; i < tam; i++) {
		cout << ch;
	}
	cout << '\n';
}

