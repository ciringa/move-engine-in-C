# move-engine-in-C

a terminal based movement and colision engine using C only
just some study about C programing language
there's a terminal based moviment engine who use's bi dimensional arrays to represent X an Y coordinates seting the player and objects position based on it
the current version is "Movement engine"

## about the GRID 

as previous mentioned the code uses an bidimensional array that refers itself to a X and Y grid where each cell is actually a number. The code draws some ASCII symbols to represent the player,walls and enemys and of course a blank space. By that way we can set the next correlation

    0 = blank space (draw nothing)
    
    1 = player cell (draw @)
    
    2 = wall cell (draw #)
    
    3 = ini cell (draw $)

this system works in two functions set_map that checks the player, enemys and walls position to changes the grid based in these values and the draw_map that draws the map based in these values. 

## moving the player

using this little grid system we can make the following logic, if the player press some key to go up that means that we need to check the position that he wanna go and see if the value is diferente from 2(a wall) if that condiction mean true so you can change the player position to this new one. 

## moving the enemy

using the same logic of the player movement we can make anything moves, but the enemy moves freely wile the player need to receive and keyboard input. To make the enemy move we first need to create a simple logic, if the player is above the enemy that means that the anemy needs to go up (Y-=1), if the player is left from the enemy that means that the enemy needs to move to the left (X--) and we move on... 


  

