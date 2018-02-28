#!/bin/sh
## perf.sh for  in /home/barret_l/rendu/Initiation_IA/dante
## 
## Made by Ludovic BARRETEAU
## Login   <barret_l@epitech.net>
## 
## Started on  Sat May 21 14:57:57 2016 Ludovic BARRETEAU
## Last update Sat May 21 15:15:47 2016 Ludovic BARRETEAU
##

echo "Test solver profondeur 1:"
time ././profondeur/solver mazes/laby.txt > perf1_prof.test
echo "-----"
echo "Test solver profondeur 2:"
time ././profondeur/solver mazes/laby2.txt > perf2_prof.test
echo "-----"
echo "Test solver profondeur 3:"
time ././profondeur/solver mazes/laby3.txt > perf3_prof.test
echo "-----"
echo "Test solver profondeur 4:"
time ././profondeur/solver mazes/laby5.txt > perf4_prof.test
echo "-----"
echo "Test solver profondeur 5:"
time ././profondeur/solver mazes/laby6.txt > perf5_prof.test
echo "-----"
echo "Test solver profondeur 6:"
time ././profondeur/solver mazes/laby8.txt > perf6_prof.test
echo "-----"
echo "Test solver profondeur 7:"
time ././profondeur/solver mazes/laby9.txt > perf7_prof.test
echo "-----"
echo "Test solver profondeur 8:"
time ././profondeur/solver mazes/laby7.txt > perf8_prof.test
echo "-----"
echo "-------------------------"
echo "Test solver largeur 1:"
time ././largeur/solver mazes/laby.txt > perf1_larg.test
echo "-----"
echo "Test solver largeur 2:"
time ././largeur/solver mazes/laby2.txt > perf2_larg.test
echo "-----"
echo "Test solver largeur 3:"
time ././largeur/solver mazes/laby3.txt > perf3_larg.test
echo "-----"
echo "Test solver largeur 4:"
time ././largeur/solver mazes/laby5.txt > perf4_larg.test
echo "-----"
echo "Test solver largeur 5:"
time ././largeur/solver mazes/laby6.txt > perf5_larg.test
echo "-----"
echo "Test solver largeur 6:"
time ././largeur/solver mazes/laby8.txt > perf6_larg.test
echo "-----"
echo "Test solver largeur 7:"
time ././largeur/solver mazes/laby9.txt > perf7_larg.test
echo "-----"
echo "Test solver largeur 8:"
time ././largeur/solver mazes/laby7.txt > perf8_larg.test
echo "-----"
