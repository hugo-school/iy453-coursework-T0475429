#stat the story


#introduction

OUTPUT"introduction the story and tell them how to play"

OUTPIT"PLS ENTER 1 OR 2 TO PLAY THE GAMES"


#user select the number 1

OUTPUT"you select number 1 "

numOption <- USERINPUT

TOTALSCORE <- 0

numOption = userinput

If numOption = 1 Then

have another 1 or 2 to chose until ending


#user select the number 2

OUTPUT" you select number 2"

numOption <- userinput

Elseif numOption = 2 Then

have another 1 or 2 to chose until ending

Else

OUTPUT"pls enter the number 1 or 2 to playx"


#score system

IF TOTALSCORE < 0 THEN 

OUTPUT" your dead"

TOTALSCORE<- TOTALSCORE -1

else

score <- Score +1

ENDIF


#save

OUTPUT "SAVE YOUR GAME"

SAVEDATA "save.txt", score

OUTPUT" you save your game"


#Error

numOption <- userinput out of 1 or 2

OUTPUT"pls enter the number 1 or 2"

# 

anlysis and design

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
