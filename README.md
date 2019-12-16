# CPSC-334-Final

## Table of Contents  
* [Idea](#idea)  
* [Development](#development)
  * [Hardware/Electronics](#hardware)
  * [Code](#code)
* [Final Results](#final)
* [Difficulties](#difficulties)

<a name="idea"/>

## Idea

For the final project, I decided to go with sound since I find that a little bit more challenging for me. I went in a completely different direction from my initial proposal, and more details regarding that will be explained under Difficulties. 

Using rubber bands strung along two wooden boards, I decided to make a stringed instrument where you have to pluck it to play music. That is how the title Pizzicato, a playing technique that involves plucking the strings of a string instrument, came about.

<a name="development"/>

## Development

<a name="hardware"/>

### Hardware/Electronics

List of materials:
1. ESP32
2. Raspberry Pi 3 B+
3. Piezoelectric sensors (9)
4. 2 end connectors (9)
5. 1MΩ resistor (9)
6. Speakers

The following diagram is what I followed for wiring the piezoelectric sensors. The piezo is grounded on one end and the generated voltage is routed to an analog to digital input pin on the ESP32. It also requires a 1MΩ resistor. The leads of the piezo are very small and not sturdy enough to actually insert into the bread board, so I soldered a 2-end connector to each piezo. The connectors at the white blocks you can see in the later images.

![Final](/images/example.png)

I went through a few different configurations for the piezos. I initially had them lined up in 3 rows as in the picture below and strung the rubber bands (the red lines) horizontally. Depending on where on the rubber band the user plucks, a different sound would be output, but when I tested that out, the rubber band would make contact with all the piezos in the row and activate multiple sounds, so I have to change the configuration. 

![Sketch](/images/sketch.jpg)

I lined up the piezos horizontally in one line and taped it down onto a piece of wood using electric tape. Going with this setup, I ended up stringing a rubber band for each piezo, so that when the user plucks a rubber band, it does not interfere with the other sensors.

![Setup](/images/IMG_0662.jpg)

I attached two pieces of wood along the horizontal ends to have a base to which I could attach the rubbers. I had to make holes to loop and tie the rubber bands, but I also had to make extra holes to run the leads of the piezos and reach my bread board, which I hide away in my cardboard box later.

![Box](/images/IMG_0666.jpg)

A closer look at my wiring can be seen below. The white blocks are the connectors I mentioned at the beginning, and they helped out a lot. I ran ground from the ESP32 to the bread board, and used jumper cables to attach each piezo to an input pin. I ran into problems when I placed connectors right next to each other or if I used certain GPIO pins right next to one another, but that just required spacing out my circuit.

![Wire1](/images/IMG_0663.jpg)

![Wire2](/images/IMG_0664.jpg)

<a name="code"/>

### Code

Now that the hardware/electronics are done, I went to work on the code. It was a bit difficult reading in the voltage from the piezo because every time I would touch it, it would read the max voltage numerous times, so I had to filter out the data in the arduino code. Even then, I still ran into some problems, but it all sorted itself out in the end due to these reasons:

Plucking a rubber band reduced the time of contact with the piezo unlike having someone actually touch it because the snap would happen so quickly.
You will see later, but I added a black construction paper on top of the piezo, mostly for aesthetic purposes, and that helped a lot with reading the voltage. By having another layer, it acted almost like a dampener and allowed me to read one value per pluck.
Once I had that working, I had to use that input to make sound. I initial tried to use SuperCollider and have communication through OSC, but that was a bit too difficult and the functionality of SuperCollider was outside the scope of my project. With suggestions from peers, I decided to use SonicPi, a live coding environment pre-installed on my Raspberry Pi. I installed a python3 library called python-sonic that allows me to work with SonicPi within my python code. With that, I was able to read messages from my ESP32 through serial and process and play sounds with SonicPi all in one script. This link was very helpful for setting up python-sonic and using it on the pi.

I made it so that each piezo corresponded to a different note from G4 to G5. Just being able to pluck 9 notes was not that interesting, so I wanted to add a little bit more interactivity and excitement by having a “surprise” mode. If the user plays certain notes in specific order (which turns out to be the beginning of a song), then the code would recognize it and complete it for them. The songs included are: Dance of the Sugar Plum Fairy, the Mario theme song, and We Wish You a Merry Christmas.

<a name="final"/>

## Final Product 

The image below is the final product! I connected my ESP32 to the pi, read the messages in serially, and used the audio jack on the pi to connect speakers and output the sounds. I used a cardboard box to not only hide the wires and electronics away, but to also use it as a “hint” for the users, so they could play the special combos.

![Final](/images/IMG_0667.jpg)

In the demo video below, you can hear Yuki plucking all the “surprise” combos.

[Demo](https://www.youtube.com/watch?v=Ztg3LrGs4-8)

<a name="difficulties"/>

## Difficulties

I had the hardest time in the beginning when I was unsure of my idea. I tried to pursue my initial idea for the longest time. For a refresher, my initial idea was to have string dangling from something, and when the user run their hands through the strings, it plays musical notes based on their starting point and direction they move. I tried using the piezos as the sensors for this, and it was not going well. This was also the during the period I was trying to learn SuperCollider for the first time, and as mentioned earlier, that was a bad choice. I scrapped that idea altogether and created this plucking instrument. Because I was so fixated on using piezos for my first project, I ended up using them for the instrument, but I wonder if a simple capacitive touch sensor would have been better.
