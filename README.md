# Easy Button NRF24L01 Button / Low Power TX
### Note: I have had a button like this sitting on my desk for 2years now and it still works just fine, it only gets used once a month or so.

#
![Staples Easy Button](/images/button.jpg)
This project is for putting a NRF24L01 inside a staples easy button to use as a remote low power button of some sort, maybe a doorbell?

The 2*AAA that the easy button comes with should last a few years at least.

This one was used for the clients sales team to hit it when a big sale occured and it played a loud sound on some speakers connected to the receiver.
#
## Arduino Model
Many models are an option but this guide will use the arduino pro mini as they are cheap, plentiful and easy to modify for low power, you will want a 3.3v Version running at 8mhz.

For Ultra low power you will need to remove the LED and regulator, if you are lucky enough to have a board with the regulator "Strap" likethis sparkfun model. You can just remove the solder bridge to disable the regulator.
![Regulator Location](/images/ProMini_Reg_Led_Location.jpeg)

# Take the button apart
Simply remove the batteries then the four rubber feet that cover up the screws.
![Feet](/images/feet_removed.jpg)

I took this photo after everything was done, but you can remove any wiring, except the wires that go to the batteries and then remove the circuit board and button clicker plate.
![Unscrew Circuit Board](/images/done.jpg)

After that remove the four screws that hold in the divider above the speaker.
![Hidden Screws](/images/hidden_screws.jpg)

Remove the speaker as we won't be needing it and this is where the arduino and NRF24L01 will fit.
# Wiring
![Arduino Close Up](/images/arduino_closeup.jpg)

This is pretty easy, D2 connects to the Test pad pictured here, you will also need to remove the glob top and cut the traces to where it was, probably could only cut the traces but why not do it all to be sure of no connections/power drain.

![D2 Wiring](/images/cut_traces.jpg)

## NRF24L01 Wiring
![NRF24l01 Pinout](/images/nrf24l01_pinout.jpg)

I Chose A0 and A1 for CE/CSN so that all wiring was on the same side of the board.

|NRF24L01 Pin   | Arduino Pin  |
|---------------|--------------|
|CE             | A0           |
|CSN            | A1           |
|SCK            | D13          |
|MOSI           | D11          |
|MISO           | D12          |
|3.3v           | VCC/BATT +   |
|GND            | GND/BATT -   |