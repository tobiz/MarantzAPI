from MarantzAPI import *

print ("Start")


avr = IP( 23, 1, av_url="192.168.1.47", browser="firefox")


print ("Power On")
avr.write_command("PWON")

print ("Phase 1")

avr.amp_assign("Front B")
avr.write_command("PSFRONT SPA")
avr.write_command("PSFRONT?")
avr.write_command("PSFRONT SPB")
avr.write_command("PSFRONT?")
avr.write_command("PSFRONT A+B")
avr.write_command("PSFRONT?")

#print ("Phase 2")

#avr.amp_assign("ZONE2")
#avr.write_command("PSFRONT SPA")
#avr.write_command("PSFRONT?")
#avr.write_command("PSFRONT SPB")
#avr.write_command("PSFRONT?")
#avr.write_command("PSFRONT A+B")
#avr.write_command("PSFRONT?")

#print ("Phase 3")

#avr.amp_assign("Front B")
#avr.write_command("PSFRONT SPA")
#avr.write_command("PSFRONT?")
#avr.write_command("PSFRONT SPB")
#avr.write_command("PSFRONT?")
#avr.write_command("PSFRONT A+B")
#avr.write_command("PSFRONT?")   


avr.write_command("PWSTANDBY")
       
