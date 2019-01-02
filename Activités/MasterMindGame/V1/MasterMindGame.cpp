//============================================================================
// Name        : MasterMindGame.cpp
// Author      : Fermion
// Version     : 1.0
// Copyright   : Fermi and Beri Industry
// Description : Classe principale du jeu; interaction «joueur-console».
//============================================================================

#include "MasterMindGame.h"

map<char, bool> map_color;

// Construteurs de la classe
MasterMindGame::MasterMindGame() { Reset(); }

int MasterMindGame::GetCodeLength() {return codeCache.length();}
int MasterMindGame::GetMaxTries() {return essaieMax;}
int MasterMindGame::GetCurrentTry() {return essaie;}
string MasterMindGame::GetAllColors() {return tabCouleurs;}
bool MasterMindGame::isGameWon() {return gameWon;}

// Méthode pour obtenir le status du choix du joueur
EChoixStatus MasterMindGame::GetStatusChoix(string choix) {
	// Si la longueur du choix n'est pas la meme que celle du code caché
	if (choix.length() != GetCodeLength()) { return EChoixStatus::NOT_SAME_LENGTH; }

	// Si le choix du joueur contient des caractères invalides
	if (!isChoixValide(choix)) { return EChoixStatus::NOT_VALID_CARACTER; }
	return EChoixStatus::OK;
}


// Méthode pour déterminer si le choix du joueur
bool MasterMindGame::isChoixValide(string choix) {
	// Boucle sur le choix pour vérifier si ses caracters sont valides
	for (int i = 0; i < choix.length(); i++) {
		char c = choix[i];
		if (!map_color[c]) {return false;}
	}
	return true;
}

// Méthode pour mettre à jour le nombre de points
Score MasterMindGame::UpdateScore(string choix) {
	// Augmente le compteur d'essaie
	essaie++;

	// Initialise le score
	Score score;

	// Boucle sur le choix du joueur
	for (int i = 0; i < choix.length(); i++) {
		// Boucle sur le code cachée
		for (int j = 0; j < choix.length(); j++) {
			// Vérifie si les couleurs sont identiques
			if (choix[i] == codeCache[j]) {
				// Vérifie si elles sont à la meme position
				if (i == j) {
					// Augmente le compteur
					score.white++;
				} else {
					// Augmente le compteur
					score.black++;
				}
			}
		}
	}

	// Vérifie si le joueur à gagner
	if (score.white == choix.length()) {
		gameWon = true;
	} else {
		gameWon = false;
	}
	return score;
}

// Fonction pour réinitialiser le jeu au démarage d'une nouvelle partie
void MasterMindGame::Reset() {
	// TODO: Variation des attributs selon la difficulté

	// Initialise le mapping des couleurs
	for (int i = 0; i < 6; i++) {
		char c = tabCouleurs[i];
		map_color[c] = true;
	}

	// Initialise la longueur du code caché
	// TODO: Variable selon la difficulté
	codeCacheLongueur = 4;

	// Génère un nouveau code caché
	codeCache = "";
	for (int i = 0; i < codeCacheLongueur; i++) {
		char c = tabCouleurs[rand() % 6];
		codeCache.append(string(1, c));
	}

	// Initialise les attributs reliés aux essaies
	essaie = 1;
	essaieMax = 8;
	gameWon = false;
}
