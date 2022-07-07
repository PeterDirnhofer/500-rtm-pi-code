# Installation des Programms rtm_pi auf dem raspberry
## Voraussetzung: raspberry Hardware
- Raspberry Pi 4   
- mindestens 4 GB RAM    
- mindestens 32 GB micro SD   
- Original USB C Netzteil        
## Voraussetzung: raspberry Software/Konfiguration
**Raspberry Pi OS** wird zum Beispiel mit dem Raspberry Pi Imager auf der SD card installiert.     
Siehe https://www.raspberrypi.com/software/      
**Expand Filesystem** in raspi-config ausführen, damit die komplette SD card genutzt werden kann      
**SSH Zugriff** in raspi-config aktivieren für den user pi mit password raspberry. Damit der raspberry 'headless' genutzt werden kann
## Voraussetzung: zusätzliche Software git und make
Bevor wir anfangen überprüfen wir, ob **git** und **make** auf dem raspberry installiert sind.   
Prüfen, ob git installiert ist mit:   
**git --version**   
Bei Bedarf Installation git siehe z.B  https://linuxize.com/post/how-to-install-git-on-raspberry-pi/

Prüfen, on make installiert ist mit:   
**make --version**

## Wichtiger Hinweis user root !!!
**Das Programm rtm_pi muss als user **root** ausgeführt werden.    
Daher auch den code von von GitHub als user root runterladen und das Programm als user root mit make erzeugen**   
Dies ist im Folgenden durch den Befehl sudo -i sichergestellt.

## Schritt 1: raspberry code von Github auf den raspberry kopieren


Zunächst Anmmeldung im raspberry wie gewohnt als user **pi** mit password **raspberry**     
Nachdem wir als user pi angemeldet sind, wechseln zum user **root** mit   
**sudo -i**

Verzeichnis git erstellen mit    
**mkdir git**

In Verzeichnis git wechseln mit    
**cd git**

Code von GitHub auf den raspberry kopieren mit   
**git clone https://github.com/PeterDirnhofer/500-rtm-pi-code.git**

## Schritt 2: Programm rtm_pi erstellen mit make 
Bei Bedarf wechseln vom user pi zum user root mit    
**sudo -i**

Wechseln in Verzeichnis **500-rtm-pi** mit dem Befehl   
**cd ~/git/500-rtm-pi-code/500-rtm-pi**

Den runtergeladenen Code kompilieren und daraus das Programm **rtm_pi** erstellen mit dem Befehl   
**make**

## Schritt 3: Kontrolle ob das Programm rtm_pi erzeugt wurde bzw. bereits vorhanden ist  
Bei Bedarf wechseln vom user pi zum user root mit    
**sudo -i**

Wechseln in Verzeichnis **500-rtm-pi** mit dem Befehl   
**cd ~/git/500-rtm-pi-code/500-rtm-pi**

Test-Aufruf des Programms rtm_pi mit   
**./rtm_pi**   
Das Programm sollte antworten mit        
**SPI setup successful**    

Beenden des Programms mit **Strg C**
