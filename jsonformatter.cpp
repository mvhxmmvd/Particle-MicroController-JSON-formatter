class builder
{
 public:
 void add(const String& key, const String& value); //This is our add function
 void send(); //This is our send function
 
 private:
 String payload = ""; //This will create a payload variable which will contain everything
};

//This function will add your keyvalue pairs to the payload variable while maintaining proper JSON format
void builder::add(const String& key, const String& value) 
{
    if (payload.length() > 1 )
    {
        payload+=",";
    }
    payload += "\"" + key + "\":\"" + value + "\"";
}

//This function will take in all key value pairs you have in "payload" and publish it in JSON format and then empty it.
void builder::send()
{
    payload = "{" + payload +"}";
    Particle.publish("Sensor", payload); //This line is what is responsible for showing you your data in the Particle Eventts
    payload = "";
}

builder build; //This line creates an instance of the class builder. The instance is called build. Refer to step 4a for further explanation.
