import processing.serial.*;

PrintWriter output;
Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port
String currentval;


void setup()
{
  // I know that the first port in the serial list on my mac
  // is Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  output = createWriter("data.csv");
  String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 115200);
  val = "0";
  
  output.println("Trial,TrialType,HIT,Correct,TimeHit");
}

void draw()
{
  if (myPort.available() > 0) 
  {  // If data is available,
  currentval = myPort.readStringUntil('\n');         // read it and store it in val
  print(currentval);
  } 
  if (currentval != val){
    if (currentval != null){
      output.print(currentval); //print it out in the console
      val = currentval;
    }
  }
}

void keyPressed() {
  output.flush(); // Writes the remaining data to the file
  output.close(); // Finishes the file
  exit(); // Stops the program
}
