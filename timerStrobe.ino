#define LED 3   //don't know why I'm using port 3 - someone will have an argument that this is wrong

hw_timer_t *pTimerOn=NULL;
hw_timer_t *pTimerOff=NULL;
uint32_t iFreq=1000000;  //1MHz - this means we are working in micro seconds

uint32_t iPeriod = 20000; // 20ms in micro seconds[1MHz clock speed] - this is 50Hz
//uint32_t iPeriod = 16667; // 16.667ms in micro seconds[1MHz clock speed] - this is 60Hz

uint32_t iPulseWidth = 2000; // 2ms in micro seconds [iMHz clock speed] the on time for the stobe

// the interrupt function to turn the LED on
void IRAM_ATTR LED_On()
{
    digitalWrite(LED, HIGH); // Turn the LED on

    timerWrite( pTimerOff, 0); // now setup the off timer to turn it off
    timerAlarm( pTimerOff , iPulseWidth , false , 0 ); // turn the LED off in iPulseWidth micro seconds
}

// interrupt function to turn the LED off
void IRAM_ATTR LED_Off()
{
    digitalWrite(LED, LOW); // but this does not give a nice mark space ratio
}


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);   // get rid of this when all is working
  Serial.println();
  Serial.println("running setup");

  //setup the LED
  pinMode(LED, OUTPUT);

  pTimerOn  = timerBegin( iFreq );
  if( pTimerOn == NULL)
      Serial.println("Failed to initialise On timer\n");
  
  pTimerOff = timerBegin( iFreq );
  if( pTimerOff==NULL)
      Serial.println("Failed to initialise Off timer\n");
  
  timerAttachInterrupt(pTimerOn, LED_On );
  timerAttachInterrupt(pTimerOff, LED_Off);
  
  // now triger the alarm
  timerAlarm(pTimerOn, iPeriod , true , 0);  //5000 for 50Hz and 4167 for 60Hz
}

void loop() {
  // put your main code here, to run repeatedly:

  // nothing to see here.

}
