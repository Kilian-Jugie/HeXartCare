import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class Processingv2 extends PApplet {

  

PrintWriter output;
Serial udSerial;

public void closeProgram() {
    output.flush();
    output.close();
    exit(); 
}

public void setup() {
  udSerial = new Serial(this, Serial.list()[0], 9600);
  output = createWriter ("pulsations.csv");
}

int timeStart = millis();
  public void draw() {
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

  public void keyPressed(){
    closeProgram();
  }
  
  public void waitForFile() {
    boolean b=true;
    do { //<>//
       delay(500); //<>//
      File f = new File("A:\\C++\\CESI\\Projets\\A1_1\\CInterface\\CInterface\\Arduino\\pulsations.csv");
      b = f.exists(); //<>//
      
    }while(b); //<>//
  }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "Processingv2" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
