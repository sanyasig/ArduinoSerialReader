/**
all the json values are expecting to have the JSON where all the lables are 
STEING values and all the values are  Number values 
**/

boolean toggleComplete = false;
boolean pwmComplete = false;
String inputString;
char endChar = 'e';
char beginChar = 'b';
char newChar;
void setup()
{
	Serial.begin(9600);
}

void  loop()
{
	while(Serial.available()){
		newChar = (char)Serial.read();
		if (newChar == beginChar){
			inputString = "";
		}
		else if (newChar == endChar){
			toggleComplete = true;
			}else{
				inputString += newChar; 
			}
		}

	if(toggleComplete == true){
		Serial.println(inputString);
		toggleComplete = false;
	}

}
