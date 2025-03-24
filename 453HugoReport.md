Introduction

This project involves creating a text adventure game in C++, the game includes choices, combat and inventory system. Players will decide between 1 and 2, those can affect the story. The code has a player and enemy class, to manage attributes includes health attack and magic, when the player health equal or less than 0 will game over. Each story line has an ending, to  ensure the story funny enough. The code has a random weather class to make sure a story not same every time.



Required

required to do a text-based adventure game, the game should let the player with binary choices(two options). It must attract the player. Allowed the player collect varied items and the variety of scenarios, each item have impact like increase health. Last need a saves, scorce and error system. Here have at least 30 binaries to let player to choose.

output:

introduction and role

Ending

ask player select number

event(varied item, weather, weather)

attributes(health, attack and defense)

input:

name

numOption

replay or not

processing:

save

score

error(when the player dont enter num 1 or 2)

---

Pseduo code

#start story

Output" introduction the story and tell them how to play."

OUTput" PLS ENTER 1 OR 2."

numOption<-USERINPUT

TOTALSCORE<- 0

#player select number

->IF numOption = 1 THEN

OUTPUT "you select number 1."

->Return numOption

->elseif numOption = 2 Then

OUTPUT "you select number 2."

->Return numOption

->Else Output"pls enter the number 1 or 2 to play."

-> ENDSUBROUTINE

#EXPANDAD GAME

#After numOption = 1 or numOption = 2, after pick 1 or 2 it will lead to other option 1 or 2, it until the end or player dead.

#EVENT

#EVENT IS REDOM ON THIS 3 THING, SPEICAL MASTER, ITEAM AND WEATHER

#ATTRIBUTES

#IT SHOW HEALTH ,ATTACK AND DEFENSE. WHEN HEALTH 0 THEN PLAYER DEAD.

#Score system

IF TOTALSCORE<0 THEN

->OUTPUT"YOU DEAD."

#SAVE THE GAME

OUTPUT"SAVE THE GAME."

SAVEDATA"save.txt",TOTALSCORE

OUTPUT"YOU SAVED THE GAME."

#ERROR HADLING
IF numOption not equal 1 or equal 2 THEN

->OUTPUT"PLEASE ENTER THE NUMBER 1 OR ."

END IF

#END THE GAME

OUTPUT" GAME OVER."
