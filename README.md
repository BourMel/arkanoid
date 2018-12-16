Arkanoid
========

Ce programme est une implémentation en C++ du jeu de casse-briques Arkanoid.

Cette version comprend plusieurs niveaux, lus à partir de fichiers texte, ainsi que l'ensemble des bonus de la version originale.

## Prérequis

Il faut avoir une version de `cmake` relativement récente.
Sur une distribution à jour, un simple `sudo apt install cmake` devrait faire
l'affaire, sinon il faudra compiler depuis les sources.

Il faudra également avoir SDL2 sur sa machine. Pour installer tout le
nécessaire, lancez la commande suivante :
`sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev`

Il est possible d'utiliser Qt Creator pour développer et builder le projet,
mais cela n'est pas obligatoire.


## Niveaux

Un niveau est décrit par un fichier déposé dans le répertoire `levels`.

Il possède une structure de la forme :

```
A B
x x x ... x x x
x x x ... x x x
      ...
x x x ... x x x
x x x ... x x x
```

avec :
  - `A` : le nombre de lignes
  - `B` : le nombre de colonnes
  - `x` : un entier décrivant le type de brique sur la grille,
    avec `0` comme étant un emplacement vide
