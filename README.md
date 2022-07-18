# Installation des Programms rtm_pi auf dem raspberry
## Voraussetzungen / Vorbereitung des raspberry
### raspberry Hardware
raspberry Pi 4 mit mindestens 4 GB RAM und mindestens 32 GB micro SD   
Original raspberry USB C Netzteil        
### raspberry Software/Konfiguration
**Raspberry Pi OS** wird zum Beispiel mit dem Raspberry Pi Imager auf der SD card installiert.    
So geht's https://www.raspberrypi.com/software/  

**Expand Filesystem** nach der Installation in **sudo raspi-config** ausführen, damit die kompletten 32GB der SD card genutzt werden können      

**SSH Zugriff** in raspi-config aktivieren für den user pi mit password raspberry. Damit der raspberry 'headless' genutzt werden kann   
So geht's https://www.heise.de/tipps-tricks/Raspberry-Pi-SSH-einrichten-so-geht-s-4190645.html
### zusätzliche Software auf raspberry: git und make
Bevor wir anfangen überprüfen wir, ob **git** und **make** auf dem raspberry installiert sind. Wie prüfen, ob git bereits installiert ist mit:  
**git --version**   
Bei Bedarf Nach-Installation git.   
So geht's  https://linuxize.com/post/how-to-install-git-on-raspberry-pi/

raspberry Pi OS unterstützt standarmässig C und C++. Ob dies auch auf unserem raspberry zutrifft, können wir prüfen mit den Aufruf von          
**make --version**

### Anmeldung als user root !!!
**Das Programm rtm_pi muss als user **root** ausgeführt werden.    
Daher müüsen wir den code von von GitHub als user root runterladen und das Programm als user root mit make erzeugen**   
Zur Beruhigung: Die Ausführung als user root ist den folgenden Befehlssequenzen durch den vorangestellten Befehl **sudo -i** sichergestellt.

## Installation rtm_pi Schritt 1: C++ Code Dateien von Github auf den raspberry kopieren

Zunächst Anmmeldung im raspberry wie gewohnt als user **pi** mit password **raspberry**     
Nachdem wir als user pi angemeldet sind, wechseln zum user **root** mit   
**sudo -i**

Verzeichnis git erstellen mit    
**mkdir ~/git**

In Verzeichnis git wechseln mit    
**cd ~/git**

Code von GitHub auf den raspberry kopieren mit   
**git clone https://github.com/PeterDirnhofer/500-rtm-pi-code.git**

## Installation rtm_pi Schritt 2: Programm rtm_pi erstellen mit make 
Bei Bedarf wechseln vom user pi zum user root mit    
**sudo -i**

Wechseln in Verzeichnis **500-rtm-pi** mit dem Befehl   
**cd ~/git/500-rtm-pi-code/500-rtm-pi**

Den im vorhergehenden Schritt runtergeladenen C++ Code kompilieren und daraus das Programm **rtm_pi** erstellen mit dem Befehl   
**make**

## Schritt 3: Kontrolle ob das Programm rtm_pi erzeugt wurde und gestartet werden kann 
Bei Bedarf wechseln vom user pi zum user root mit    
**sudo -i**

Wechseln in Verzeichnis **500-rtm-pi** mit dem Befehl   
**cd ~/git/500-rtm-pi-code/500-rtm-pi**

Test-Aufruf des Programms rtm_pi mit   
**./rtm_pi**   
Das Programm sollte antworten mit        
**SPI setup successful**    

Beenden des Programms mit **Strg C**
