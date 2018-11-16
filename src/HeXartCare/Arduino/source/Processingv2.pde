  import processing.serial.*;

PrintWriter output;
Serial udSerial;

void closeProgram() {
    output.flush();
    output.close();
    exit(); 
}

void setup() {
  udSerial = new Serial(this, Serial.list()[0], 9600);
  output = createWriter ("pulsations.csv");
}

int timeStart = millis();
  void draw() {
    if (millis()-timeStart>1000) {
      output.flush();
      output.close();
      waitForFile();
      timeStart=millis();
      output = createWriter ("pulsations.csv");
    }
    if (udSerial.available() > 0) {
      String SenVal = udSerial.readString(); 
      if (SenVal != null) {
        output.println(SenVal);
      }
    }
  }

  void keyPressed(){
    closeProgram();
  }
  
  void waitForFile() {
    boolean b=true;
    do { //<>//
       delay(500); //<>//
      File f = new File("A:\\C++\\CESI\\Projets\\A1_1\\CInterface\\CInterface\\Arduino\\pulsations.csv");
      b = f.exists(); //<>//
      
    }while(b); //<>//
  }
