# practicum_12-10-2022

Hier een voorbeeld om van een functie voor user input. De functie `askQuestion` in de file [askQuestion.py](askQuestion.py) krijgt drie argumenten: type, vraag en opties. Binnen de functie wordt gecontroleerd of het resultaat correct is. Door middel van recursie wordt de functie vervolgens opnieuw aangeroepen, totdat er een correct antwoord is gegeven.

Het script is opgesplitst in meerdere files, die vervolgens samen worden gevoegd door vanuit [_main.py](_main.py) de andere files te importeren. Python insert vervolgens de code van de andere files op die plek in de code.

Door middel van de `__name__` variabele weet je of de file is ingeladen als module (import) of vanuit de terminal (python \<filenaam\>).
