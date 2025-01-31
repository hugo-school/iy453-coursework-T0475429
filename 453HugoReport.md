#stat the story 

OUTPUT"introduction the story and tell them how to play

#Ask user select the number

OUTPUT"enter the number 1 or 2"

numOption <- USERINPUT

TOTALSCORE <- 0

numOption = userinput

If numOption = 1 Then

have another 1 or 2 to chose until ending

numOption = userinput

Elseif numOption = 2 Then

have another 1 or 2 to chose until ending

else

output the number 1 or 2

#score system

score = 0

OUTPUT" your dead"

score <- score -1

else

score <- Score +1

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
