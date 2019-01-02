## Code sans commentaire / nom approprié
```cpp
int f(int a) {
    int b = 0;  
    for (int i = 0; i <= a; i++) {
        b = b + i;       
    }
    return b;
}
```

## Code sans commentaire / avec noms appropriés
```cpp
int somme(int n) {
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum = sum + i;
    }
    return sum;
}
```

## Code avec commentaires et noms appropriés
```cpp
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
```


## Boucle for
```cpp
for (int i = 0; i < 10; i++) {
    std::cout << i << std::endl;
}
```

```cpp
for (int i = 0; i < 10; i = i + 2) {
    std::cout << i << std::endl;
}
```

## Boucle while
```cpp
int i = 0;
while( i < 10) {
    std::cout << i << std::endl;
    i++;
}
```

```cpp
int i = 0 ;
while(i < 10) {
    std::cout << i << std::endl;
    i = i + 2;
}
```