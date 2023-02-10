void updateTemperature()
{
//converting double to char array
double temp = 20 + random(1000) /100.0 ;
dtostrf(temp,6,2,tempAr);


}