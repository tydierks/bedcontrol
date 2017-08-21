/*Bed Controls V2*/

#define pushButton 2
#define relay1 7
#define relay2 9
#define relay3 10
#define relay4 11

long startTime = 0;
long timeOut = 0;
int endTime = 1000;

void setup() {
    Serial.begin(9600);
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);
    pinMode(pushButton, INPUT);
    digitalWrite(relay1, HIGH);
    delay(100);
    digitalWrite(relay2, HIGH);
    delay(100);
    digitalWrite(relay3, HIGH);
    delay(100);
    digitalWrite(relay4, HIGH);
    delay(1000);  
    digitalWrite(relay1, LOW);
    delay(100);
    digitalWrite(relay2, LOW);
    delay(100);
    digitalWrite(relay3, LOW);
    delay(100);
    digitalWrite(relay4, LOW);
    delay(100);
    Serial.println("program started");  
}

void loop() {
    if (digitalRead(pushButton) == HIGH) {
        Serial.println("loop started");
        startTime = millis();
        timeOut = startTime + 5000;
            while (startTime < timeOut) {
                adjustOne();
                while (digitalRead(pushButton) == LOW) {
                //Do nothing. This method is hack-ey but ensures program will wait for the user to press button again
                }
                if (digitalRead(pushButton) == HIGH) {
                    startTime = millis();
                    timeOut = startTime + 5000;
                    adjustTwo();
                }
                while (digitalRead(pushButton) == LOW) {
                //Do nothing. This method is hack-ey but ensures program will wait for the user to press button again
                }
                if (digitalRead(pushButton) == HIGH) {
                    startTime = millis();
                    timeOut = startTime + 5000;
                    adjustThree(); 
                }
                while (digitalRead(pushButton) == LOW) {
                //Do nothing. This method is hack-ey but ensures program will wait for the user to press button again
                }
                if (digitalRead(pushButton) == HIGH) {
                    startTime = millis();
                    timeOut = startTime + 5000;
                    adjustThree();
                }
                while (digitalRead(pushButton) == LOW) {
                    //Do nothing. This method is hack-ey but ensures program will wait for the user to press button again
                    }
                if (digitalRead(pushButton) == HIGH) {
                    startTime = millis();
                    timeOut = startTime + 5000;
                    adjustFour();
                }
            delay(endTime);
            break;
            }
            Serial.println("loop finished");
    }
}

void adjustOne() {
    delay(1000);
    if (digitalRead(pushButton) == HIGH) {
        while (digitalRead(pushButton) == HIGH) {
            startTime = millis();
            timeOut = startTime + 5000;
            digitalWrite(relay1, HIGH);
        }
    }
    digitalWrite(relay1, LOW);
    return;
}

void adjustTwo() {
    delay(1000);
    if (digitalRead(pushButton) == HIGH) {
        while (digitalRead(pushButton) == HIGH) {
            startTime = millis();
            timeOut = startTime + 5000;
            digitalWrite(relay2, HIGH);
        }
    }
    digitalWrite(relay2, LOW);
    return;
}

void adjustThree() {
    delay(1000);
    if (digitalRead(pushButton) == HIGH) {
        while (digitalRead(pushButton) == HIGH) {
            startTime = millis();
            timeOut = startTime + 5000;
            digitalWrite(relay3, HIGH);
        }
    }
    digitalWrite(relay3, LOW);
    return;
}

void adjustFour() { 
    delay(1000);
    if (digitalRead(pushButton) == HIGH) {
        while (digitalRead(pushButton) == HIGH) {
            startTime = millis();
            timeOut = startTime + 5000;
            digitalWrite(relay4, HIGH);
        }
    }
    digitalWrite(relay4, LOW);
    return;
}