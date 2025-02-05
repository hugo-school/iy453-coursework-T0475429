required to do a text-based adventure game, the game should let the player with binary choices(two options). It must attract the player.Allowed the player collect varied items and the variety of senarios, each item have impact like increase health. Last need a save, scorce and error system.

output:

introduction and role

Ending

ask player select number

event(varied item, weather)

attributes(health, attack and defense)

input:

name

numOption

replay or not

processing:

save

score

error(when the player dont enter num 1 or 2)


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

#EXpanded game

#After numOption = 1 or numOption = 2, you will have option 1 or 2 until the end or dead.


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
