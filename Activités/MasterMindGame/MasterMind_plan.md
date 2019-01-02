# MasterMind: Plan

## Règlements:

* Une partie se joue sur un certain nombre de manches.
* Deux joueurs jouent l'un contre l'autre (__codemaker__ & __codebreaker__).
* Le __codemaker__ choisi sa chaine constituée de 4 couleurs parmis un choix de 6.
* Le __codebreaker__ doit déterminer la chaine cachée en 8/10/12 essaies.
* Pour chaque tentative, le __codemaker__ donne le nombre de couleurs correctement
  dévinées (position+couleur) et le nombre de couleurs partiellement devinées 
  (couleur uniquement).
* Si le __codebreaker__ réussi à deviner la chaine du __codemaker__, il gagne la manche.

## Implémentation:
    
* __codemaker__: 
    Le __codemaker__ sera simplement l'ordinateur et choisiera sa chaine 
    de manière aléatoire à chaque début de manche.        
* __codebreaker__: 
    Le __codebreaker__ sera le joueur (humain) qui joue au jeu, tout simplement.
* Interaction _Joueur-Console_:
    L'interaction entre le joueur (__codebreaker__) et l'ordinateur (__codemaker__) 
    se fera via la classe __MasterMindGame__ qui gèrera toutes les interactions possibles. 
    Elle sera responsable de génèrer la chaine aléatoire, d'accepter et de vérifier
    la validité de la tentative du joueur et de lui retourner le score associé. 
    La classe peut être vu comme le _maître du jeu_ qui s'occupe du bon fonctionnement d'une partie.


