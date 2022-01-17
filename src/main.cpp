
class dcPort
{
    // Variáveis membro da classe
    // São inicializadas no startup do programa
    int portPin;        // número do pino do LED
    int portAvailable;  // 
    long onTime;        // milissegundos do tempo ligado
    long offTime;
    // Essas mantém o estado atual
    int portState;                     // portState usada para guardar o estado do LED
    unsigned long previousMillis;      // vai guardar o último acionamento do LED
 
  public:
  dcPort(int pin)
  {
    portPin = pin;
    pinMode(portPin, OUTPUT);     
    onTime = 0;
    offTime = millis();  
    
    portAvailable = true;
    portState = LOW; 
    previousMillis = 0;
  }
  void turnOn(){
    if(portAvailable==true && portState==LOW){
      this->writeOn();
      onTime = millis();
      offTime= 0;
      
    }
    else{
      
    }
  }

  void turnOff(){
  if(portAvailable==false && portState==HIGH){
    this->writeOff();
     offTime = millis();
     onTime= 0;
  }
  else{
    
  }
  }
  getPortState(){
  return portState;
  }


  void writeOn(){
    digitalWrite(portPin, HIGH);
    Serial.println("WriteOn");
    portState = true;
    portAvailable = false;
  }
   void writeOff(){
    digitalWrite(portPin, LOW);
    Serial.println("WriteOff");
    portState = false;
    portAvailable = true;
    
  }

  getPortStateTime(){
    if(this->getPortState() == LOW){
      return millis() - offTime;
    }else{
      return millis() - onTime;
    }
  }


};
 dcPort dcPort1(53);
 dcPort dcPort2(52);

void setup()
{
  Serial.begin(9600);
}
  
void loop()
{
dcPort1.turnOn();
Serial.println(dcPort1.getPortState());
delay(1000);
Serial.println(dcPort1.getPortStateTime());
}