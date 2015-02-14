/**
all the json values are expecting to have the JSON where all the lables are 
STEING values and all the values are  Number values 
**/

boolean toggleComplete = false;
boolean pwmComplete = false;
String inputString;
char endChar = 'z';
char beginChar = 'q';
String value;
String lable;


void setup()
{
	Serial.begin(9600);
}

void  loop()
{
	while(Serial.available()){
		char newChar = (char)Serial.read();
		if (newChar == beginChar){
			value  = "";
			lable = "";
			inputString = "";
		}
		else if (newChar == endChar){
			toggleComplete = true;
			}
                else{
           		inputString += newChar; 
			}
		}

	if(toggleComplete == true){
               	getCommand(inputString);
		Serial.println("lable: " + lable);
		Serial.println("value: " + value);
		toggleComplete = false; 
	}

}
void getCommand(String stringValue){ 
	boolean isLable = false;
	boolean isValue = false;
	boolean end = false;
	for (int i=0; i<stringValue.length(); i++){
		char eachChar = stringValue.charAt(i);

		if((char)eachChar == '}'){
			break;
		}
		if(eachChar == '{'){
			isLable = true;
			isValue = false;
		}
		if (eachChar == ':'){
			isLable = false;
			isValue = true;
		}

		if(isLable && eachChar != '{'){
			lable += eachChar;
		}
		if(isValue && eachChar != ':'){
			value += eachChar;
		}

	}
}


