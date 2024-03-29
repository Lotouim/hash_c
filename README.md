# Reconnaitre un type de hash en C

Dans ce projet, j'ai pu créer un programme en C qui permet de détecter le type de hash utilisé.

## Compilation du programme

Pour ce projet nous allons utiliser le compilateur GCC.

Pour l'installer sous Windows nous pouvons suivre cette vidéo : https://www.youtube.com/watch?v=y-i96kqT53A&t=780s

Les étapes à suivres sont les suivantes : **ATTENTION IL VOUS FAUDRA LES DROITS ADMINISTRATEURS POUR FAIRE CETTE INSTALLATION**

- Se rendre sur le site : https://winlibs.com/
- Descendre jusqu'à la section **Download**
- Télécharger l'archive ZIP la plus récente. Attention, il y a deux versions de cette archive : **Win32/Win64** et **without LLVM/Clang/LLD/LLDB**. Ici la version **without LLVM/Clang/LLD/LLDB** sera suffisante.
- Extraire le fichier sur le bureau pour plus de simplicité.
- Appuyé sur la touche **Window** et tapé : Variables d'environnement
- Appuyé sur le bouton : **Variables d'environnement**
- Dans le rectangle du bas, sélectionné la variable système : **Path**
- Copier le chemin d'accès aux fichier bin (Exemple : C:\\Users\\Damian\\Desktop\\mingw32\\bin)
- Cliquer sur le bouton : **Nouveau**
- Coller le chemin d'accès
- Valider et fermer toutes les fenêtres.
- Ouvrir un powershell et tapez les commandes suivantes :

Ensemble d'outils C :

```
gcc -v
```

Compilateur C/C++ :

```
g++ -v
```

Débogueur C :

```
gdb -v
```

Si les versions de ces outils apparaissent correctement alors les outils sont utilisables.

## Utilisation du compilateur

Pour vérifier que tout soit correctement installé nous allons essayer un petit programme : **Attention il faut enregistrer le programme en ".c" car le programme est en C**

```cpp
#include <stdio.h>

int main()
{
    printf("Hello Wolrd !");
    return 0;
}
```

Maintenant que nous avons notre code, il faut le compiler afin d'obtenir un fichier exécutable.
Pour cela, il faut ouvrir un powershell et taper les commandes suivantes :

**Attention à bien se mettre dans le dossier où se situe notre programme en C avant de lancer les commandes.**

```
g++ -std=c++17 -Wall -Wextra -Werror <Nom_du_fichier_que_l_on_veut_compiler> -o <Nom_de_l_executable>
```

- "-std=c++17" : version du compilateur utilisée.
- "-Wall" : permet d'activer la plupart des avertissements, utile en cas d'erreurs.
- "-Wextra" : permet d'activer d'autres avertissements
- "-Werror" : permet de traiter tous les avertissements comme des erreurs. Avec cette option, si un avertissement est détecté, la compilation sera interrompue.

**Les options -Wall, -Wextra et -Werror ne sont pas obligatoires mais c'est une bonne habitudes à prendre.**

S'il n'y a pas d'erreurs, nous devrions trouver un fichier exécutable dans le même dossier que votre fichier code.

Pour l'exécuter il ne reste plus qu'à taper le nom de l'exécutable, appuyer sur TAB puis sur ENTRER.

Pour notre programme cela va donner :

```
PS C:\Users\Damian\Nextcloud\Guardia\Projet 8\Code> .\<Nom_de_l_executable>.exe
```

Résultats :

```
Hello World !
```

A partir de là vous pourrez compiler le programme **hash.c** avec la commande suivante :

```
g++ -std=c++17 -Wall -Wextra -Werror .\hash.c -o hash.exe
```

Vous obtiendrez votre exécutable **hash.exe**