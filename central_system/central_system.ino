#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

#include <SD.h>
#include <SPI.h>

#define SD_ChipSelectPin 53
// Note must refactor code to make it more DRY, 
// replace booleans with an array? Look into that, due to lack of time leave it as is
TMRpcm tmrpcm;   // create an object for use in this sketch
int pinDo = 30;
int pinRe = 31;
int pinMi = 32;
int pinFa = 33;
int pinSo = 34;
int pinLa = 35;
int pinTi = 36;
int pinDo2 = 37;
int previousNote;
int currentNote;

bool isSameDo = false;
bool isSameRe = false;
bool isSameMi = false;
bool isSameFa = false;
bool isSameSo = false;
bool isSameLa = false;
bool isSameTi = false;
bool isSameDo2 = false;
bool disabledDo = false;
bool disabledRe = false;
bool disabledMi = false;
bool disabledFa = false;
bool disabledSo = false;
bool disabledLa = false;
bool disabledTi = false;
bool disabledDo2 = false;

void setup()                    
{
    tmrpcm.speakerPin = 6;
  
    Serial.begin(9600);
    if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
      Serial.println("SD fail");  
      return;   // don't do anything more if not
    }

    for(int x = 29; x<36; x++){
      pinMode(x,INPUT);
    }

}

void loop()                    
{ 
 debugCode();
//--------------------------------------------------------------------------------------------------------------------------// Each if statment is for each note on the scale, it is used to control when the note is played and whether the note is repeated.
    if(isSameDo == true && digitalRead(pinDo) == HIGH && tmrpcm.isPlaying() == false && disabledDo == false){
      tmrpcm.play("piano-c.wav");
      Serial.print("Playing c");
      disabledDo = true;

    }
    else if (isSameDo == false && digitalRead(pinDo) == HIGH  ){
      isSameDo = true;
      currentNote = 1;
    }
    else if (isSameDo == true && digitalRead(pinDo)== LOW)
    {
      isSameDo = false;
      tmrpcm.stopPlayback();
      disabledDo = false;
    }
//--------------------------------------------------------------------------------------------------------------------------
    if(isSameRe == true && digitalRead(pinRe)== HIGH && tmrpcm.isPlaying() == false && disabledRe == false){
      tmrpcm.play("piano-d.wav");
      Serial.print("Playing d");
      disabledRe = true;
    }
    else if (isSameRe == false && digitalRead(pinRe) == HIGH ){
      isSameRe = true;
      currentNote = 2;
    }
    else if (isSameRe == true && digitalRead(pinRe)== LOW)
    {
      isSameRe = false;
      tmrpcm.stopPlayback();
      disabledRe = false;
    }
//--------------------------------------------------------------------------------------------------------------------------
    if(isSameMi == true && digitalRead(pinMi)== HIGH && tmrpcm.isPlaying() == false && disabledMi == false){
      tmrpcm.play("piano-e.wav");
      Serial.print("Playing e");
      disabledMi = true;
    }
    else if (isSameMi == false && digitalRead(pinMi) == HIGH ){
      currentNote = 3;
      isSameMi = true;
    }
    else if (isSameMi == true && digitalRead(pinMi)== LOW)
    {
      isSameMi = false;
      tmrpcm.stopPlayback();
      disabledMi = false;
    }
//--------------------------------------------------------------------------------------------------------------------------
    if(isSameFa == true && digitalRead(pinFa)== HIGH && tmrpcm.isPlaying() == false && disabledFa == false){
      tmrpcm.play("piano-f.wav");
      Serial.print("Playing f");
      disabledFa = true;
    }
    else if (isSameFa == false && digitalRead(pinFa) == HIGH  ){
      currentNote = 4;
      isSameFa = true;
    }
    else if (isSameFa == true && digitalRead(pinFa)== LOW)
    {
      isSameFa = false;
      tmrpcm.stopPlayback();
      disabledFa = false;
    }
//--------------------------------------------------------------------------------------------------------------------------
    if(isSameSo == true && digitalRead(pinSo)== HIGH && tmrpcm.isPlaying() == false  && disabledSo == false){
      tmrpcm.play("piano-g.wav");
      Serial.print("Playing g");
      disabledSo = true;
    }
    else if (isSameSo == false && digitalRead(pinSo) == HIGH ){
      currentNote = 5;
      isSameSo = true;
    }
    else if (isSameSo == true && digitalRead(pinSo)== LOW)
    {
      isSameSo = false;
      tmrpcm.stopPlayback();
      disabledSo = false;
    }
//--------------------------------------------------------------------------------------------------------------------------
    if(isSameLa == true && digitalRead(pinLa)== HIGH && tmrpcm.isPlaying() == false  && disabledLa == false){
      tmrpcm.play("piano-a.wav");
      Serial.print("Playing a");
      disabledLa = true;
    }
    else if (isSameLa == false && digitalRead(pinLa) == HIGH ){
      currentNote = 6;
      isSameLa = true;
    }
    else if (isSameLa == true && digitalRead(pinLa)== LOW)
    {
      isSameLa = false;
      tmrpcm.stopPlayback();
      disabledLa = false;
    }
//--------------------------------------------------------------------------------------------------------------------------
    if(isSameTi == true && digitalRead(pinTi)== HIGH && tmrpcm.isPlaying() == false  && disabledTi == false){
      tmrpcm.play("piano-b.wav");
      Serial.print("Playing b");
      disabledTi = true;
    }
    else if (isSameTi == false && digitalRead(pinTi) == HIGH ){
      currentNote = 7;
      isSameTi = true;
    }
    else if (isSameTi == true && digitalRead(pinTi)== LOW)
    {
      isSameTi = false;
      tmrpcm.stopPlayback();
      disabledTi = false;
    }
//--------------------------------------------------------------------------------------------------------------------------
    if(isSameDo2 == true && digitalRead(pinDo2)== HIGH && tmrpcm.isPlaying() == false && disabledDo2 == false){
      tmrpcm.play("piano-c.wav");
      Serial.print("Playing c");
      disabledDo2 = true;
    }
    else if (isSameDo2 == false && digitalRead(pinDo2) == HIGH ) {
      isSameDo2 = true;
      currentNote = 8;
    }
    else if (isSameDo2 == true && digitalRead(pinDo2)== LOW)
    {
      isSameDo2 = false;
      tmrpcm.stopPlayback();
      disabledDo2 = false;
    }

    samePreviousNote(currentNote);
}

//This Function checks if the previous note played is the same note as the current note
void samePreviousNote(int currentNote){
  if (currentNote != previousNote)
  {
    //tmrpcm.stopPlayback();
    previousNote = currentNote; 
  }
    //resetDisabled();
    //setDisabledState(currentNote);
  
}
// This function sets a disabled state for each note to prevent repeated playing if panel is stepped on continuously
void setDisabledState(int currentNote){
  Serial.println("Setting disabled state on: ");
  Serial.print(currentNote);
  
  switch(currentNote){
    case 1:
      disabledDo = true;
    break;
    case 2:
      disabledRe = true;
    break;
    case 3:
      disabledMi = true;
    break;
    case 4:
      disabledFa = true;
    break;
    case 5:
      disabledSo = true;
    break;
    case 6:
      disabledLa = true;
    break;
    case 7:
      disabledTi = true;
    break;
    case 8:
      disabledDo2 = true;
    break;
  }
}

// Reset all the disabled states
void resetDisabled(){
  Serial.print("Resetted!");
  bool disabledDo = false;
  bool disabledRe = false;
  bool disabledMi = false;
  bool disabledFa = false;
  bool disabledSo = false;
  bool disabledLa = false;
  bool disabledTi = false;
  bool disabledDo2 = false;
}

void debugCode(){
      Serial.println(digitalRead(pinDo));
    Serial.print("  ");                    
    Serial.print(digitalRead(pinRe));
    Serial.print("  ");                    
    Serial.print(digitalRead(pinMi));
    Serial.print("  ");                    
    Serial.print(digitalRead(pinFa));
    Serial.print("  ");                    
    Serial.print(digitalRead(pinSo));
    Serial.print("  ");                    
    Serial.print(digitalRead(pinLa));
    Serial.print("  ");                    
    Serial.print(digitalRead(pinTi));
    Serial.print("  ");                    
    Serial.print(digitalRead(pinDo2));
    Serial.print("  ");
    Serial.print("  ");
}








