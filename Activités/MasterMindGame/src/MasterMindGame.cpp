//============================================================================
// Name        : MasterMindGame.cpp
// Author      : Fermion
// Version     : 1.0
// Copyright   : Fermi and Beri Industry
// Description : Classe principale du jeu; interaction «joueur-console».
//============================================================================

#include "MasterMindGame.h"

#define LENGTH 4

// Construteurs de la classe
MasterMindGame::MasterMindGame() { Reset(); }

int MasterMindGame::GetCodeLength() {return codeCache.length();}	// Obtient la longueur du code caché
int MasterMindGame::GetMaxTries() {return essaieMax;}				// Obtient le nombre d'essaie maximum
int MasterMindGame::GetCurrentTry() {return essaie;}				// Obtient le nombre d'essais actuel
string MasterMindGame::GetAllColors() {return tabCouleurs;}			// Obtient les couleurs possibles
bool MasterMindGame::isGameWon() {return gameWon;}					// Obtient l'état de la partie

// Méthode pour obtenir le status du choix du joueur
EChoixStatus MasterMindGame::GetStatusChoix(string choix) {
	// Si la longueur du choix n'est pas la meme que celle du code caché
	if (choix.length() != GetCodeLength()) { return EChoixStatus::NOT_SAME_LENGTH; }

	// Si le choix du joueur contient des caractères invalides
	if (!isChoixValide(choix)) { return EChoixStatus::NOT_VALID_CARACTER; }

	// Sinon choix valide
	return EChoixStatus::OK;
}


// Méthode pour déterminer si le choix du joueur est valide (contient des caractères valides)
bool MasterMindGame::isChoixValide(string choix) {
	// Boucle sur le choix pour vérifier si ses caracters sont valides
	for (int i = 0; i < choix.length(); i++) {
		// Obtient le ie charactère du choix
		char c = choix[i];
		// Vérifie si le caractère ne fait pas partie des couleurs valides
		if (!map_color[c]) {return false;}
	}
	// Retourne vrai si tous les caractères sont valides
	return true;
}

// Méthode pour mettre à jour le nombre de points
Score MasterMindGame::UpdateScore(string choix) {
	// Augmente le compteur d'essaie
	essaie++;

	// Initialise le score
	Score score;

	bool notUsed[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		notUsed[i] = true;
	}

	// Vérifie le nombre de "white"
	for (int i = 0; i < choix.length(); i++) {
		if (choix[i] == codeCache[i]) {
			score.white++;
			notUsed[i] = false;
		}
	}


	// Boucle sur le choix du joueur
	for (int i = 0; i < choix.length(); i++) {
		// Boucle sur le code cachée
		for (int j = 0; j < choix.length(); j++) {
			// Vérifie si les couleurs sont identiques
			if ((choix[i] == codeCache[j]) && notUsed[j]) {
				score.black++;
				notUsed[j] = false;
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
	codeCacheLongueur = LENGTH;

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
