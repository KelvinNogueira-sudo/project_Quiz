#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <vector>
#include <cstdlib>
using namespace std;

void cleanScreen() {
    system("clear");
}

void cleanBuffer() {
    if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void printLogo() {
    cout << R"(
================================================================================
__________                   __               __    ________        .__        
\______   \_______  ____    |__| ____   _____/  |_  \_____  \  __ __|__|_______
|     ___/\_  __ \/  _ \   |  |/ __ \_/ ___\   __\  /  / \  \|  |  \  \___   /
|    |     |  | \(  <_> )  |  \  ___/\  \___|  |   /   \_/.  \  |  /  |/    / 
|____|     |__|   \____/\__|  |\___  >\___  >__|   \_____\ \_/____/|__/_____ \
                         \______|    \/     \/              \__>              \/
================================================================================
)";
}

void printScore() {
    cout << R"( _________                           
 /   _____/ ____  ___________   ____  
 \_____  \_/ ___\/  _ \_  __ \_/ __ \ 
 /        \  \__(  <_> )  | \/\  ___/ 
/_______  /\___  >____/|__|    \___  >
        \/     \/                  \/ 

============ Top 10 Sábios ============
)";
    cout << "Nome\t\t\t\t Pontos\n\n";
}

void showInfo() {
    cout << R"(
 ______________________________________________________________________________
/ Informações sobre o Quiz:                                                     \
| - Serão 15 perguntas aleatórias para responder, cada uma com 4 alternativas;  |
| - Para cada resposta correta, será acrescentado +10 pontos na sua pontuação;  |
| - Para cada resposta errada, será subitraído -5 pontos na sua pontuação;      |
| - Você terá apenas 10 segundos para responder cada pergunta (em caso de time- |
| out, a pergunta será pulada para a próxima e não pontuará);                   |
|                                                                               |
\ - Boa Sorte (⌐■_■);                                                           /
 -------------------------------------------------------------------------------
)";
}

void easterEgg() {
    cout << R"(
*PARABÉNS, VOCÊ PONTOU O SUFICIENTE PARA DESCOBRIR O EASTER EGG!*
            ⬜⬜⬛⬜⬛⬛⬛⬛⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜
            ⬜⬛⬜⬛⬜⬜⬜⬜⬛⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜
            ⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜
            ⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬜⬜⬜⬜⬜⬜⬛⬜
            ⬛⬜⬜⬛⬜⬜⬛⬜⬜⬜⬜⬜⬛⬜⬜⬜⬜⬛⬜⬛
            ⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬛⬜⬛
            ⬛⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬜⬛
            ⬛⬜⬛⬜⬛⬜⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛
            ⬛⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛
            ⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛
            ⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛
            ⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛
            ⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛
            ⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬜
            ⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬜
            ⬜⬛⬜⬜⬛⬛⬜⬜⬛⬛⬛⬛⬜⬜⬛⬛⬜⬜⬛⬜
            ⬜⬛⬜⬛⬜⬛⬜⬜⬛⬜⬜⬛⬜⬜⬛⬛⬜⬛⬜⬜
            ⬜⬜⬛⬜⬜⬛⬜⬛⬜⬜⬜⬛⬜⬛⬜⬜⬛⬜⬜⬜
            ⬜⬜⬜⬜⬜⬜⬛⬜⬜⬜⬜⬜⬛⬜⬜⬜⬜⬜⬜⬜
=================================================================
)";
}

void saveScore(Score p) {
    vector<Score> save;
    save.push_back(p);
    size_t len = p.name.size();

    try{
    //Salvar no Arquivo
    ofstream out ("../data/score/score.bin", ios::binary | ios::app);
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(p.name.c_str(), len);
    out.write(reinterpret_cast<const char*>(&p.points), sizeof(p.points));

    out.close();
    }
    catch(...) {
        cout << "Erro ao Salvar Arquivo\n";
    }
}

void loadScore(const string& archive) {
    cleanScreen();
    printScore();

    vector<Score> loadScores;
    Score p;
    size_t len = p.name.size();

    ifstream load (archive, ios::binary);
    try{
        while(load.read(reinterpret_cast<char*>(&len), sizeof(len))) {
            p.name.resize(len);
            load.read(&p.name[0], len);
            load.read(reinterpret_cast<char*>(&p.points), sizeof(p.points));
    
            loadScores.push_back(p);
        }
    }
    catch(...) {
        cout << "Erro de Leitura\n";
    }
    sort(loadScores.begin(),loadScores.end());
    for(const auto&p : loadScores){
        cout << p.name << " .................................. " << p.points << '\n';
    }
    load.close();

    char next;
    cout << "\nDigite qualquer tecla para sair...\n";
    cin >> next;
    cleanScreen();
}

vector<Quest> loadQuest(const string& archive) {
    vector<Quest> list;
    string line;
    ifstream read(archive);

    if(!read.is_open()) {
        return list;
    }

    while(getline(read,line)) {
        stringstream ss(line); //stringstream para facilitar inserir as linhas do arquivo
        string field;
        Quest p;

        //Lê a pergunta do arquivo
        getline(ss, field, ';');
        p.text = field;

        //Lê as alternativas (4)
        for(int i = 0; i < 4; i++) {
            getline(ss, field, ';');
            p.altern.push_back(field); //push_back para inserir cada alternativa no vetor
        }

        //Se não achar mais ";", significa que chegou na resposta das perguntas
        if(!getline(ss, field, ';')) {
            continue;
        }

        try {
            p.answer = stoi(field); //stoi para converter string para int
        } catch(const exception&) {
            continue;
        }

        //Aloca as Structs (pergunta,alternativas,resposta) no vetor;
        list.push_back(p);
    }
    read.close();
    return list;
}

void start() {
    cleanScreen();
    showInfo();
    int response;
    int score = 0;
    char next;
    cout << "Digite [S] para Começar... \n";
    cin >> next;

    if(next == 'S' || next == 's') {
        cleanScreen();

        //Carregar as perguntas em um vetor de Structs
        vector<Quest> quizQuest = loadQuest("../data/questions/questions.bin");
        if(quizQuest.empty()) { //Caso de falha ao carregar o vetor
            cout << "Falha ao carregar as perguntas.\n";
            return;
        }
        mt19937 rng(random_device{}());
        shuffle(quizQuest.begin(), quizQuest.end(), rng); //Embaralha o vetor de forma aleatória, sem risco de tirar uma questão repitida

        //Loop de Exibição das Perguntas e Alternativas
        for(int i = 0; i < 15; i++) { 
            cleanScreen();
            cout << "Pontuação Atual: " << score << '\n';
            cout << "================================================================\n";
            Quest actual = quizQuest[i];

            //Mostra a Pergunta
            cout << actual.text << '\n' << '\n';

            //Mostra as Alternativas
            for(size_t k = 0; k < actual.altern.size(); k++) {
                cout << k+1 << ") " << actual.altern[k] << '\n';
            }

            //Recebe e checa a resposta
            cin >> response;
            cleanBuffer();
            if(response == actual.answer) {
                score += 10;
            }
            else score -= 5;
        }
        cleanScreen();

        cout << "\t\t=== Quiz Finalizado ===\n";
        if (score >= 140) easterEgg();
        cout << "Pontuação Final: " << score << '\n';
        cout << "Digite seu nome (Até 3 Letras): ";

        //Salva o Nome e pontuação:
        string name;
        Score player;

        cin >> name;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpar o '\n' restante
            if (name.size() >= 3) name.erase(3); //Se o nome digitado pelo usuário for maior que 3 caractéres, apaga de 3° em diante

        player.name = name;
        player.points = score;
        saveScore(player);

        cout << "Pontuação Salva\n";

    }
    else {
        cout << "Opção Inválida!\n";
    }
}