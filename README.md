# 2022-2023-4gp-ELLINGSEN-SZTYM

Dans le cadre de l’unité de formation “Du capteur au banc de test” suivi en 4ème année par les étudiants de Génie Physique de l’INSA de Toulouse, nous avons réalisé un capteur à jauge de contrainte low-tech à base de crayon graphite. Ce projet s’appuie sur l’ouvrage : “Pencil Drawn Strain Gauges and Chemiresistors on Paper”, écrit par : Cheng-Wei Lin*, Zhibo Zhao*, Jaemyung Kim & Jiaxing Huang. 

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
- x1 flexsensor 
- x1 feuille de papier et un crayon à papier


## Simulations sous LTSpice

## KiCad
Le logiciel Kicad a été essentiel dans la réalisation de schémas électriques et la modélisation de notre PCB avant la création du shield. Ce processus implique plusieurs étapes. Tout d'abord, nous avons créé les empreintes de tous les composants que nous souhaitions incorporer, puis défini les connexions entre eux ainsi qu'avec la carte Arduino. Ensuite, nous avons édité le PCB en suivant les consignes imposées, avant de conclure par la visualisation en 3D du PCB complet.

### Symboles, empreintes et visualisation 3D des composants
Afin de réaliser le schéma du circuit, nous avons créé une librairie d'empreintes pour les composants qui n'étaient pas disponibles dans les librairies intégrées au logiciel. Ensuite, nous avons établi les connexions entre les composants et la carte Arduino une fois que tous les éléments ont été schématisés.

### Schématique
### PCB
### Visualisation 3D

## Fabrication du Shield

## Arduino

## Application Bluetooth

## Tests et résultats
### Banc de test
### Résultats obtenus
### Analyse des résultats
### Pistes d'améliorations

## Datasheet

## Contacts
