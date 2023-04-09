#include <stdio.h>
#include <stdlib.h>
#include "Farben.h"                                     //Selbst erstellt Bibliothek wird miteingebaut

int buchstabe_ae=132;                                   //Integer erstellt um � anzuzeigen
int buchstabe_ue=129;                                   //Integer erstellt um � anzuzeigen
int spielfeld [8][7];                                   //Ein Array mit 72 Speicherpl�tzen wird angelegt.(Eine extra Saplte nach oben damit eine reihe von 0 �ber dem Spielfeld ist, wird ben�tigt um sp�ter eine Gewinnkontrolle durchzuf�hren.)
int spielfeld_kopie[8][7];                              //Ein weiters Array mit 72 Speicherpl�tzen wird angelegt, dies wird verwendet um ASCII zeichen in das Spielfeld einzugeben.

void arrayleeren (void)                                 //Unterfunktion welche das Array mit 0 f�llt
{
    int spalten=0;                                      //integer f�r splaten erstellt
    int zeilen=0;                                       //integer f�r zeilen erstellt
    for(spalten=0;spalten<=7;spalten++)                 //loopt spalten durch
    {
        for(zeilen=0;zeilen<=6;zeilen++)                //loopt zeilen durch
        {
            spielfeld[spalten][zeilen]=0;               //setzt an der position von spalten und Zeilen im Array eine null und bei der kopie eine 255, 255 als ASCII ist ein freies Feld.
            spielfeld_kopie[spalten][zeilen]=255;
        }
    }
}
void spielregeln(void)                                  //Unterfunktion welche die Spielregeln ausgibt.
{
    cyan();
    printf("\nHiermit werden die Spielregeln von 4 Gewinnt erkl%crt.",buchstabe_ae);
    printf("\nBei 4 Gewinnt werden Marker auf ein Spielfeld gelegt, dabei kann ein Feld nur einmal belegt werden.");
    printf("\nEs gibt 7 Spalten und 6 Zeilen auf dem Spielplan und es wird zwischen 2 spielern alterniert.");
    printf("\nJetzt kannst du eine Zahl von 1-7 eingeben.");
    reset_color();
}

void zeichnen(void)                                     //Unterfunktion f�r die Ausgabe des Spielfelds.
{
    int a= 185;
    int b= 186;
    int c= 187;
    int d= 188;
    int f= 200;
    int g= 201;
    int h= 202;
    int i= 203;
    int j= 204;
    int k= 205;
    int l= 206;
    int loopzeilen=0;
    int loopspalten=0;
    int spalten=-1;
    int zeilen=5;
    for(loopzeilen=0;loopzeilen<=24;loopzeilen++)
    {
        blue();
        if(loopzeilen==0)
        {
            printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", g,k,k,k,k,k,i,k,k,k,k,k,i,k,k,k,k,k,i,k,k,k,k,k,i,k,k,k,k,k,i,k,k,k,k,k,i,k,k,k,k,k,c);
        }
        if(loopzeilen==24)
        {
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", f,k,k,k,k,k,h,k,k,k,k,k,h,k,k,k,k,k,h,k,k,k,k,k,h,k,k,k,k,k,h,k,k,k,k,k,h,k,k,k,k,k,d);
        }
        if((loopzeilen==4)|(loopzeilen==8)|(loopzeilen==12)|(loopzeilen==16)|(loopzeilen==20))
        {
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", j,k,k,k,k,k,l,k,k,k,k,k,l,k,k,k,k,k,l,k,k,k,k,k,l,k,k,k,k,k,l,k,k,k,k,k,l,k,k,k,k,k,a);
        }
        if((loopzeilen==1)|(loopzeilen==3)|(loopzeilen==5)|(loopzeilen==7)|(loopzeilen==9)|(loopzeilen==11)|(loopzeilen==13)|(loopzeilen==15)|(loopzeilen==17)|(loopzeilen==19)|(loopzeilen==21)|(loopzeilen==23))
        {
            printf("%c     %c     %c     %c     %c     %c     %c     %c\n", b,b,b,b,b,b,b,b);
        }
        if((loopzeilen==2)|(loopzeilen==6)|(loopzeilen==10)|(loopzeilen==14)|(loopzeilen==18)|(loopzeilen==22))
        {
            for(loopspalten=0;loopspalten<=15;loopspalten++)
            {
                if((loopspalten==0)|(loopspalten==2)|(loopspalten==4)|(loopspalten==6)|(loopspalten==8)|(loopspalten==10)|(loopspalten==12))
                {
                    printf("%c  ",b);
                }
                if(loopspalten==14)
                {
                    printf("%c\n",b);
                }
                if((loopspalten==1)|(loopspalten==3)|(loopspalten==5)|(loopspalten==7)|(loopspalten==9)|(loopspalten==11)|(loopspalten==13))
                {
                    spalten++;
                    if(spielfeld[spalten][zeilen]==1)
                    {
                        red();
                        printf("%c  ",spielfeld_kopie[spalten][zeilen]);
                        blue();
                    }
                    if(spielfeld[spalten][zeilen]==2)
                    {
                        yellow();
                        printf("%c  ",spielfeld_kopie[spalten][zeilen]);
                        blue();
                    }
                    if(spielfeld[spalten][zeilen]==0)
                    {
                    printf("%c  ",spielfeld_kopie[spalten][zeilen]);
                    }
                    if(spalten==6)
                    {
                        zeilen--;
                        spalten=-1;
                    }
                }
            }
        }
    }
    reset_color();
}

void einwurf(int player)                                //Unterfunktion welche den Einwurf regelt.
{
    int spalten=0;                                      //erstellen von Variablen
    int zeilen=0;                                       //erstellen von Variablen
    int ungueltige_eingabe_zaehler=0;                   //erstellen von Variablen

    cyan();                                             //Wechselt die Farbe auf T�rkis, geschieht in einer von mir erstellten Bibliothek.
    printf("\n\nSpieler %i ist an der Reihe", player);  // Ausgabe des aktuellen Spielers
    scanf(" %i", &spalten);                             // Eingabe der Spalte durch den Spieler
    spalten--;                                          //Spalten wird um eins runter gez�hlt, die wird getan um eine Eingabe von 1-7 zu erlauben.

    while(spalten<0||spalten>6||spielfeld[spalten][5]!=0)  // �berpr�fung der Eingabe auf Korrektheit
    {
        red();                                          //setzt die Textausgabe auf Rot
        printf("\nUngueltige Spalte! Nimm ne andere Spalte.");             //Textausgabe
        scanf(" %i", &spalten);                         //Eingabe der Spalte durch den Spieler
        spalten--;                                      //Spalten wird um eins runter gez�hlt, die wird getan um eine Eingabe von 1-7 zu erlauben.
        ungueltige_eingabe_zaehler++;                   //Hiermit werden die ungueltigen Eingaben gez�hlt.

        if(ungueltige_eingabe_zaehler==6)               //Wenn zuviele ung�ltige Eingaben get�tigt wurden, wird der Bildchirm entleert.
        {
            ungueltige_eingabe_zaehler=0;               //Damit erneut der Bildschirm geleert werden kann, wirrd der z�hler auf 0 gesetzt
            system("cls");
            zeichnen();
            spielregeln();
            yellow();
            printf("\nMachst du das eigentlich mit Abischt?");
            cyan();
            printf("\nSpieler %i ist an der Reihe", player);
        }
    }
    reset_color();                                      //Textfarbe wird auf Standard zur�ckgesetzt

    for (zeilen=0;zeilen<=5;zeilen++)                   // Durchlaufen der Zeilen in der ausgew�hlten Spalte
    {
        if(spielfeld[spalten][zeilen]!=0)               // Wenn die Zelle bereits besetzt ist, wird zum n�chsten Durchlauf der Schleife gesprungen
        {
            continue;
        }
        if (player==1)                                  // Platzieren des Spielsteins f�r den aktuellen Spieler in der aktuellen Zelle
        {
            spielfeld[spalten][zeilen]=1;
            spielfeld_kopie[spalten][zeilen]=254;       //254 ist ASCII-code f�r ein Viereck, da die kopie des Spielfelds daf�r verwendet wird steine auszugeben wird hier also 254 eingef�gt.
            break;
        }
        if (player==2)
        {
            spielfeld[spalten][zeilen]=2;
            spielfeld_kopie[spalten][zeilen]=254;
            break;
        }
    }
}

int spielerwechsel(int player2,int gewausgabe)          //Unterfunktion f�r den Spielerwechsel, diese bekommt (1) spieler und (2) gewonnen und speichert die vorher genannten in (1) player2 und (2) gewausgabe.
{
    if(gewausgabe!=1)                                   //�berpr�ft ob gewausgabe (Gewinnausgabe) eine ist 1, wenn nein findet der Spieler wechsel statt
    {
        if(player2==1)                                  //�berpr�ft ob spieler (welcher in player2 �bertragen wird) gleich 1 ist.
        {
            return 2;                                   //Gibt eine 2 zur�ck an das Hauptprogramm wenn die Kondition der if-abrfrage erf�llt ist.
        }
        if(player2==2)                                  //�berpr�ft ob spieler (welcher in player2 �bertragen wird) gleich 2 ist.
        {
            return 1;                                   //Gibt eine 1 zur�ck an das Hauptprogramm wenn die Kondition der if-abrfrage erf�llt ist.
        }
    }

    return player2;                                     //Gibt den Wert den die Unterfunktion von der Hauptfunktion bekommen hat ohne �nderung wieder zur�ck.
}

int feldvoll ()                                         //Unterfunktion welche ausgibt ob das Feld voll ist, diese gibt feldvoll als integer zur�ck.
{
    int loopvoll=0;                                     //Integer zum loopen erstellt
    int ueberfuellt=0;                                  //Integer zum hochz�hlen erstellt
    for(loopvoll=0;loopvoll<=6;loopvoll++)              //looped bis gr��er gleich 6
        {
            if(spielfeld[loopvoll][5]!=0)               //�berpr�ft ob das Feld in der obersten Zeile an der Stelle von loopvoll eine 0 hat, wenn nein ist die kondition erf�llt.
            {
                ueberfuellt++;                          //Z�hlt ueberfuellt 1 auf.
            }
        }
    if(ueberfuellt>=7)                                  //Wenn ueberfuellt jetzt gr��er gleich 7 ist, ist das Feld voll, und somit wird eine 1 zur�ck gegeben.
    {
        return 1;                                       //Gibt eine 1 zur�ck an die Hautpfunktion.
    }
    return 0;                                           //Wenn vorher keine 1 zur�ck gegeben wurde, wird eine 0 zur�ck an die Hauptfunktion gegeben.
}

int gewinn (int player3)                                //Unterfunktion welche �berpr�ft ob gewonnen wurde, diese bekommt spieler �bergeben und speichert dies in player3
{
int spalten=0;                                          // spalten wird verwendet, um durch die Spalten zu iterieren.
int zeilen=0;                                           // zeilen wird verwendet, um durch die Zeilen zu iterieren.
int counter=0;                                          // counter wird verwendet, um zu �berpr�fen, ob vier gleiche Spielsteine in einer Reihe liegen.
int diagonal=0;                                         // diagonal wird als Zwischenspeicher verwendet.


for (spalten = 0; spalten <= 6; spalten++)              // Hier werden die Spalten durchgez�hlt.
{
    for (zeilen = 0; zeilen <= 5; zeilen++)             // Hier werden die Zeilen durchgez�hlt.
    {
        if (spielfeld[spalten][zeilen]==player3)        // �berpr�fen, ob der Spielstein im Spielfeld mit dem Spielernamen �bereinstimmt, der zuletzt gespielt hat.
        {
            counter++;                                  // Wenn ja, wird counter erh�ht.
        }
        else                                            // Wenn die vorherige �berpr�fung negativ ausf�llt, wird counter auf null zur�ckgesetzt.
        {
            counter=0;                                  // Counter wird auf null gesetzt.
        }
        if(counter>=4)                                  // Wenn counter gr��er oder gleich 4 ist, gibt die Funktion eine 1 zur�ck an die Hauptfunktion.
        {
            return 1;                                   // Gibt eine 1 an die Hauptfunktion zur�ck.
        }
    }
}
spalten=0;                                              // Setzt spalten auf null, damit in der n�chsten Schleife keine falschen Werte verwendet werden.
zeilen=0;                                               // Setzt zeilen auf null, damit in der n�chsten Schleife keine falschen Werte verwendet werden.
counter=0;                                              // Setzt counter auf null, damit in der n�chsten Schleife keine falschen Werte verwendet werden.

for(zeilen=0;zeilen<=5;zeilen++)                        // Geht durch bis zeilen gr��er oder gleich 5 erreicht hat.
{
    for(spalten=0;spalten<=6;spalten++)                 // Hier werden die Spalten durchgez�hlt.
    {
        if(spielfeld[spalten][zeilen]==player3)         // �berpr�fen, ob der Spielstein im Spielfeld mit dem Spielernamen �bereinstimmt, der zuletzt gespielt hat.
        {
            counter++;                                  // Wenn ja, wird counter erh�ht.
        }
        else                                            // Wenn die vorherige �berpr�fung negativ ausf�llt, wird counter auf null zur�ckgesetzt.
        {
            counter=0;                                  // Counter wird auf null gesetzt.
        }
        if(counter>=4)                                  // Wenn counter gr��er oder gleich 4 ist, gibt die Funktion eine 1 zur�ck an die Hauptfunktion.
        {
            return 1;                                   // Gibt eine 1 an die Hauptfunktion zur�ck.
        }
    }
}

spalten=0;
zeilen=0;
counter=0;
diagonal=0;

while(diagonal <= 3)                                    // Solange diagonal kleiner oder gleich 3 ist, wird die Schleife wiederholt.
{
    counter=0;                                          // Setzt den Z�hler auf 0 zur�ck, damit er bei der n�chsten Durchf�hrung der For-Schleife wieder bei 0 beginnt.
    zeilen=diagonal;                                    // Da diagonal hochz�hlt, sobald eine Iteration der For-Schleife abgeschlossen ist, wird zeilen mit diagonal gleichgesetzt, um den Zeilenwert zu erh�hen.
    for(spalten=0;spalten<=6;spalten++)                 // F�hrt die Schleife aus, solange spalten kleiner oder gleich 6 ist.
    {
        if(spielfeld[spalten][zeilen]==player3)         // �berpr�ft, ob der Stein auf dem Spielfeld demjenigen des Spielers entspricht, der als letztes dran war.
        {
            counter++;                                  // Wenn das der Fall ist, wird der Z�hler erh�ht.
            zeilen++;                                   // Zeilenwert wird erh�ht, um Diagonalz�hlung zu erm�glichen.
        }
        else                                            // Wenn die vorherige Bedingung nicht erf�llt ist, werden e und c auf 0 zur�ckgesetzt. Bevor das passiert, wird zeilen um counter und spalten um counter reduziert.
        {
            spalten=spalten-counter;                    // Setzt spalten um counter zur�ck.
            zeilen=zeilen - counter;                    // Setzt zeilen um counter zur�ck.
            counter=0;                                  // Setzt counter auf 0 zur�ck.
        }
            if(counter>=4)                              // Wenn der Z�hler gr��er oder gleich 4 ist, gibt die Unterfunktion 1 an die Hauptfunktion zur�ck.
        {
            return 1;                                   // Gibt 1 an die Hauptfunktion zur�ck.
        }
            if(spalten==6)                              // Wenn spalten gleich 6 ist, wird diese Bedingung erf�llt.
        {
            diagonal++;                                 // Diagonal wird um 1 erh�ht.
            counter=0;                                  // Counter wird auf 0 zur�ckgesetzt.
        }
    }
}

spalten=0;                                              // Setzt spalten auf 0, damit bei der n�chsten �berpr�fung/Schleife kein falscher Wert �bergeben wird.
zeilen=0;                                               // Setzt zeilen auf 0, damit bei der n�chsten �berpr�fung/Schleife kein falscher Wert �bergeben wird.
counter=0;                                              // Setzt counter auf 0, damit bei der n�chsten �berpr�fung/Schleife kein falscher Wert �bergeben wird.
diagonal=0;                                             // Setzt diagonal auf 0, damit bei der n�chsten �berpr�fung/Schleife kein falscher Wert �bergeben wird.

while(diagonal<=3)                                      //W�hrend diagonal kleiner als 3 ist wird wiederholt
{
    counter=0;                                          //setzt counter auf 0 zur�ck damit wenn der n�chste Lauf des For-loops erreicht wird, counter wieder auf 0 beginnt.
    zeilen=diagonal;                                    //Da diagonal hochz�hlt sobald ein Durchgang der For-Schleife geendet hat, setze ich zeilen mit diagonal gleich um die Zeilen hoch zu springen
    for(spalten=6;spalten>=0;spalten--)                 //Z�hlt von der anderen Seite des Spielfelds ab
    {
        if(spielfeld[spalten][zeilen]==player3)         //Wenn das Spielfeld an der Stelle wo die Counter gerade sind denselben "Stein" wie der Spieler hat ist die Bedingung erf�llt
        {
            counter++;                                  //counter wird um 1 hochgez�hlt, counter wird verwendet um �berpr�fen ob wer gewonnen hat.
            zeilen++;                                   //zeilen wird um 1 hochgez�hlt, das wird getan damit Diagonal gez�hlt werden kann.
        }
        else                                            //wenn die vorherige �berpr�fung nicht der Fall ist werden e und counter auf null zur�ck gesetzt, befvor dass geschieht wird zeilen auf zeilen-counter und spalten auf spalten+counter gesetzt.
        {
            zeilen=zeilen-counter;                      //Setzt zeilen mit zeilen-counter gleich, dies geschieht damit in der selben Spalte weiter gez�hlt werden kann
            spalten=spalten+counter;                    //Setzt spalten mit spalten+counter gleich, dies geschieht damit in der selben Zeile weiter gez�hlt werden kann
            counter=0;                                  //setzt counter auf null
        }
        if(counter>=4)                                  //Wenn counter gr��er gleich 4 ist gibt die unterfunktion eine 1 zur�ck an die Hauptfunktion.
        {
        return 1;                                       //Gibt eine 1 zur�ck an die Hauptfunktion.
        }
        if(spalten<=0)                                  //Wenn spalten kleiner gleich als 0 ist, ist die Kondition erf�llt.
        {
        diagonal++;                                     //diagonal wird um 1 hochgez�hlt.
        counter=0;                                      //counter wird auf 0 gesetzt
        }
    }
}
return 0;                                               //wenn vorher nichts anderes zur�ck an die Hauptfunktion gegeben wird, wird 0 zur�ck gegeben.
}

void siegerehrung (int gleichstand,int player4,int gewinner)    //Unterfunktion welche eine Siegerehrung durchf�hrt. bekommt (1) voll, (2) spieler und (3) gewonnen aus der Hauptfunktion und speichert diese in (1) gleichstand, (2) player 4 und (3) gewinner.
{
    if(gewinner==1)                                                                             //Wenn jemand gewonnen hat wird ein Text ausgegeben.
    {
        green();                                                                               //Textfarbe wird auf Lila gewwechselt.
        printf("\nSpieler %i du hast gewonnen! F%chlst du dich jetzt gut oder wie?",player4,buchstabe_ue);
        reset_color();                                                                          //Textfarbe wird zur�ckgesetzt
    }
    if((gleichstand==1)&&(gewinner!=1))                                                         //Wenn Gleichstand ist, gibt as Programm einen anderen Text aus.
    {
        yellow();                                                                               //Textfarbe wird auf Gelb gesetzt.
        printf("\nSieht so aus als sei das Feld voll, Das ist also ein Gleichstand.");          //Textausgabe
        reset_color();                                                                          //Textfarbe wird zur�ck gesetzt
    }
}

int main()                                              //Hauptfunktion
{


    int spieler=1;                                      //Ineteger um zu Speichern welcher Spieler an der reihe ist.
    int voll=0;                                         //Integer erstellt um zu Speichern ob das Feld voll ist oder nicht.
    int gewonnen=0;                                     //Integer erstellt um zu Speichern ob gewonnen wurde.

    initialize_color();                                 //Sorgt daf�r dass ein Farben wechsel unterst�tzt wird, dies geschieht in einer von mir erstellten Bibliothek.
    arrayleeren();                                      //Unterfunktion welche das Spielfeld leert.
    while((voll !=1) & (gewonnen !=1))                  //Bis das Feld voll ist oder jemand gewonnen, wird weiter gelooped.
    {
        zeichnen();                                     //Unterfunktion welche das Spielfeld zeichnet.
        spielregeln();                                  //Unterfunktion welche die Spielregeln augibt.
        einwurf(spieler);                               //Unterfunktion welche den Einwurf einleitet, diese bekommt spieler �bergeben.
        system("cls");                                  //L�scht den Bildschirm.
        gewonnen=gewinn(spieler);                       //Setzt gewonnen mit der zur�ckgegebenen Zahl gleich, diese bekommt spieler �bergeben.
        voll=feldvoll();                                //Setzt voll mit der zur�ckgegebenen Zahl gleich.
        spieler=spielerwechsel(spieler,gewonnen);       //Setzt spieler mit der zur�ckgegebenen Zahl gleich, die Unterfunktion bekommt spieler und gewonnen.
    }
    zeichnen();                                         //Unterfunktion welche das Spielfeld zeichnet, dies geschieht nachdem der Loop beendet wurde.
    siegerehrung(voll,spieler,gewonnen);                //Unterfunktion welche die Siegerehrung ausgibt, diese bekommt voll, spieler und gewonnen �bergeben.

    return 0;
}
