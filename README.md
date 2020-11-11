#CastleQuest

#This is a brief demo of a command-line RPG in development written in C++ created by Rob Scales

The current method of running is:
  compile Battler.cpp as game.exe
  compile keyNav2 as key2.exe
  compile congratsAnim as congrats.exe
  place all executables in the same folder as the file BigMap.txt and Celebration.txt
  run key2.exe
  
-----Controls-----
Navigating Map:
  -Up key - Move Up
  -Down key - Move Down
  -Left key - Move Left
  -Right key - Move Right
  -esc - exit game
  -any key - refresh map (buggy)
  
Command line battler:
  At this point, commands are written in the command line as prompted by the game.
  
  First, enter your name as one word.
  Second, enter your class from the 3 classes: sword, gunner, or magic 
  (case-sensitive; gunner is recommended in this demo)
  
  In battle commands:
    slash - attack that does 3 damage (sword only)
    shoot - attack that does 5 damage (gunner only)
    healhit - attack that does 2 damage (magic only)
    heal - restores 3 health
    
 There are 3 battles, each with enemies of different strength and with a different probability of landing an attack.
 
 It is possible to undergo multiple turns with one line e.g. 
    >>shoot shoot shoot heal heal
 will perform 3 turns in which the player (a gunner in this case) attacks and 2 in which the player heals themself.
 
 
#All code was written using C++
#Code, sprites, animation, and map written by Rob Scales
#Website of creator: https://robscales06.github.io/sitio/index.html
#Thank you for Reading!
