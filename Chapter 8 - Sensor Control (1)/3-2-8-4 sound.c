/* SKU CoE ITE - ParkSooYoung */
/* Grade 3 , Semester 2 , Chapter 8 , Number 4 */

#include <stdio.h>
#include <wiringPi.h>

#define SOUND_PIN 18

int readSound(int nPin)
{
    int nSoundVal = 0;

    nSoundVal = digitalRead(nPin);

    if(nSoundVal == HIGH)
    {
        printf("Sound Detected!\n");
    }
    else
    {
        printf("No Sound Detected!\n");
    }

    return nSoundVal;
}

int main(void)
{
    if(wiringPiSetupGpio() == -1)
    {
        printf("Unable to start wiringPi GPIO : \n");

        return 1;
    }

    pinMode(SOUND_PIN, INPUT);

    while(1)
    {
        delay(100);

        readSound(SOUND_PIN);
    }

    return 0;
}
