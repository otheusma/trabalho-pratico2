#include <iostream>
#include "concurso.h"

using namespace std;

int main() {
	int qtdQuestoes{}, qtdParticipantes{};
	participante* participantes;
	questao* questoes;
	media* medias;

	exibirCaractere('*', 50);
	cout << "Concurso de Programacao\n\n";

	cout << "Qual o numero de participantes? ";
	cin >> qtdParticipantes;
	 participantes = new participante[qtdParticipantes]{};

	cout << "Qual o numero de questoes? ";
	cin >> qtdQuestoes;
	questoes = new questao[qtdQuestoes * qtdParticipantes]{};
	medias = new media[qtdQuestoes];

	cout << '\n'; exibirCaractere('*', 50);

	// recebe as questoes e participantes
	for (int i = 0, j = 0, q = 0; i < qtdParticipantes; i++, q = q + qtdQuestoes) {
		exibirCaractere('-', 13);
		cout << "Participante: ";
		cin >> participantes[i].nome;
		exibirCaractere('-', 13);

		for (int k = 0; k < qtdQuestoes; k++, j++) {
		cout << "Questao " << char('A' + k) << '\n';

		cout << "\tDificuldade: "; 
		cin >> questoes[j].dificuldade;

		cout << "\tInicio: ";
		cin >> questoes[j].inicio;

		cout << "\tFim: ";
		cin >> questoes[j].fim;

		}
		participantes[i].questoes = questoes + q;
		exibirCaractere('-', 13);  cout << '\n';
	}

	exibirCaractere('*', 50);

	exibirCaractere('-', 23);
	cout << "Resumo por Participante\n";
	exibirCaractere('-', 23);
	for (int i = 0; i < qtdParticipantes; i++) {                                                                                                                                        
		cout << participantes[i].nome << ":\n";
		for (int j = 0; j < qtdQuestoes; j++) {
			cout << '\t' << char('A' + j);
			exibirQuestao(participantes[i].questoes, j);
		}
	}

	exibirCaractere('-', 23); cout << "\n\n";

	exibirCaractere('-', 23);
	cout << "Resumo por Questao\n";
	exibirCaractere('-', 23);
	for (int i = 0; i < qtdQuestoes; i++) {
		cout << "Questao " << char('A' + i) << ":\n";
		for (int j = 0; j < qtdQuestoes; j++) {
			cout << '\t' << participantes[j].nome;
			exibirQuestao(participantes[j].questoes, i);
		}
	}

	exibirCaractere('-', 23); cout << "\n\n";

	exibirCaractere('-', 12);
	cout << "Estatisticas\n";
	exibirCaractere('-', 12);
	media concurso{};
	cout << fixed;
	cout.precision(2);
	for (int j = 0; j < qtdQuestoes; j++) {
		medias[j] = calcularMedia(questoes, qtdQuestoes * qtdParticipantes, j, qtdQuestoes);
		cout << "Questao " << char('A' + j) << ": ";
		cout << "Dificuldade (" << medias[j].mediaDificuldade << ") - Tempo (" << medias[j].mediaTempo << " minutos)\n";
		concurso.mediaDificuldade += medias[j].mediaDificuldade;
		concurso.mediaTempo += medias[j].mediaTempo;
	}
	cout << "Concurso:  Dificuldade (" << concurso.mediaDificuldade / qtdQuestoes << ") - Tempo (" << concurso.mediaTempo / qtdQuestoes << " minutos)\n\n";

	exibirCaractere('*', 50);

	delete[] questoes;
	delete[] participantes;
	delete[] medias;
}