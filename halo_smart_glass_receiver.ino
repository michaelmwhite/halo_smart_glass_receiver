const byte MAX_MESSAGE_LENGTH = 64;
const char MESSAGE_TERMINATOR = '!';
char messageBuffer[MAX_MESSAGE_LENGTH];
byte index = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("< Running Halo Smart Glass Receiver >");
  initScreenController();
}
void loop()
{
  char data;
  while (Serial.available() > 0) {
    data = Serial.read();
    if(data != MESSAGE_TERMINATOR){
      messageBuffer[index] = data;
      index++;
    }else{
      messageBuffer[index] = '\0';
      Serial.println(messageBuffer);
      showText(messageBuffer);
      index = 0;
    }
  }
}
