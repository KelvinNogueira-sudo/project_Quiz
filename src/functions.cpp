#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <atomic>
#include <thread>
#include <chrono>
#include <random>
#include <vector>
#include <cstdlib>
#include <SFML/Audio.hpp>
using namespace std;

atomic<bool> timeOut(false);

void cleanScreen() {
    system("clear");
}

void cleanBuffer() {
    if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void timerQuiz(int seconds) {
    for(int i = 0; i < seconds; i++){
        if (timeOut) return; //Encerra se o usuário terminar antes do tempo acabar
        this_thread::sleep_for(chrono::seconds(1));
    }
    timeOut = true;
    cout << "\n\t === ⏰ Tempo Esgotado! ===\n";
    cout << "(Digite qualquer tecla para ver sua Pontuação)";
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
    cout << R"(
  _________                           
 /   _____/ ____  ___________   ____  
 \_____  \_/ ___\/  _ \_  __ \_/ __ \ 
 /        \  \__(  <_> )  | \/\  ___/ 
/_______  /\___  >____/|__|    \___  >
        \/     \/                  \/ 

============ Pontuação Geral ============
)";
    cout << "Nome\t\t\t\t Pontos\n\n";
}

void printStart() {
    cout << R"(
  _________ __                 __   
 /   _____//  |______ ________/  |_ 
 \_____  \\   __\__  \\_  __ \   __\
 /        \|  |  / __ \|  | \/|  |  
/_______  /|__| (____  /__|   |__|  
        \/           \/             )";
}

void showInfo() {
    cout << R"(
 ______________________________________________________________________________
/ Informações sobre o Quiz:                                                     \
|                                                                               |
| - Você terá 2:00 min para responder ao máximo de perguntas possíveis (30 no   |
| total) corretamente;                                                          |
| - Para cada resposta correta, será acrescentado +10 pontos na sua pontuação;  |
| - Para cada resposta errada, será subitraído -5 pontos na sua pontuação;      |
| - Em caso de resposta não correspondente (exemplo: 33, a, 7) a pergunta será  |
| pulada e você perderá 5 pontos (então preste atençao na sua resposta);        |
| - Em caso de Time Out (Tempo Acabar), o quiz será encerrado, e você poderá    |
| registrar sua pontuação.                                                      |
|                                                                               |
\ - Boa Sorte (⌐■_■);                                                           /
 -------------------------------------------------------------------------------
)";
}

void easterEgg() {
    cout << R"(
    *PARABÉNS, VOCÊ PONTOU O SUFICIENTE PARA ACHAR O DOGUINHO!*
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
  ===============================================================
)";

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("data/audio/annoying_dog.WAV")) {
        cerr << "Erro: não foi possível carregar o áudio!\n";
        return;
    }

    sf::Sound sound(buffer);
    sound.play();

    while(sound.getStatus() == sf::Sound::Status::Playing) {
            sf::sleep(sf::seconds(1));
    }
}

void saveScore(Score p) {
    size_t len = p.name.size();

    try{
    //Salvar no Arquivo
    ofstream out ("data/score/score.bin", ios::binary | ios::app);
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
    timeOut = false;
    cleanScreen();
    printStart();
    showInfo();

    int response;
    int score = 0;
    char next;
    cout << "Digite [S] para Começar... \n";
    cin >> next;

    if(next == 'S' || next == 's') {
        cleanScreen();

        //Carregar as perguntas em um vetor de Structs
        vector<Quest> quizQuest = loadQuest("data/questions/questions.txt");
        if(quizQuest.empty()) { //Caso de falha ao carregar o vetor
            cout << "Falha ao carregar as perguntas.\n";
            return;
        }

        mt19937 rng(random_device{}());
        shuffle(quizQuest.begin(), quizQuest.end(), rng); //Embaralha o vetor de forma aleatória, sem risco de tirar uma questão repitida

        //Cria a Thread e execulta o timer em paralelo
        thread t(timerQuiz, 120); //120 segundos = 2:00 minutos

        //Loop de Exibição das Perguntas e Alternativas
        for(int i = 0; i < 30; i++) { 
            if (timeOut) break; //Verifica se o tempo acabou
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

            if(score < 0) score = 0; //Evitar que a pontuação fique negativa
            if (timeOut) break; //Se o tempo acabar, encerra
        }
        timeOut = true;
        t.join();
        cleanScreen();

        cout << "\t\t=== Quiz Finalizado ===\n";
        if (score >= 280) easterEgg();
        cout << "Pontuação Final: " << score << '\n';
        cout << "Digite seu nome (Até 3 Letras): ";

        //Salva o Nome e pontuação:
        string name;
        Score player;

        cin >> name;
        cleanBuffer();
            if (name.size() >= 3) name.erase(3); //Se o nome digitado pelo usuário for maior que 3 caractéres, apaga de 3° em diante

        player.name = name;
        player.points = score;
        saveScore(player);
        cleanScreen();

        cout << "\t=== Pontuação Salva ===\n";
        this_thread::sleep_for(chrono::seconds(2));
        cleanScreen();
    }
    else {
        cleanScreen();
        cout << "=== Opção Inválida! ===\n";
        start();
    }
}