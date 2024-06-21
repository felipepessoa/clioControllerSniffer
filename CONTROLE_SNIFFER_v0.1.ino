/*
* Vol - == Red & Yellow
* Vol + == Red & Blue
* Mute == Black & Blue
* Enter == Red & Green
* SRC FWD == Yellow &  Black
* SRC BWD == Black & Green
* Wheel == Green e Brown
*/

// ANALOG INPUT
const uint8_t BLACK = A0;
const uint8_t BROWN = A1;
const uint8_t RED = A2;

//DIGITAL OUTPUT
const uint8_t YELLOW = 5;
const uint8_t BLUE = 6;
const uint8_t GREEN = 7;

const uint8_t INPUTS[3] = {BLACK,BROWN, RED};
const uint8_t OUTPUTS[3] = {YELLOW,BLUE, GREEN};

const String COMMAND_BTN[9] = {
  "VOLUME_DOWN",
  "VOLUME_UP",
  "MUTE",
  "ENTER",
  "MOVE_FOWARD",
  "MOVE_BACKWARDS"
  "CMD_WHEEL_1",
  "CMD_WHEEL_2",
  "CMD_WHEEL_3"
};



void setup() {
  Serial.begin(9600);

  Serial.println("Start...");

  setUpInputPins();
  setUOutputPins();


}


void loop() {
  updateCommands();
}

void setUpInputPins() {
  for (uint8_t i = 0; i < INPUTS; i++) {
    pinMode(INPUTS[i], INPUT);
  }
}

void setUOutputPins() {
  for (uint8_t i = 0; i < OUTPUTS; i++) {
    pinMode(OUTPUTS[i], OUTPUT);
  }
}

void updateCommands(){

  int readed = 0;

  for (uint8_t i = 0; i < OUTPUTS; i++){
    
    digitalWrite(OUTPUTS[i], HIGH);
    
    for (uint8_t j = 0; j < INPUTS; j++){
      Serial.print(OUTPUTS[j]);
      Serial.print("------");
      Serial.print(INPUTS[j]);
      Serial.print("--->");
      Serial.println(analogRead(INPUTS[j]));
    }

    digitalWrite(OUTPUTS[i], LOW);
  }

}

