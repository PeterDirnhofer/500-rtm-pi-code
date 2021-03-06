# Installation des Programms rtm_pi auf dem raspberry
## Voraussetzungen / Vorbereitung des raspberry
### raspberry Hardware
raspberry Pi 4 mit mindestens 4 GB RAM und mindestens 32 GB micro SD   
Original raspberry USB C Netzteil        
### raspberry Software/Konfiguration
**Raspberry Pi OS** Wir installieren das Betriebssystem mit dem **Raspberry Pi Imager** auf die SD card    
So geht's https://www.raspberrypi.com/software/  

**Expand Filesystem** nach der Installation in **sudo raspi-config** ausführen, damit die kompletten 32GB der SD card genutzt werden können      

**SSH Zugriff** in raspi-config aktivieren für den user pi mit password raspberry. Damit der raspberry 'headless' genutzt werden kann   
So geht's https://www.heise.de/tipps-tricks/Raspberry-Pi-SSH-einrichten-so-geht-s-4190645.html
### zusätzliche Software auf raspberry: git und make
Bevor wir anfangen überprüfen wir, ob **git** und **make** auf dem raspberry installiert sind. Wie prüfen, ob git bereits installiert ist mit:  
**git --version**   
Falls git noch nicht installiert ist, installieren wir es nach.      
So geht's  https://linuxize.com/post/how-to-install-git-on-raspberry-pi/

raspberry Pi OS unterstützt standarmässig C und C++ also sollte make bereits installiert sein. Ob dies wirklich der Fall ist, können wir prüfen mit dem Aufruf von          
**make --version**

### Anmeldung als user root im commandline mode!!!
Das Programm rtm_pi wird vom user **root im command line modus** ausgeführt.    
Daher klonen wir den C++ code als user root von GitHub und kompilieren und erzeugen das Programm rtm_pi mit make ebenfalls als user root.   
Zur Beruhigung: Die Ausführung als user root ist den folgenden Befehlssequenzen durch den vorangestellten Befehl **sudo -i** sichergestellt.

## Installation rtm_pi Schritt 1: C++ Code Dateien von Github auf den raspberry kopieren

Zunächst melden wir uns am raspberry an als user **pi** mit password **raspberry**      
   
Nachdem wir als user pi angemeldet sind, wechseln zum user **root** mit   
**sudo -i**

Wir erstellen das Verzeichnis git mit    
**mkdir ~/git**   
Hinweis: das **~** Zeichen finden wir mit **Alt Gr** auf der Taste links neben der Eingabetaste      

Wir wechseln in das neue verzeichnis git       
**cd ~/git**

Wir kopieren den Code von GitHub in das Verzeichnis git mit dem Befehl   
**git clone https://github.com/PeterDirnhofer/500-rtm-pi-code.git**

## Installation rtm_pi Schritt 2: Programm rtm_pi erstellen mit make 
Bei Bedarf wechseln wir vom user pi zum user root mit    
**sudo -i**   

Wir wechseln in das Verzeichnis **500-rtm-pi** mit   
**cd ~/git/500-rtm-pi-code/500-rtm-pi**

Wir kompilieren den im vorhergehenden Schritt geklonten C++ Code und erstellen das Programm **rtm_pi** mit     
**make**

## Schritt 3: Kontrolle ob das Programm rtm_pi erzeugt wurde und gestartet werden kann 
Bei Bedarf wechseln wir vom user pi zum user root mit    
**sudo -i**

Wir wechseln in das Verzeichnis **500-rtm-pi** mit     
**cd ~/git/500-rtm-pi-code/500-rtm-pi**

Wir testen, ob sich das Programm rtm_pi starten lässt mit   
(Den führenden Punkt beachten !)      
**./rtm_pi**   


Wenn alles ok ist, antwortet das Programm mit        
**SPI setup successful**    

Wir beenden das Programm mit **Strg C**
