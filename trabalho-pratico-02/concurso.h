#include <iostream>
using namespace std;

struct horario {
	int hor{};
	int min{};
};

struct questao {
	int dificuldade{};
	horario inicio{};
	horario fim{};
};

struct media {
	float mediaDificuldade{};
	float mediaTempo{};
};

struct participante {
	char nome[20];
	questao* questoes;
};

istream& operator>>(istream&, horario&);
int operator-(horario, horario);

void exibirQuestao(questao[], int);
media calcularMedia(questao[], int, int, int);
void exibirCaractere(char, int);