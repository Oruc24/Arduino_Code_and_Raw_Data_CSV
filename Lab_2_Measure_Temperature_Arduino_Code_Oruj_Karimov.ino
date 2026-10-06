// Lab 2 - Measure Temperature - Oruj Karimov

// Sets the time interval between each reading.
const unsigned long interval_length = 100;
// The desired total reading time.
const unsigned long total_time = 10000;
// Start time of the program.
unsigned long t_s = 0;
// Time in which the previous reading was taken.
unsigned long t_f = 0;
// The following boolean variable is so that the loop terminates once the final time of a reading is equal to the total time.
bool done = false;

void setup()
{
  Serial.begin(9600);                   // The speed in which the USB serial port transfers information is set to 9600 baud.
  t_s = millis();                       // Initialization of the start time of the program.
  t_f = t_s - interval_length;          // Initialization of the finish time such that the first value is included in the dataset.
}

void loop()
{
  if(done)
  {
  return;                               // Checks if the loop is done.
  }

  unsigned long now = millis();         // Represents current time.

  if(now - t_f >= interval_length)      // The conditional statement checks whether or not the desired interval_length time has passed for it to post readings in the serial monitor.
  {
    int sensorValue = analogRead(A0);   // ADC readings are assigned to sensorValue variable.
    unsigned long elapsed = now - t_s;  // Total time elapsed from the start of the program.

    Serial.print(elapsed);              // The following posts the elapsed time and the ADC readings as comma separated values (csv).
    Serial.print(',');
    Serial.println(sensorValue);

    t_f = now;                          // Lastly, we change the time of the last reading to be current time for the next iteration.
  }

  if(now - t_s >= total_time)           // Conditional statements indicates whether elapsed time has reached the set total time for the program.
  {
    done = true;                        // This activates the condition for the loop to terminate once this iteration is processed.
    return;
  }
}
