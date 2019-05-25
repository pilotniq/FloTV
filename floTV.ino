/*
  FloTV

  For ATTiny85 processor

  Dedicated to Florian Biesinger
  
  Most code copied from https://forum.arduino.cc/index.php?topic=148967.0
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  int i;
  for( i = 0; i < 2; i++ )
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

  // fade on
  for( i = 0; i < 255; i++ )
  {
    analogWrite( 0, i );
    analogWrite( 1, i );
    delay( 10 );
  }
}

void switchAll( int state )
{
  int i;
  
  for( i = 0; i < 6; i++ )
    digitalWrite( i, state );  
}


void whiteScene()
{
  digitalWrite( 0, HIGH );
  digitalWrite( 1, HIGH );

  delay( 1000 );
}

// fade in
void scene2()
{
  int i;

  for( i = 0; i < 255; i++ )
  {
    analogWrite( 0, i );
    analogWrite( 1, i );
    delay( 20 );  
  }
}

// flickering
void scene3()
{
  boolean sw = HIGH;
  for(int i=0;i<30;i++)
  {
    digitalWrite(0,sw);
    digitalWrite(1,sw);
    sw = !sw;
    delay(random(50,300));
  } 
}

// 
void scene4()
// Changes red/grn light levels only
// wht/blu are off
{
  int randpwm;
  
  //don't use wht/blu
  // digitalWrite(0,LOW);
  // digitalWrite(1,LOW);
  for(int i=0;i<12;i++)
  {
    randpwm = random(20,255);
    analogWrite(0,randpwm); 
    // analogWrite(red2,randpwm); 
    randpwm = random(20,255);
    analogWrite(1,randpwm); 
    // analogWrite(grn2,randpwm); 
    delay(random(200,2000));
  }
}

// Simulates a switch to or from a commercial break 
void commercial()
{
  analogWrite(0,2); 
  analogWrite(1,2);
  delay(random(1000,2500));
}  

// the loop function runs over and over again forever
void loop() {

  for(int i=0;i<10;i++)  //play scene 1 multiple times
    whiteScene();

  if (random(2) == 1)  //Possibly call scene 2
    scene2();

  if (random(2) == 1)  //Possibly call scene 3
    scene3();

  if (random(2) == 1)  //Possibly call scene 4
    scene4();

  if (random(4) == 1)  //Possibly do a commercial break
    commercial();
#if 0 
    for(int i=0;i<10;i++)  //play scene 1 multiple times
  {
    scene1();
  }
  if (random(2) == 1)  //Possibly call scene 2
  {
    scene2();
  }
  if (random(2) == 1)  //Possibly call scene 3
  {
    scene3();
  }
  if (random(2) == 1)  //Possibly call scene 4
  {
    scene4();
  }
  if (random(4) == 1)  //Possibly do a commercial break
  {
    commercial();
  }
  analogWrite( 0, 10 );
  analogWrite( 1, 10 );
  analogWrite( 2, 10 );
  delay( 500 );

  analogWrite( 0, 100 );
  analogWrite( 1, 100 );
  analogWrite( 2, 100 );
  delay( 500 );

  analogWrite( 0, 255 );
    analogWrite( 1, 255 );
  analogWrite( 2, 255 );

  delay( 500 );
  
  // switchAll( HIGH );
  
  // digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  // delay(1000);
  // switchAll( LOW );
  // wait for a second
  // digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  // delay(1000);                       // wait for a second
#endif
}
