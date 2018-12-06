//============================================================================
// Name        : MasterMindGame.h
// Author      : Fermion
// Version     : 1.0
// Copyright   : Fermi and Beri Industry
// Description : En-tête de la classe MasterMindGame.
//============================================================================
#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

// Structure pour contenirs les scores
struct Score {
	int white = 0;	// Bonne couleur, bonne place
	int black = 0;	// Bonne couleur, mauvaise place
};

// Status possible pour un code fourni par le joueur
enum class EChoixStatus {
	OK,
	NOT_SAME_LENGTH,
	NOT_VALID_CARACTER,
	INVALIDE
};

class MasterMindGame {

public:
	/* Constructeur */
	MasterMindGame();

	/* Getters */
	int GetCodeLength();
	int GetMaxTries();
	int GetCurrentTry();
	string GetAllColors();
	bool isGameWon();

	/* Méthodes */
	EChoixStatus GetStatusChoix(string);
	bool isChoixValide(string);
	Score UpdateScore(string);

	void Reset();

// TODO: Compléter les attributs / méthodes privées.
private:
	/* Attributs */
	string codeCache;
	int codeCacheLongueur;
	bool gameWon;
	int essaie;
	int essaieMax;

	char tabCouleurs[6] = {'r', 'b', 'v', 'j', 'm', 'c'};	// Tableau des couleurs permises

};
