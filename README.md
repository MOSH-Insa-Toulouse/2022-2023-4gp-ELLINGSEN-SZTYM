# 2022-2023-4gp-ELLINGSEN-SZTYM

Dans le cadre de l’unité de formation “Du capteur au banc de test” suivi en 4ème année par les étudiants de Génie Physique de l’INSA de Toulouse, nous avons réalisé un capteur à jauge de contrainte low-tech à base de crayon graphite. Ce projet s’appuie sur l’ouvrage : “Pencil Drawn Strain Gauges and Chemiresistors on Paper”, écrit par : Cheng-Wei Lin, Zhibo Zhao, Jaemyung Kim & Jiaxing Huang. 

D’après cet article scientifique, le capteur créé simplement à partir de papier et d’un dépôt de crayon à papier, produirait une variation de résistance en lui appliquant une contrainte mécanique de type tension et compression. Cette variation de résistance s’explique par la variation de la distance entre les particules de graphites présentes. 

L’esprit de cette unité de formation est tournée vers l’Open Source, c’est pourquoi toutes les ressources nécessaires à la réalisation de ce projet sont disponibles dans notre dossier.  

Vous retrouverez à la suite de cette introduction, toutes les étapes de réalisation de ce projet, du design du circuit analogique à la caractérisation du capteur. 

## Sommaire

1. [Description du projet et livrables attendus](#description-du-projet-et-livrables-attendus)
2. [Matériel nécessaire](#matériel-nécessaire)
3. [Simulations sous LTSpice](#simulations-sous-ltspice)
4. [KiCad](#kicad)
   1. [Symboles, empreintes et visualisation 3D des composants](#symboles-empreintes-et-visualisation-3d-des-composants)
   2. [Schématique](#schématique)
   3. [PCB](#pcb)
   4. [Visualisation 3D](#visualisation-3d)
5. [Fabrication du Shield](#fabrication-du-shield)
6. [Arduino](#arduino)
7. [Application Bluetooth](#application-bluetooth)
8. [Tests et résultats](#tests-et-résultats)
   1. [Banc de test](#banc-de-test)
   2. [Résultats obtenus](#résultats-obtenus)
   3. [Analyse des résultats](#analyse-des-résultats)
   4. [Pistes d'améliorations](#pistes-daméliorations)
9. [Datasheet](#datasheet)
10. [Contacts](#contacts)

## Description du projet et livrables attendus

## Matériel nécessaire
- x2 résistances 100kΩ
- x2 résistances 1kΩ
- x1 résistance 10kΩ
- x1 capacité 1 μF
- x1 capacité 1 nF 
- x1 amplificateur opérationnel LTC 1050
- x1 module Bluetooth HC-05
- x1 écran OLED-2864 
- x1 flexsensor et 1 résistance de 33kΩ (en bonus)
- x1 feuille de papier et un crayon à papier


## Simulations sous LTSpice

## KiCad
Le logiciel Kicad a été essentiel dans la réalisation de schémas électriques et la modélisation de notre PCB avant la création du shield. Ce processus implique plusieurs étapes. Tout d'abord, nous avons créé les empreintes de tous les composants que nous souhaitions incorporer, puis défini les connexions entre eux ainsi qu'avec la carte Arduino. Ensuite, nous avons édité le PCB en suivant les consignes imposées, avant de conclure par la visualisation en 3D du PCB complet.

### Symboles, empreintes et visualisation 3D des composants
Afin de réaliser le schéma du circuit, nous avons créé une librairie d'empreintes pour les composants qui n'étaient pas disponibles dans les librairies intégrées au logiciel. Ensuite, nous avons établi les connexions entre les composants et la carte Arduino une fois que tous les éléments ont été schématisés.

- Capteur graphite

![Imgur](https://i.imgur.com/xKIDfKd.png)


- Flexsensor
- LTC1050
- Module Bluetooth
- Écran OLED

### Schématique

### PCB
Ensuite, nous avons positionné les composants sur le shield et édité le circuit imprimé en répartissant les composants de manière à éviter les croisements de fils et à assurer une connexion correcte. Pour cela nous avons suivi les consignes imposées, avec des pistes de 1 mm, des pastilles de 2 mm et des zones de perçage de 0,8 mm.

### Visualisation 3D
Le téléchargement des modèles non fournis par Kicad sur le site “grabcad.com” des composants nous a permis d'obtenir un modèle 3D de notre PCB final. Cela nous a permis de vérifier que les positions des composants ne se gênaient pas mutuellement et qu'ils disposaient tous d'un espace suffisant sur le shield.

## Fabrication du Shield
Grâce à l’aide de Catherine Crouzet, nous avons concrétisé le PCB physique. Il est fabriqué à partir d'une plaque d'époxy recouverte d'une fine couche de cuivre conducteur. Notre schéma de PCB, issu de Kicad, a été imprimé et utilisé comme masque lors de l'exposition aux rayons UV pour isoler la plaque. Un révélateur a été utilisé pour éliminer la résine non isolée. Ensuite, un bain de perchlorure de fer a gravé le cuivre non protégé par la résine. Ainsi, nous avons obtenu le PCB physique conforme à notre modèle Kicad.

Par la suite, nous avons percé des trous dans le PCB pour pouvoir y insérer les composants. Nous avons utilisé des trous d'un diamètre de 1 mm pour les broches de connexion de la carte Arduino, et de 0,8 mm pour les autres composants. 

Enfin, nous avons pu souder les composants sur la carte à l'aide d'étain.

## Arduino

Le code Arduino permet d’assurer la communication entre les différents composants du PCB et la carte Arduino. 
Il permet de récupérer la valeur renvoyée par le capteur graphite, de la passer en valeur décimale et de la convertir en résistance.
Il permet aussi de récupérer la valeur renvoyée par le Flexsensor, de la convertir en valeur décimale, puis en résistance et de donner la valeur de l’angle de courbure associé.
Le tout est envoyé sur l’écran OLED grâce à la librairie Adafruit_SSD1306.h.
La valeur récupérée du capteur graphite est transférée au module Bluetooth.

## Application Bluetooth

Pour capturer et visualiser les variations de résistance lors de la déformation du capteur envoyées par le module Bluetooth, nous avons développé une application Android sur la plateforme MIT App Inventor.

Notre application permet de se connecter au module Bluetooth en utilisant un bouton dédié qui affiche les périphériques disponibles localement. Une fois la connexion établie, un canvas affiche la courbe de variation de résistance en fonction du temps. En bas de l'écran, un champ de texte affiche la valeur de résistance du capteur en mégaohms. Les données sont actualisées toutes les 50 millisecondes.

## Tests et résultats

### Banc de test
La caractérisation de notre capteur a été réalisée à l’aide des cylindres présents ci-dessus. Ces 7 cylindres possèdent un diamètre de 5 cm pour le plus grand à 2 cm pour le plus petit, avec un pas de 0,5 cm entre chacun. Il est donc possible de calculer la déformation du capteur à l’aide de la formule suivante : ε = e/2R, avec e l’épaisseur de notre capteur (0.3 mm), et R le rayon de chaque cylindre. 

Il suffit de positionner le capteur graphite sur chacun des cylindres, du plus grand au plus petit et de noter la valeur renvoyée par celui-ci. Pour notre part, nous avons directement utilisé la valeur renvoyée par l’Arduino, qui est comprise entre 0 et 1024. Il est aussi nécessaire de noter la valeur renvoyée par le capteur lorsqu’il n’est soumis à aucune contrainte mécanique. 

Une fois les mesures réalisées, il est possible de tracer la variation relative de résistance du capteur graphite en fonction de la déformation appliquée. 

Nous avons tracé les courbes pour deux types de crayons différents : le HB et le B, en tension et en compression. Les valeurs en tension correspondent à la position de droite, et les valeurs en compression à la position de gauche.

### Résultats obtenus

Voici les courbes en tension et en compression obtenues pour les crayons HB et B : 
Vous trouverez le détail de chaque courbe dans le dossier : … 

### Analyse des résultats

En tension, le crayon HB possède un coefficient de droite de 3125,738 et le B 1702,870.
En compression, le crayon HB possède un coefficient de droite de -6378,553 et le B -3431,997.

On remarque que plus un crayon est gras, donc plus il est concentré en graphite, moins sa variation relative de résistance est élevée en valeur absolue en tension et en compression. 

De plus, sous tension, les particules de graphite s’éloignent les unes des autres, ce qui casse certains chemins de percolation et explique une augmentation de la variation de résistance. 
Sous compression, les particules de graphite se rapprochent, ce qui facilite la conduction dans le réseau percolé de notre capteur et implique une diminution de la variation relative de résistance.

Nous avons aussi caractérisé le Flexsensor en tension, afin de comparer sa sensibilité à notre capteur graphite. Voici la courbe obtenue :

On remarque que le Flexsensor industriel possède une sensibilité plus élevée. Le coefficient directeur de sa droite est en effet plus élevé que n’importe quel crayon que nous avons utilisé. Il est de 57702,122. Il est donc capable de détecter des variations plus fines du signal délivré. Il est aussi beaucoup plus robuste, et son utilisation nécessite beaucoup moins de précautions que notre capteur graphite. 

### Pistes d'améliorations

Afin d’améliorer la précision de nos courbes, nous aurions pu réaliser plus de mesures et dans de meilleures conditions. En effet, les valeurs obtenues ne sont pas très précises et sont très influencées par la quantité de graphite présente, le placement des pinces métalliques et la façon dont le capteur est courbé. Il est donc difficile d’obtenir une expérience de mesure répétable.

## Datasheet

Vous trouverez la datasheet de notre capteur ici : …. Vous pouvez aussi visualiser son code LaTeX via le lien suivant : https://www.overleaf.com/read/bkwftjfrphdg.  

## Contacts

N’hésitez pas à nous contacter pour toutes questions concernant ce projet. 
SZTYM Alice : sztym@etud.insa-toulouse.fr
ELLINGSEN Abélia : aellings@etud.insa-toulouse.fr 

