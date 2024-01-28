# LED Matrix Leuchtschrift

Texte auf eine SPI Led Matrixanzeige anzeigen lassen.

# Module

- 8x8 SPI LED Matrix (CLK: PB_13, DIN: PB_15, CS: PC_1, Vin: 5V, GND: GND)

## Notes

Es kann sein, dass beim erstmaligen Versorgen mit Strom nicht alle Matrizen leuchten. Dann einfach einmal den MC
resten (schwarzer Knopf)

Die Texte können in text.h frei gewählt werden.  
Jeder Text besteht aus einem Text (logisch) und einer Probability.  
Außerdem kann auch ein Text spezifische Scroll Speed eingestellt werden.

Der Text wird mit den in der Lib spezifischen Syntax aufgebaut.  
Wenn der Text zu lang ist, kann es sein, dass er nicht richtig angezeigt wird.
Was helfen kann (nicht ausprobiert) ist den Wert `MAX_TEXT_LENGTH` in DOTMATRIX.h zu erhöhen.

Die Probability gibt an, mit welcher Wahrscheinlichkeit der Text ausgeben wird.
Je höher der Wert, desto wahrscheinlicher.

Optional kann auch noch ein anderer Scroll Speed angegeben werden.
Wenn kein Scroll Speed angeben wird, wird der in main.cpp eingestelle "normale" Scroll Speed benutzt.

In main.cpp kann man die Anzahl an Modulen, den Scroll Speed, die Ausrichtung des Textes und die Helligkeit der Module eingestellt werden.

Wenn sehr viele Module benutzt werden oder eine helle Helligkeit benutzt wird, sollte man ein externes 5V Netzteil nur für die Module benutzen.  
Bei 27 Modulen mit einer Helligkeit von 5 war das aber kein Problem.

Das Wort das mit G anfängt und mit MT aufhört, ist nicht so gerne gesehen ...


Das Projekt kann sowohl in Keil Studio als auch mit PlatformIO geöffnet werden.

Gemacht von Leo