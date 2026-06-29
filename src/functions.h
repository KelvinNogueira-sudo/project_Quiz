#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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

struct Quest {
    string text;
    vector<string> altern;
    int answer;
};

struct Score {
    string name;
    int points;

    bool operator<(const Score& other) const {
        return points > other.points;
    }
};

void cleanScreen();
void cleanBuffer();
void timerQuiz(int seconds);
void printLogo();
void printScore();
void printStart();
void showInfo();
void easterEgg();
void saveScore(Score p);
void loadScore(const string& archive);
vector<Quest> loadQuest(const string& archive);
void start();

#endif