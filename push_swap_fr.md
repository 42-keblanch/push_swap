# Push_swap

> *Parce que Swap_push sonne moins naturel*

**Résumé :**
Cette activité vous fera trier des données sur une pile, avec un jeu d'instructions limité, en utilisant le moins d'actions possible. Pour réussir, vous devrez manipuler différents types d'algorithmes et choisir la solution la plus adaptée (parmi beaucoup d'autres) pour un tri optimisé des données.

**Cette activité de groupe doit être réalisée par exactement 2 apprenants.**

*Version : 1.2*

---

## Sommaire

- [I. Avant-propos](#i-avant-propos)
- [II. Instructions communes](#ii-instructions-communes)
- [III. Instructions relatives à l'IA](#iii-instructions-relatives-à-lia)
- [IV. Introduction](#iv-introduction)
- [V. Objectifs](#v-objectifs)
- [VI. Partie obligatoire](#vi-partie-obligatoire)
  - [VI.1 Exigences du projet de groupe](#vi1-exigences-du-projet-de-groupe)
  - [VI.2 Les règles](#vi2-les-règles)
  - [VI.3 Exigences algorithmiques](#vi3-exigences-algorithmiques)
    - [VI.3.1 Modèle de complexité et contraintes sur les opérations](#vi31-modèle-de-complexité-et-contraintes-sur-les-opérations)
    - [VI.3.2 Mesure du désordre (obligatoire)](#vi32-mesure-du-désordre-obligatoire)
    - [VI.3.3 Stratégies requises](#vi33-stratégies-requises)
  - [VI.4 Exemple](#vi4-exemple)
  - [VI.5 Le programme « push_swap »](#vi5-le-programme--push_swap-)
    - [VI.5.1 Exemples d'utilisation](#vi51-exemples-dutilisation)
  - [VI.6 Benchmark de performance](#vi6-benchmark-de-performance)
- [VII. Exigences pour le README](#vii-exigences-pour-le-readme)
- [VIII. Partie bonus](#viii-partie-bonus)
  - [VIII.1 Le programme « checker »](#viii1-le-programme--checker-)
- [IX. Rendu et évaluation par les pairs](#ix-rendu-et-évaluation-par-les-pairs)

---

## I. Avant-propos

Il était une fois, dans les terres mystérieuses de l'informatique, un certain Donald Knuth[^1] qui popularisa la notation Grand O pour nous aider à parler de la façon dont les algorithmes passent à l'échelle. Le Grand O, c'est en gros une manière polie de dire : « Ton code va soit tourner vite pour toujours… soit devenir tellement lent que tu auras le temps de te faire un café, de le boire et de vieillir en attendant. »

La légende raconte qu'au début, les programmeurs n'avaient pas le Grand O. Ils lançaient simplement leur code et, si c'était trop long, ils accusaient le matériel. Puis le Grand O est arrivé et a gâché la fête en prouvant mathématiquement que parfois, ton algorithme est juste mauvais — peu importe le nombre de hamsters que tu mets dans la roue du CPU.

Pourquoi est-ce important pour push_swap ? Parce que vous voilà, armé de deux piles et d'une poignée de mouvements étrangement limités, à essayer de trier des nombres plus vite qu'un tri par insertion en manque de sommeil. Le Grand O vous aidera à affronter la dure réalité : une brillante stratégie en O(n log n) survivra toujours à votre maladroite O(n²) quand l'entrée grandit… à moins, bien sûr, que vous choisissiez d'ignorer les maths et de regarder votre nombre d'opérations exploser.

Alors, en concevant vos algorithmes, souvenez-vous : le Grand O n'est pas là pour vous faire peur — il est là pour vous éviter de devenir la personne qui écrit :

```
pb; pa; pb; pa; pb; pa; ...
```

10 000 fois d'affilée, et qui se demande ensuite pourquoi le checker la déteste. Triez malin, pas lentement.

> 💡 Le Grand O n'est pas une taille de pot de pop-corn… mais si c'en était une, O(n log n) resterait le juste milieu.

[^1]: Oui, le type à la barbe glorieuse et à la patience infinie.

---

## II. Instructions communes

- Votre projet doit être écrit en C.
- Votre projet doit respecter la Norme. Si vous avez des fichiers/fonctions bonus, ils sont inclus dans la vérification de la Norme, et vous aurez 0 en cas d'erreur de Norme.
- Vos fonctions ne doivent pas s'arrêter de manière inattendue (segmentation fault, bus error, double free, etc.) sauf en cas de comportement indéfini. Si cela arrive, votre projet sera considéré comme non fonctionnel et recevra 0 lors de l'évaluation.
- Toute mémoire allouée sur le tas doit être correctement libérée lorsque c'est nécessaire. Aucune fuite mémoire ne sera tolérée.
- Si le sujet l'exige, vous devez rendre un `Makefile` qui compile vos fichiers sources vers la sortie demandée avec les flags `-Wall`, `-Wextra` et `-Werror`, en utilisant `cc`. De plus, votre `Makefile` ne doit pas relinker inutilement.
- Votre `Makefile` doit contenir au minimum les règles `$(NAME)`, `all`, `clean`, `fclean` et `re`.
- Pour rendre des bonus, vous devez inclure une règle `bonus` dans votre `Makefile`, qui ajoutera les différents headers, bibliothèques ou fonctions qui ne sont pas autorisés dans la partie principale du projet. Les bonus doivent être placés dans des fichiers `_bonus.{c/h}`, sauf si le sujet précise autre chose. L'évaluation de la partie obligatoire et de la partie bonus se fait séparément.
- Si votre projet autorise l'utilisation de votre `libft`, vous devez copier ses sources et son `Makefile` associé dans un dossier `libft`. Le `Makefile` de votre projet doit compiler la bibliothèque en utilisant son `Makefile`, puis compiler le projet.
- Nous vous encourageons à créer des programmes de test pour votre projet, même si ce travail n'a pas à être rendu et ne sera pas noté. Cela vous permettra de tester facilement votre travail et celui de vos pairs. Ces tests vous seront particulièrement utiles pendant votre soutenance. En effet, pendant la soutenance, vous êtes libre d'utiliser vos tests et/ou ceux du pair que vous évaluez.
- Rendez votre travail sur le dépôt Git assigné. Seul le travail présent dans le dépôt Git sera noté. Si Deepthought est chargé de noter votre travail, cela aura lieu après vos évaluations par les pairs. Si une erreur survient dans une section de votre travail pendant la notation par Deepthought, l'évaluation s'arrêtera.

---

## III. Instructions relatives à l'IA

### ● Contexte

Au cours de votre parcours d'apprentissage, l'IA peut vous aider dans de nombreuses tâches. Prenez le temps d'explorer les différentes capacités des outils d'IA et la manière dont ils peuvent soutenir votre travail. Cependant, abordez-les toujours avec prudence et évaluez les résultats de façon critique. Qu'il s'agisse de code, de documentation, d'idées ou d'explications techniques, vous ne pouvez jamais être totalement sûr que votre question était bien formulée ni que le contenu généré est exact. Vos pairs sont une ressource précieuse pour vous aider à éviter les erreurs et les angles morts.

### ● Message principal

- ☛ Utilisez l'IA pour réduire les tâches répétitives ou fastidieuses.
- ☛ Développez des compétences de prompting — liées au code ou non — qui vous serviront dans votre future carrière.
- ☛ Apprenez comment fonctionnent les systèmes d'IA pour mieux anticiper et éviter les risques, biais et problèmes éthiques courants.
- ☛ Continuez à développer vos compétences techniques et vos soft skills en travaillant avec vos pairs.
- ☛ N'utilisez que du contenu généré par IA que vous comprenez entièrement et dont vous pouvez assumer la responsabilité.

### ● Règles pour les apprenants

- Prenez le temps d'explorer les outils d'IA et de comprendre leur fonctionnement, afin de les utiliser de façon éthique et de réduire les biais potentiels.
- Réfléchissez à votre problème avant de rédiger un prompt — cela vous aide à écrire des prompts plus clairs, plus détaillés et plus pertinents, avec un vocabulaire précis.
- Prenez l'habitude de vérifier, relire, questionner et tester systématiquement tout ce qui est généré par l'IA.
- Cherchez toujours la relecture d'un pair — ne vous fiez pas uniquement à votre propre validation.

### ● Résultats attendus de la phase

- Développer des compétences de prompting à la fois générales et spécifiques à un domaine.
- Augmenter votre productivité grâce à une utilisation efficace des outils d'IA.
- Continuer à renforcer la pensée computationnelle, la résolution de problèmes, l'adaptabilité et la collaboration.

### ● Commentaires et exemples

- Vous rencontrerez régulièrement des situations — examens, évaluations, etc. — où vous devrez démontrer une réelle compréhension. Soyez prêt, continuez à développer vos compétences techniques et relationnelles.
- Expliquer votre raisonnement et débattre avec vos pairs révèle souvent des lacunes dans votre compréhension. Faites de l'apprentissage entre pairs une priorité.
- Les outils d'IA manquent souvent de votre contexte spécifique et ont tendance à fournir des réponses génériques. Vos pairs, qui partagent votre environnement, peuvent offrir des éclairages plus pertinents et plus précis.
- Là où l'IA tend à générer la réponse la plus probable, vos pairs peuvent apporter d'autres perspectives et des nuances précieuses. Appuyez-vous sur eux comme point de contrôle qualité.

✅ **Bonne pratique :**
> Je demande à l'IA : « Comment tester une fonction de tri ? » Elle me donne quelques idées. Je les essaie et je revois les résultats avec un pair. Nous affinons l'approche ensemble.

❌ **Mauvaise pratique :**
> Je demande à l'IA d'écrire une fonction entière et je la copie-colle dans mon projet. Pendant l'évaluation, je ne sais pas expliquer ce qu'elle fait ni pourquoi. Je perds en crédibilité — et j'échoue au projet.

✅ **Bonne pratique :**
> J'utilise l'IA pour m'aider à concevoir un parser. Ensuite, je déroule la logique avec un pair. Nous trouvons deux bugs et le réécrivons ensemble — mieux, plus propre, et entièrement compris.

❌ **Mauvaise pratique :**
> Je laisse Copilot générer le code d'une partie clé de mon projet. Ça compile, mais je ne sais pas expliquer comment il gère les pipes. Pendant l'évaluation, je n'arrive pas à justifier et j'échoue au projet.

---

## IV. Introduction

Le projet Push swap est un projet d'algorithmique très simple et très direct : il faut trier des données.

Vous disposez d'un ensemble de valeurs entières, de 2 piles et d'un ensemble d'opérations pour manipuler les deux piles.

Votre objectif ? Écrire un programme en C appelé `push_swap` qui calcule et affiche sur la sortie standard le plus petit programme, composé d'opérations du *langage Push swap*, qui trie les entiers reçus en arguments.

Facile ?

On verra…

---

## V. Objectifs

Le but de ce projet est de vous faire découvrir la complexité algorithmique de manière très concrète.

Trier des nombres, c'est facile ; les trier rapidement avec seulement deux piles et une poignée de mouvements autorisés, c'est une autre histoire. Trier une liste complètement aléatoire et trier une liste presque triée sont aussi deux choses extrêmement différentes.

Vous verrez rapidement à quel point le choix de l'algorithme peut faire la différence entre une victoire rapide et un défilement interminable d'opérations.

---

## VI. Partie obligatoire

### VI.1 Exigences du projet de groupe

- Ce projet doit être réalisé par **exactement 2 apprenants** travaillant ensemble.
- Les deux apprenants doivent contribuer de manière significative au projet et comprendre tous les algorithmes implémentés.
- Le dépôt doit indiquer clairement les contributions de chacun dans le fichier `README.md`.
- Pendant la soutenance, les deux apprenants doivent être présents et capables d'expliquer n'importe quelle partie du code.
- Le rendu doit inclure les logins des deux apprenants dans le dépôt.

### VI.2 Les règles

- Vous disposez de 2 piles nommées **a** et **b**.
- Au départ :
  - La pile **a** contient une quantité aléatoire de nombres négatifs et/ou positifs, sans doublon.
  - La pile **b** est vide.
- Le but est de trier les nombres par ordre croissant dans la pile **a**. Pour cela, vous disposez des opérations suivantes :

| Opération | Nom | Description |
|---|---|---|
| `sa` | swap a | Intervertit les deux premiers éléments au sommet de la pile **a**. Ne fait rien s'il n'y a qu'un élément ou aucun. |
| `sb` | swap b | Intervertit les deux premiers éléments au sommet de la pile **b**. Ne fait rien s'il n'y a qu'un élément ou aucun. |
| `ss` | — | `sa` et `sb` en même temps. |
| `pa` | push a | Prend le premier élément au sommet de **b** et le met au sommet de **a**. Ne fait rien si **b** est vide. |
| `pb` | push b | Prend le premier élément au sommet de **a** et le met au sommet de **b**. Ne fait rien si **a** est vide. |
| `ra` | rotate a | Décale d'une position vers le haut tous les éléments de la pile **a**. Le premier élément devient le dernier. |
| `rb` | rotate b | Décale d'une position vers le haut tous les éléments de la pile **b**. Le premier élément devient le dernier. |
| `rr` | — | `ra` et `rb` en même temps. |
| `rra` | reverse rotate a | Décale d'une position vers le bas tous les éléments de la pile **a**. Le dernier élément devient le premier. |
| `rrb` | reverse rotate b | Décale d'une position vers le bas tous les éléments de la pile **b**. Le dernier élément devient le premier. |
| `rrr` | — | `rra` et `rrb` en même temps. |

### VI.3 Exigences algorithmiques

Pour imposer une compréhension rigoureuse de la complexité algorithmique (en temps et en espace), vous devez implémenter **quatre stratégies de tri distinctes** et les intégrer à votre programme `push_swap`. Votre programme doit pouvoir sélectionner une stratégie à l'exécution en fonction de la configuration de l'entrée.

#### VI.3.1 Modèle de complexité et contraintes sur les opérations

Toutes les stratégies sont implémentées en C et doivent générer des séquences d'opérations Push_swap pour effectuer le tri. Cela signifie :

- Vos algorithmes en C analysent l'entrée et génèrent la séquence d'opérations appropriée : `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.
- La sortie de votre stratégie est la séquence de ces opérations qui trie la pile.
- Lorsque vous annoncez une classe de complexité, elle doit refléter le coût **mesuré en nombre d'opérations Push_swap générées**, et non la complexité théorique d'un algorithme classique sur tableau.

#### VI.3.2 Mesure du désordre (obligatoire)

Dans ce sujet, le **désordre** (*disorder*) est un nombre entre 0 et 1 qui indique à quel point votre pile **a** initiale est éloignée d'être triée.

Si les nombres sont déjà dans le bon ordre, le désordre vaut 0. S'ils sont dans le pire ordre possible, le désordre vaut 1. Toute valeur intermédiaire signifie que votre pile est partiellement triée, mais encore en désordre.

Pour le calculer, imaginez que vous regardez toutes les paires de nombres possibles dans la pile. Chaque fois qu'un nombre plus grand apparaît avant un plus petit, cette paire compte comme une erreur. Plus il y a d'erreurs, plus le désordre se rapproche de 1.

```
function compute_disorder(stack a):
    mistakes = 0
    total_pairs = 0
    for i from 0 to size(a)-1:
        for j from i+1 to size(a)-1:
            total_pairs += 1
            if a[i] > a[j]:
                mistakes += 1
    return mistakes / total_pairs
```

> ⚠️ Vous devez mesurer le désordre **avant** d'effectuer le moindre mouvement.

#### VI.3.3 Stratégies requises

1. **Algorithme simple (O(n²))**
   Implémentez au moins un algorithme de base de la classe O(n²). Exemples :
   - Adaptation du tri par insertion
   - Adaptation du tri par sélection
   - Adaptation du tri à bulles
   - Méthodes simples d'extraction du min/max

2. **Algorithme moyen (O(n√n))**
   Implémentez au moins un algorithme de la classe O(n√n). Exemples :
   - Tri par chunks (division en √n chunks)
   - Méthodes de partitionnement par blocs
   - Adaptations du tri par paquets (bucket sort) avec √n paquets
   - Stratégies de tri par plages de valeurs

3. **Algorithme complexe (O(n log n))**
   Implémentez au moins un algorithme de la classe O(n log n). Exemples :
   - Adaptation du radix sort (LSD ou MSD)
   - Adaptation du tri fusion utilisant deux piles
   - Adaptation du tri rapide avec partitionnement de piles
   - Adaptation du tri par tas
   - Approches par arbre de Fenwick (Binary Indexed Tree)

4. **Algorithme adaptatif personnalisé (conçu par vous)**
   Concevez une stratégie adaptative qui choisit différentes méthodes internes selon le désordre mesuré. Vous n'êtes contraint à aucun algorithme nommé en particulier ; les techniques internes sont entièrement à votre choix. Cependant, votre conception doit respecter les objectifs de complexité suivants pour chaque régime (dans le modèle d'opérations Push_swap) :

   | Régime | Condition | Complexité exigée |
   |---|---|---|
   | Désordre faible | `disorder < 0.2` | O(n²) |
   | Désordre moyen | `0.2 ≤ disorder < 0.5` | O(n√n) |
   | Désordre élevé | `disorder ≥ 0.5` | O(n log n) |

   Vous devez documenter dans votre dépôt (par ex. dans le `README.md`) la justification de vos seuils, les techniques internes utilisées dans chaque régime, et un bref argument de complexité (bornes supérieures) en temps et en espace dans le modèle Push_swap.

### VI.4 Exemple

Pour illustrer l'effet de certaines de ces opérations, trions une liste d'entiers aléatoires. Dans cet exemple, on considère que les deux piles grandissent par la droite.

```
----------------------------------------------------------------------------
Init a and b:
2
1
3
6
5
8
_ _
a b
----------------------------------------------------------------------------
Exec sa:
1
2
3
6
5
8
_ _
a b
----------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
----------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
----------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
----------------------------------------------------------------------------
```

Les entiers de la pile **a** sont triés en 12 opérations. Pouvez-vous faire mieux ?

### VI.5 Le programme « push_swap »

| | |
|---|---|
| **Nom du programme** | `push_swap` |
| **Fichiers à rendre** | `Makefile`, `*.h`, `*.c` |
| **Makefile** | `NAME`, `all`, `clean`, `fclean`, `re` |
| **Arguments** | pile a : une liste d'entiers |
| **Fonctions externes** | `read`, `write`, `malloc`, `free`, `exit`<br>`ft_printf` ou tout équivalent codé PAR VOUS |
| **Libft autorisée** | Oui |
| **Description** | Trier des piles |

Votre projet doit respecter les règles suivantes :

- Vous devez rendre un `Makefile` qui compile vos fichiers sources. Il ne doit pas relinker.
- Les variables globales sont interdites.
- Vous devez écrire un programme nommé `push_swap` qui prend en arguments :
  - La pile **a** sous forme de liste d'entiers (le premier argument est le sommet de la pile).
  - Un sélecteur de stratégie optionnel :
    - `--simple` — Force l'utilisation de votre algorithme en O(n²).
    - `--medium` — Force l'utilisation de votre algorithme en O(n√n).
    - `--complex` — Force l'utilisation de votre algorithme en O(n log n).
    - `--adaptive` — Force l'utilisation de votre algorithme adaptatif basé sur le désordre. **C'est le comportement par défaut si aucun sélecteur n'est donné.**
- Le programme doit afficher la plus petite liste d'opérations Push_swap possible pour trier la pile **a**, le plus petit nombre étant au sommet.
- Les opérations doivent être séparées par un `\n` et rien d'autre.
- La classe de complexité annoncée pour chaque algorithme doit être valide dans ce modèle.
- La sélection de stratégie doit fonctionner pour toutes les entrées valides. Chaque flag de sélection doit fonctionner quelles que soient la taille de l'entrée et son désordre.
- Si aucun paramètre n'est fourni, le programme ne doit rien afficher et rendre la main.
- En cas d'erreur, il doit afficher `"Error"` suivi d'un `\n` sur la **sortie d'erreur**. Les erreurs incluent par exemple : des arguments qui ne sont pas des entiers, des entiers hors de la plage valide, ou des doublons.
- Votre binaire doit embarquer les quatre stratégies (Simple O(n²), Moyenne O(n√n), Complexe O(n log n) et Adaptative). Le nom de la stratégie sélectionnée et sa classe de complexité doivent être disponibles en mode `--bench`.
- Le **mode benchmark** optionnel (`--bench`) doit afficher, après le tri :
  - Le `disorder` calculé (en %, avec deux décimales).
  - Le nom de la stratégie utilisée et sa classe de complexité théorique.
  - Le nombre total d'opérations.
  - Le nombre de chaque type d'opération (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).

  La sortie du benchmark doit être envoyée sur `stderr` et n'apparaître que lorsque le flag est présent.

#### VI.5.1 Exemples d'utilisation

*Notation : les lignes préfixées par `[bench]` représentent les messages affichés par le mode benchmark optionnel (sur `stderr`). Le flux d'opérations reste sur `stdout`.*

```console
$> ./push_swap 2 1 3 6 5 8
ra
pb
rra
pb
pb
ra
pb
ra
pb
pb
pa
pa
pa
pa
pa
pa
```

**Sélection par défaut (`--adaptive`) et nombre d'opérations :**

```console
$> ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l
13
```

**Forcer la stratégie simple (O(n²)) :**

```console
$> ./push_swap --simple 5 4 3 2 1
rra
pb
rra
pb
rra
pb
ra
pb
pb
pa
pa
pa
pa
pa
```

**Forcer la stratégie complexe (O(n log n)) et vérifier avec le checker :**

```console
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK
```

**push_swap avec une grande entrée :**

```console
$> shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
6784
$>
```

**Lancer avec le benchmark activé ; masquer les opérations et n'afficher que les métriques :**

```console
$> shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
OK
$> cat bench.txt
[bench] disorder:  49.93%
[bench] strategy:  Adaptive / O(n√n)
[bench] total_ops:  7997
[bench] sa:  0  sb:  0  ss:  0  pa:  500  pb:  500
[bench] ra:  4840  rb:  1098  rr:  0  rra:  0  rrb:  1059  rrr:  0
```

**Envoyer les opérations au checker tout en enregistrant le benchmark dans un fichier :**

```console
$> ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_linux $ARG
OK
$> cat bench.txt
[bench] disorder:  40.00%
[bench] strategy:  Adaptive / O(n√n)
[bench] total_ops:  13
[bench] sa:  0  sb:  0  ss:  0  pa:  5  pb:  5
[bench] ra:  2  rb:  1  rr:  0  rra:  0  rrb:  0  rrr:  0
```

**Exemples de gestion d'erreurs :**

```console
$> ./push_swap --adaptive 0 one 2 3
Error
$> ./push_swap --simple 3 2 3
Error
```

### VI.6 Benchmark de performance

Pour valider ce projet, vous devez atteindre certains objectifs de performance avec un nombre minimal d'opérations :

| Taille de l'entrée | Validation (minimum) | Bonne performance | Excellente performance |
|---|---|---|---|
| 100 nombres aléatoires | < 2000 opérations | < 1500 opérations | < 700 opérations |
| 500 nombres aléatoires | < 12000 opérations | < 8000 opérations | < 5500 opérations |

Tout cela sera vérifié pendant votre évaluation à l'aide du checker fourni.

---

## VII. Exigences pour le README

Un fichier `README.md` doit être présent à la racine de votre dépôt Git. Son but est de permettre à toute personne qui ne connaît pas le projet (pairs, staff, recruteurs, etc.) de comprendre rapidement de quoi il s'agit, comment le lancer et où trouver plus d'informations sur le sujet.

Le `README.md` doit contenir au minimum :

- La toute première ligne doit être en italique et indiquer : *This project has been created as part of the 42 curriculum by \<login1\>[, \<login2\>[, \<login3\>[...]]].*
- Une section **« Description »** qui présente clairement le projet, y compris son objectif et un bref aperçu.
- Une section **« Instructions »** contenant toutes les informations utiles sur la compilation, l'installation et/ou l'exécution.
- Une section **« Resources »** listant les références classiques liées au sujet (documentation, articles, tutoriels, etc.), ainsi qu'une description de la façon dont l'IA a été utilisée — en précisant pour quelles tâches et quelles parties du projet.

> ➠ Des sections supplémentaires peuvent être exigées selon le projet (par ex. exemples d'utilisation, liste des fonctionnalités, choix techniques, etc.).

Tout ajout requis sera explicitement listé ci-dessous.

- Une explication détaillée et une justification des algorithmes choisis pour ce projet doivent également être incluses.

> ℹ️ L'anglais est recommandé ; vous pouvez aussi utiliser la langue principale de votre campus.

---

## VIII. Partie bonus

Vu sa simplicité, ce projet offre peu de possibilités de fonctionnalités supplémentaires. Mais pourquoi ne pas créer votre propre checker ?

> 💡 Grâce au programme checker, vous pourrez vérifier si la liste d'opérations générée par le programme push_swap trie réellement la pile correctement.

> ⚠️ La partie bonus ne sera évaluée que si la partie obligatoire est **parfaite**. Parfaite signifie que la partie obligatoire a été entièrement réalisée et fonctionne sans erreur. Pour ce projet, cela implique de valider tous les benchmarks sans exception. Si vous n'avez pas rempli TOUTES les exigences obligatoires, votre partie bonus ne sera pas évaluée du tout.

### VIII.1 Le programme « checker »

| | |
|---|---|
| **Nom du programme** | `checker` |
| **Fichiers à rendre** | `*.h`, `*.c` |
| **Makefile** | `bonus` |
| **Arguments** | pile a : une liste d'entiers |
| **Fonctions externes** | `read`, `write`, `malloc`, `free`, `exit`<br>`ft_printf` ou tout équivalent codé PAR VOUS |
| **Libft autorisée** | Oui |
| **Description** | Exécuter les opérations de tri |

- Écrivez un programme nommé `checker` qui prend en argument la pile **a** sous forme de liste d'entiers. Le premier argument doit être au sommet de la pile (attention à l'ordre). Si aucun argument n'est donné, il s'arrête sans rien afficher.
- Il attend ensuite et lit des opérations sur l'entrée standard, chaque instruction étant suivie de `'\n'`. Une fois toutes les instructions lues, le programme doit les exécuter sur la pile reçue en argument.
- Si, après l'exécution de ces instructions, la pile **a** est bien triée et la pile **b** est vide, le programme doit afficher `"OK"` suivi d'un `'\n'` sur la sortie standard.
- Dans tous les autres cas, il doit afficher `"KO"` suivi d'un `'\n'` sur la sortie standard.
- En cas d'erreur, vous devez afficher `"Error"` suivi d'un `'\n'` sur la **sortie d'erreur**. Les erreurs incluent par exemple : certains arguments ne sont pas des entiers, certains arguments dépassent la taille d'un int, il y a des doublons, une instruction n'existe pas et/ou est mal formatée.

```console
$> ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$> ./checker 3 2 1 0
sa
rra
pb
KO
$> ./checker 3 2 one 0
Error
$> ./checker "" 1
Error
$>
```

> ℹ️ Vous N'êtes PAS obligé de reproduire exactement le comportement du binaire fourni. La gestion des erreurs est obligatoire, mais c'est à vous de décider comment parser les arguments.

---

## IX. Rendu et évaluation par les pairs

Rendez votre travail sur votre dépôt Git comme d'habitude. Seul le travail présent dans votre dépôt sera évalué pendant la soutenance. N'hésitez pas à vérifier deux fois les noms de vos fichiers pour vous assurer qu'ils sont corrects.

**Exigences de rendu pour le projet de groupe :**

- Les deux apprenants doivent apparaître comme contributeurs dans le dépôt.
- Le `README.md` doit documenter clairement les contributions des deux apprenants.
- Les deux apprenants doivent être présents lors de la soutenance.
- Chaque apprenant doit être capable d'expliquer et de défendre n'importe quelle partie du code.

Pendant l'évaluation, une brève **modification du projet** peut parfois être demandée. Il peut s'agir d'un léger changement de comportement, de quelques lignes de code à écrire ou réécrire, ou d'une fonctionnalité facile à ajouter.

Même si cette étape ne s'applique pas à tous les projets, vous devez y être préparé si elle est mentionnée dans le barème d'évaluation.

Cette étape sert à vérifier votre compréhension réelle d'une partie précise du projet. La modification peut être réalisée dans l'environnement de développement de votre choix (par ex. votre configuration habituelle), et elle doit pouvoir être faite en quelques minutes — sauf si un délai précis est défini dans le cadre de l'évaluation.

On peut par exemple vous demander de faire une petite mise à jour d'une fonction ou d'un script, de modifier un affichage, ou d'adapter une structure de données pour stocker une nouvelle information, etc.

Les détails (périmètre, cible, etc.) seront précisés dans le barème d'évaluation et peuvent varier d'une évaluation à l'autre pour un même projet.
