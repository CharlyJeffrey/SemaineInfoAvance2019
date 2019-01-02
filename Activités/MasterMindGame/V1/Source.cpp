//============================================================================
// Name        : MasterMindGame.cpp
// Author      : Fermion
// Version     :
// Copyright   : Fermi and Beri Industry
// Description : Version du jeux adapté pour la semaine «Informatique Avancé».
//============================================================================


#include <iostream>
#include "MasterMindGame.h"

using namespace std;

int essaieMax;

// Fonction pour afficher l'introduction au jeu
void PrintIntro();
void PrintOutro();

void PlayGame();

string GetChoixValide();

string choixJoueur;


MasterMindGame MMG;

string allColors = MMG.GetAllColors();

int main() {
	PrintIntro();
	PlayGame();
	PrintOutro();
	return 0;
}


// Fonction pour afficher l'introdution au jeu.
void PrintIntro() {
	cout << "Bienvenue à MasterMindGame!\n";
	cout << "Vous devez déterminer quel est le code de " << MMG.GetCodeLength() << " couleurs en " << MMG.GetMaxTries() << " essaies maximum!\n\n";
}

void PrintOutro() { cout << "À une prochaine fois! Au revoir.\n\n" <<endl;}

void PlayGame() {
	// Reset une partie
	MMG.Reset();
	essaieMax = MMG.GetMaxTries();

	// Initialise le score
	Score score;

	// Boucle de jeu tant que le joueur n'a pas gagné/perdu
	while (!MMG.isGameWon() && MMG.GetCurrentTry() <= essaieMax){
		// Obtient le choix (valide) du joueur
		choixJoueur = GetChoixValide();
		// Détermine le "score" associé au choix
		score = MMG.UpdateScore(choixJoueur);
		// Affiche le score
		cout << "Whites: " << score.white << endl;
		cout << "Blacks: " << score.black << endl;
		cout << endl;
	}

}

// Fonction pour obtenir un choix valide du joueur.
string GetChoixValide() {
	// Initialise un string vide
	string choix = "";
	// Initialise le status du choix à INVALIDE par défaut
	EChoixStatus Status = EChoixStatus::INVALIDE;

	// Demande au jouer de faire un choix tant que le choix fait n'est pas valide
	do {
		int essaie = MMG.GetCurrentTry();

		cout << "Essaie " << essaie << " de " << MMG.GetMaxTries() << " essaies.\n";
		cout << "Entrez votre code de couleurs: ";

		// Obtient le choix du joueur
		getline(cin, choix);

		// Vérifie le status du choix fait
		Status = MMG.GetStatusChoix(choix);
		switch (Status) {
			// Cas longueur incorrecte
			case EChoixStatus::NOT_SAME_LENGTH:
				cout << "La longueur de votre code doit être de " << MMG.GetCodeLength() << " couleurs.\n";
				break;

			// Cas caractère invalide
			case EChoixStatus::NOT_VALID_CARACTER:
				// TODO: Plus propre
				cout << "Votre code doit uniquement contenir les caractères:";
				for (int i = 0; i < allColors.length(); i++) {
					cout << " " << allColors[i];
				}
				cout << ".\n";
				break;
		}
	} while (Status != EChoixStatus::OK);
	return choix;
}

