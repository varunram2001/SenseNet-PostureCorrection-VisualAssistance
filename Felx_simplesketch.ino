const int flexPin = A0;		
const float VCC = 5;	
const float R_DIV = 47000.0;	
const float flatResistance = 25000.0;	
const float bendResistance = 100000.0;	
void setup() {
	Serial.begin(9600);
	pinMode(flexPin, INPUT);
}

void loop()
 {

	int ADCflex = analogRead(flexPin);
	float Vflex = ADCflex * VCC / 1023.0;
	float Rflex = R_DIV * (VCC / Vflex - 1.0);
	Serial.println("Resistance: " + String(Rflex) + " ohms");
	float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);
	Serial.println("Bend: " + String(angle) + " degrees");
	Serial.println();

	delay(500);
}