**Particle IDE MicroController JSON formatter**

Hey there, so you're probably trying to use Particle IO and get your Data out in a JSON format but having some trouble doing so.
Don't worry, I have made something to help you out with this.

**Important Notes**                                                                                     
***1. Checking my code.*** This can be done at any time by clicking the check mark icon at the top left in the Particle IDE. If all is good, it will "Code Verified! Great work." If not, you will get a list of errors. Please work through these errors or check again in documentation to make sure you haven't forgotten or done something incorrectly.             
***2. Your variable declarations*** Please make sure all your variables are declared globally. I would recommend doing this after the line of code ``builder build`` which you will see in Step 2.

**Step 1** Creating a duplicate version of your current code. [Click here for a video Tutorial](https://www.youtube.com/watch?v=QuAGKQYp_mc) . The video tutorial will show you how this is done, please follow directions **EXACTLY.**       
**Tutorial Steps:**          
**1a.** Click on the code icon on the left hand toolbar in Particle IDE ---> Share this Revision ---> Get Shareable Link ---> Copy link, open new tab, and go to link.                       
**1b.** You now have the same exact code you had before duplicated and opened up in another tab. On the left hand, you will see "Copy this app". Click it. The name however will be the exact same as your prior app and to seperate it, click on the name of your app at the top of the left hand toolbar and rename it or add "test" for example. 
1c. Click back into your code box, everything is now saved and if you click on the Code icon again, you will see under "My Apps" you will have your original file and this new testbench duplicate file. 

**Step 2.** Please include the following code **AFTER YOUR #INCLUDE STATEMENTS.**

```c++
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
```
**Step 3**                   So what now? With the line ```builder build``` you have now created what's called an instance using the class ``builder``. Now in your INO file's `` void loop()`` function, you are going to add your variable names and display everything.    
Please follow the following format for adding:
```objectinstance.add("Insert Event Name", variablename);```
**The objectinstance is whatever you call your instance that you declare by using your class object. So for example, the class  is called ```builder``` so my objectinstance would be called ```build``` for example which you will see later down below.**
In "Insert Event Name", you want to put whatever you would want your Event to be called. So for example if your variable ```int temp``` 
is recording temperautre, you would want the event name to say Temparature, right? In "variablename", you want to fill in whatever the name of your variable is.
So in this example, it would be ```int temp```. Depending on how you have your variables declared, if you do come across an issue saying the Data Type is wrong or doesn't match String
please use the following line of code to fix that issue ```String(variablename)```. So it would then be ```add("Insert Event Name", String(variablename));```
and that should fix the issue. 

**Step 4** Example of how to use add function to add variable names.                         
***Step 4a*** So once again, the class name is ``builder`` but the instance we create is called ``build`` which must be used EVERYTIME you use a variable that belongs to the class. ``build`` can be changed to whatever you'd like however ``builder`` can **NOT** be changed. 
```
//This is just an example to show you how to add to "payload"
void loop()
{
 //your loop code that was there prior
 
  String testvar = " ";//EXAMPLE VARIABLE DO NOT NEED TO INCLUDE
  int temp = 20;//EXAMPLE VARIABLE DO NOT NEED TO INCLUDE
  
  build.add("Test", testvar); //This is just an EXAMPLE to show you how to use the add function. 
  build.add("Temp", String(temp));
  build.add("Humidity", "40%");
  build.send(); //Particle Publish all your data. Look at step 4b for further explanation on how this works
}

```

**Step 4b** Displaying your Data                
To see what values you are now recieving through your variables and microcontroller, you will use the ```send()``` function.
Paste the following line of code after all of your ```add()``` statements in ```void setup()```:
```objectinstance.send(payload);```
This line will take in everything you have put into Payload and format it into JSON formatting. This will also ```Particle.publish``` it so you can see it when you go to the events tab in Particle.



**Questions?**
Feel free to ask me any and all questions by reaching out to me via the following places:
[Twitter](http://twitter.com/mvhxmxd)
[Instagram](http://instagram.com/mvhxmmvd)
**Email** mvhxmmd@gmail.com
or just drop a comment below!
