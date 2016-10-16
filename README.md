# PdStarterKit

Ce répertoire fourni une architecture de base pour écrire des objets [Pure Data](https://puredata.info/)

## Installation

voir installation de [cmake, Xcode/Visual Studio...](https://github.com/paccpp/paccpp/blob/master/setup/readme.md)

---

Vous aurez aussi besoin de `git` pour pouvoir cloner ce répertoire

- Vérifiez que git est installé en tapant : `git --version`
- Si vous ne l'avez pas :
  - Mac : télécharger et installer [git-osx-installer](https://sourceforge.net/projects/git-osx-installer/)
  - Windows : télécharger et installer [git-for-windows](https://git-for-windows.github.io/)
  - Linux : taper `yum install git` ou `apt-get install git`.

Vous pouvez desormais utiliser `git` en ligne de commande, ou passer par un client git en installant par exemple [SourceTree](https://www.sourcetreeapp.com/) sur Mac et Windows.

---

- Créer un répertoire vide en local (ex. "MyPdObjects").

- Dans le terminal ou la console, se rendre dans ce répertoire en tapant:

```shell
cd "path_to_my_folder"
```

- Si vous utilisez un client git, cloner ce dépôt grâce à l'interface graphique, sinon clonez ce dépôt dans le répertoire local que vous venez de créer en tapant en ligne de commande :

```shell
git clone --recursive https://github.com/paccpp/{name_of_this_repository}.git .
```

4. Créer ensuite un dossier _build_ en tapant : `mkdir build` et s'y rendre `cd build`.

6. Vous pouvez maintenant générer des projets pour votre environnement :

#### Mac

Pour générer un projet Xcode taper :
- `cmake -G Xcode ..`
- Ouvrez le projet Xcode généré dans le dossier _build_ pour compiler à partir de l'IDE, ou compiler directement le projet en tapant `cmake --build .`

Répéter ces commandes à chaque modification du projet (ajout, suppression de fichier, dossier).

#### Windows

La commande exacte à taper va dépendre de la version de Visual Studio que vous avez installée.
- Taper `cmake --help` pour obtenir la liste des options disponibles.
- Si vous avez par exemple Visual Studio 2013, la commande à taper ressemblera à :
  * 32 bit: `cmake -G "Visual Studio 12" ..`
  * 64 bit: `cmake -G "Visual Studio 12 Win64" -DWIN64:Bool=True ..`

Quand le projet est généré, vous pouvez ouvrir le fichier .sln avec Visual Studio.

Répéter ces commandes à chaque modification du projet (ajout, suppression de fichier, dossier).

#### Makefiles

Pour compiler directement en ligne de commandes :
- tapper `cmake ..` puis `cmake --build .` ou `make .`

## Pour ajouter un external:

- Dupliquer un dossier existant dans le répertoire _source/projects/_
- renommer le dossier copié ex : _my.objectname_tilde_
- Modifier ensuite le nom de l'external dans le fichier 'CMakeLists.txt' en remplaçant le nom de l'ancien objet par le nouveau (ex: _my.objectname~_) à la ligne suivante :

```cmake
set(PRODUCT_NAME my.objectname~)
```

- Générer à nouveau le projet en utilisant la commande cmake dans le dossier _build_ puis ouvrez le pour modifier le code source et compiler.

  Les externals compilés se trouvent dans le répertoire _externals_.

## Crédits

- [pure-data](https://github.com/pure-data/pure-data) => @millerpuckette and others
- [pd.build](https://github.com/pierreguillot/pd.build) => @pierreguillot
