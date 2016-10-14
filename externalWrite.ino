
void writeToExternal(){


ThingSpeak.setField(1,ethanolValue);
ThingSpeak.setField(2,cO2Value);  
ThingSpeak.setField(3,analogTempValue);
ThingSpeak.setField(4,intTH[0]);
ThingSpeak.setField(5,intTH[1]);
ThingSpeak.setField(6,DSTemp);


 ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);  

}

