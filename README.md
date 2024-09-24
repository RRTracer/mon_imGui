# Mon Git pour Mon ImGui du cour

## Introduction :

    Dans ce Git, je vais placer mon code , mon MakeFile, mes documentations, qui me sont nécessaire dans le cours.

    En gros le cours a pour but de nous faire apprendre et initer à ImGui , une interface graphique puissante qui nous sera utile surement en projet.

    Je ne suis pas dévellopeur mais juste étudiant qui essaye d'apprendre aussi de mon coter.

## Explication de mon MakeFile

(Mon Makefile a été ecrit par moi même mais j'ai fais générer l'explication par l'ia)


Voici l'explication ligne par ligne du Makefile, sans le code :

---

1. **CXX = g++**  
   Cette ligne définit la variable `CXX`, qui représente le compilateur à utiliser. Ici, c'est le compilateur `g++`, utilisé pour les programmes en C++.

2. **CXXFLAGS = -std=c++11 -g -Wall `sdl2-config --cflags` -Iinclude**  
   Cette ligne configure les options de compilation via la variable `CXXFLAGS`.  
   - `-std=c++11` : Spécifie l'utilisation de la norme C++11.
   - `-g` : Active la génération d'informations de débogage.
   - `-Wall` : Active tous les avertissements lors de la compilation pour repérer les erreurs potentielles.
   - `` `sdl2-config --cflags` `` : Exécute la commande `sdl2-config` pour obtenir les drapeaux de compilation nécessaires à la bibliothèque SDL2.
   - `-Iinclude` : Indique au compilateur d'inclure le répertoire `include` pour chercher les fichiers d'en-tête.

3. **LDFLAGS = `sdl2-config --libs` -lGL -lGLEW**  
   Cette ligne définit les options d'édition de liens via la variable `LDFLAGS`.  
   - `` `sdl2-config --libs` `` : Exécute la commande `sdl2-config` pour récupérer les bibliothèques nécessaires à SDL2.
   - `-lGL` : Lie la bibliothèque OpenGL.
   - `-lGLEW` : Lie la bibliothèque GLEW (OpenGL Extension Wrangler Library).

4. **SRC_DIR = source**  
   Déclare la variable `SRC_DIR`, représentant le répertoire où se trouvent les fichiers source du projet (`source`).

5. **OBJ_DIR = obj**  
   Déclare la variable `OBJ_DIR`, représentant le répertoire où les fichiers objets (les fichiers intermédiaires générés à partir des fichiers source) seront placés (`obj`).

6. **BUILD_DIR = build**  
   Définit le répertoire de sortie final du projet, où sera placé l'exécutable compilé (`build`).

7. **SOURCES = $(wildcard $(SRC_DIR)/*.cpp)**  
   Utilise la fonction `wildcard` pour lister tous les fichiers `.cpp` du répertoire `source`. Tous ces fichiers seront stockés dans la variable `SOURCES`.

8. **OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))**  
   Utilise la fonction `patsubst` pour convertir la liste des fichiers source en fichiers objets correspondants. Pour chaque fichier source `source/nom.cpp`, on obtient un fichier objet `obj/nom.o`.

9. **EXECUTABLE = $(BUILD_DIR)/out**  
   Définit le nom de l'exécutable final, qui sera généré dans le répertoire `build` avec le nom `out`.

10. **all: $(EXECUTABLE)**  
    C'est la règle principale. Elle indique que la cible par défaut du Makefile est l'exécutable, qui dépend des fichiers objets. Quand on tape `make`, cette règle est exécutée.

11. **$(EXECUTABLE): $(OBJECTS)**  
    Cette règle précise que pour générer l'exécutable, il faut d'abord compiler tous les fichiers objets. Le symbole `$@` représente ici le fichier cible (`$(EXECUTABLE)`).

12. **$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)**  
    C'est la commande pour générer l'exécutable à partir des fichiers objets. Elle utilise le compilateur défini dans `CXX`, et les options de lien définies dans `LDFLAGS`.

13. **@echo "Compilation terminée avec succès ! L'exécutable est disponible dans $(BUILD_DIR)/out."**  
    Après avoir compilé avec succès, un message est affiché pour informer l'utilisateur que la compilation est terminée et que l'exécutable est disponible.

14. **$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp**  
    Cette règle décrit la manière de compiler chaque fichier source en fichier objet. Pour chaque fichier `source/nom.cpp`, elle génère `obj/nom.o`.

15. **$(CXX) $(CXXFLAGS) -c $< -o $@**  
    C'est la commande qui compile un fichier source (`$<` désigne le fichier source) en fichier objet (`$@` désigne le fichier cible).

16. **clean:**  
    C'est une règle pour supprimer les fichiers objets et l'exécutable généré. Elle est généralement utilisée pour « nettoyer » le projet.

17. **rm -rf $(OBJ_DIR)/*.o $(EXECUTABLE)**  
    Cette commande supprime tous les fichiers objets dans le répertoire `obj` ainsi que l'exécutable final.



## Description des envie de continuité

En gros j'y vais étape par étape afin de au final créé une interface graphique qui capte le signal réseau , le mets en graphique pour voir l'utilisation celon les gigas . 

Arès je voudrais pouvoir integrer un terminal dedans afin d'au final créé un ide parfait pour l'education et l'étude du BUS série.


