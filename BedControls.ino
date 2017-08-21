/*Bed Controls*/

/*This version of the bed controls provides no visual feedback. User presses the button to cycle through relays. Pressing and holding activates the current relay until
 * the button is released. The program will time out if there is no input for a preset amount of time (adjusted with potentiometer). Should be fairly easy to modify the 
 * software for additional relays.
 */

#define pushButton 2
#define relay1 7
#define relay2 9
#define relay3 10
#define relay4 11
#define timingPot A0


//Tuning constants//
const int timeMultiplier = 10;      //Allows for a wider/narrower time out range with the potentiometer. Without multiplier, range is between 0-1 sec. (ex. timeMultiplier = 10 then time out range is 0-10 sec.) 
const int delayTime = 250;          //Delay before program checks if button is still held. If this value is high, the user must hold down the button longer before relay is activated.
                                       //If this value is too low the user may accidentally trigger the relay before while cycling.

//Variable Declaration//
long startTime = 0;                //Stores time of first button press.
long timeOut = 0;                  //Time before program times out and restarts the program. Adjusted with pot.
   

void setup() {
    //Serial.begin(1200);
    pinMode(relay1, OUTPUT);
    digitalWrite(relay1, HIGH);
    pinMode(relay2, OUTPUT);
    digitalWrite(relay2, HIGH);
    pinMode(relay3, OUTPUT);
    digitalWrite(relay3, HIGH);
    pinMode(relay4, OUTPUT);
    digitalWrite(relay4, HIGH);
    pinMode(pushButton, INPUT);
    pinMode(timingPot, INPUT);
    //Serial.println("program started");  
}

void loop() {

    start:   //If the device times out at any point, the program is routed back here. Waits for another button press.
    
    if (digitalRead(pushButton) == HIGH) {
       timeOut = analogRead(timingPot);
       timeOut = timeOut*timeMultiplier;
       //Serial.println(timeOut);
            adjustOne();
            delay(100);   //Debounce

            if (digitalRead(pushButton) == LOW) {
                startTime = millis();   //timer starts
                while (millis() - startTime <= timeOut) {
                    if (digitalRead(pushButton) == HIGH) {
                        break;   //If input goes HIGH, break from while loop.
                    }
                }
                if (millis() - startTime > timeOut) {
                    //Serial.println("timed out");
                    goto start;
                }
            }

            if (digitalRead(pushButton) == HIGH) {
                adjustTwo();
                delay(100); //Debounce
                }
             
                if (digitalRead(pushButton) == LOW) {
                    startTime = millis();
                    while (millis() - startTime <= timeOut) {
                        if (digitalRead(pushButton) == HIGH) {
                            break;
                        }
                        }
                    if (millis() - startTime > timeOut) {
                        Serial.println("timed out");
                        goto start;
                    }
                }

            if (digitalRead(pushButton) == HIGH) {
                adjustThree();
                delay(100); //Debounce
            }
    
            if (digitalRead(pushButton) == LOW) {
                //Serial.println("timer started");
                while (millis() - startTime <= timeOut) {
                    if (digitalRead(pushButton) == HIGH) {
                        break;
                    }
                    }
                if (millis() - startTime > timeOut) {
                    //Serial.println("timed out");
                    goto start;
                }
            }
            if (digitalRead(pushButton) == HIGH) {
                adjustFour();
                delay(100); //Debounce
            }
            //Serial.print("Loop Finished!");
    }
}


//Used to activate relay. All following adjustment functions are same.
void adjustOne() {
    delay(delayTime);  //If input is HIGH after this delay, program assumes the user intended to activate the relay.
    if (digitalRead(pushButton) == HIGH) {
        while (digitalRead(pushButton) == HIGH) {
            digitalWrite(relay1, LOW);   //Remains closed as long as button is held.
        }
    }
    digitalWrite(relay1, HIGH);  //Otherwise, program skips this relay and returns.
    return;
}

void adjustTwo() {
    delay(delayTime);  
    if (digitalRead(pushButton) == HIGH) {
        while (digitalRead(pushButton) == HIGH) { 
            digitalWrite(relay2, LOW);  
        }
    }
    digitalWrite(relay2, HIGH);  
    return;
}

void adjustThree() {
    delay(delayTime);  
    if (digitalRead(pushButton) == HIGH) {
        while (digitalRead(pushButton) == HIGH) {
            digitalWrite(relay3, LOW); 
        }
    }
    digitalWrite(relay3, HIGH); 
    return;
}

void adjustFour() { 
    delay(delayTime);
    if (digitalRead(pushButton) == HIGH) {
        while (digitalRead(pushButton) == HIGH) {
            digitalWrite(relay4, LOW); 
        }
    }
    digitalWrite(relay4, HIGH); 
    return;
}
