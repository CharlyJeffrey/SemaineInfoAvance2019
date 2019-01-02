int f(int a) {
    int b = 0;  
    for (int i = 0; i <= a; i++) {
        b = b + i;       
    }
    return b;
}

int somme(int n) {
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum = sum + i;
    }
    return sum;
}


// Fonction pour obtenir la somme de tous les nombres de 0 à n
int somme(int n) {
    // Initialise la variable pour stocker la somme
    int sum = 0;
    // Boucle sur tous les nombres de 0 à n
    for (int i = 0; i <= n; i++) {
        // Augmente la valeur de 'sum' de 'i'
        sum = sum + i;
    }
    // Retourne la valeur finale de sum
    return sum;
}