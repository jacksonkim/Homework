# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Final - 12/5/13
# Description: Choose Your Own Adventure
# Replicant Quiz - 3 questions

choice = int(0)
points = int(0)
#jungBlue = int(0)
#jungGreen = int(0)
#jungRed = int(0)
#jungYellow = int(0)
#MBTIexin = int(0)
#MBTIsensint = int(0)
#MBTIthinkfeel = int(0)
#MBTIjudgeperc = int(0)


#wrote all this crap in Twine and then formatted it for python
print("It\'s the unsteady rattling of a bottle of pills\n"
      + "that brings you back from your dream. Whatever the dream was\n"
      + "about fades quickly while the pills get louder, closer. The\n"
      + "rattling is accompanied by footsteps, heels of a woman's shoe\n"
      + "clicking over a tiled floor.\n"
      + "\nYour body hurts, aches in various places. Where those places are\n"
      + "is a mystery to you in your groggy state of unconsciousness. You\n"
      + "can hear humming of machines, feel the warmth of electricity, even\n"
      + "the static pulling at your arm hairs.")
input()
print("The pill bottle is closed, the cap replaced with a\n" +
      "pleasant pop! It rattles back into a pocket of some kind, followed\n" +
      "by the scratch of a bottle cap being turned. The liquid sloshes in\n" +
      "the bottle and you hear swallowing after a moment. Then another\n" +
      "slosh and swallow, followed by a short sigh.\n" +
      "\nWith the aches around your body, you are hesitant to do anything\n" +
      "beyond lying where you are. However uncomfortable it is. Which is\n" +
      "a great deal. You can feel the unbending metal digging your\n" +
      "shoulderblades into the thin layer of skin on your back. Your spine\n" +
      "curves sharply at the small of your back to compensate the curve of\n" +
      "your body against the unforgiving flat surface. The back of your\n" +
      "head aches when you roll it in a different direction.") 
input()
print("Nothing smells out of the ordinary, which is out of the ordinary.\n" +
      "Normally your home would smell like the pancakes or ramen or whatever\n" +
      "you cooked the night before, or the sheets would smell like your\n" +
      "morning breath from the drool on your pillow. Actually it does smell\n" +
      "like something. It's soft, but its obviously a cleaning solution. You\n" +
      "are reminded of the few times you had to visit the hospital.\n" +
      "\nYour brow furrows slowly and a pain shoots around the side of your\n" +
      "head that is resting on whatever hard surface you are laying on.\n" +
      "\nAside from the sound of the pills, the water, the woman, you start\n" +
      "to hear the rest of the room. You can tell that it isn't very large,\n" +
      "judging by the sound of the machines humming away in the distance.\n" +
      "Occasionally you hear the hiss of air released from a machine.")
input()
print("So definitely not your room. Nothing in this room is familiar. The hard\n" +
      "floor, the hard surface, the machines. Maybe it's time to open your eyes.\n" +
      "\nYou are finally able to open your eyes. The brightness is unexpected,\n" +
      "stinging your eyes and causing them to water in defense. Pain shoots\n" +
      "through your skull, every breath and heartbeat thudding loudly against\n" +
      "the inside. There are lights overhead, flourescent tubes in those\n" +
      "gridded ceiling tiles. Those same ceiling tiles in every major\n" +
      "building, the white ones with the black spots, or holes, or whatever\n" +
      "is wrong with them.\n" +
      "\nYou slowly roll your eyes to your right, the motion reminding you\n" +
      "that you are in pain, in the direction that you heard the pills and\n" +
      "the water. As they move, you see the machines lining the walls. Not\n" +
      "one has a visible printout, but all of them appear to be connected\n" +
      "together to one object somewhere in your direction.")
input()
print("You focus on the woman with little difficulty. She appears to be\n" +
      "tall, though that could just be your relative position to her. You\n" +
      "appear to be around hip-height to her. She has her back to you,\n" +
      "standing at a table with her arms meeting somewhere in her center\n" +
      "mass. She has long red hair cascading down her back, stopping around\n" +
      "the small of her back. Her lab coat continues on around her mid-thigh,\n" +
      "black slacks cover her legs. She isn't far enough away for you to see\n" +
      "her offensive shoes, though you know enough about them from the\n" +
      "clicking inside your skull.")

print("\n1: Attempt to get up")
print("2: Address the woman")

choice = int(input("\nEnter 1 or 2: "))
#if else for choices
if choice == 1:
    points = points + 3
    print('\nYour torso muscles tense up a bit and you start to lift yourself\n' +
          'off of whatever it is you\'re laying on. Or you try to. You feel the\n' +
          'straps dig in to your skin, hear the metal clink against itself on the\n' +
          'ratchet and the squeaking of the cloth as it stretches against you,\n' +
          'holding you down fast. This sobers you a bit, though not completely.\n' +
          '\nThe noise of your movements has alerted the woman in the room with\n' +
          'you. "Oh good, you\'re awake." She clicks closer, and your jaw clenches\n' +
          'reflexively. The clicking fills your skull, threatening to break it\n' +
          'apart from the inside.\n' +
          '\nHer cold hands press to your throat and wrist, and you hear a\n' +
          'sharp intake of breath through your own teeth. After a few seconds,\n' +
          'you see her nod and she moves her hand to your forehead, thankfully a\n' +
          'little warmer. She glances to her left, behind you. "Pulse is steady, no\n' +
          'fever." Her hand moves away to her lab coat pocket and she pulls out a\n' +
          'pen-like object. She clicks it and you see a light against the palm \n' +
          '\nof her hand.\nThe pain shoots directly back from your eyes as she \n' +
          'shines the light into your eyes and away. Your object in the form of \n' +
          'squirms and groans, but she holds your eyelid open and checks both eyes. \n"Responses all seem within normal levels."')
elif choice == 2:
    points = points + 1
    print('\nObservation of the room leaves you with more questions than answers.\n' +
          '\nYou collect the saliva in your mouth and attempt to swallow it. Your tongue\n' +
          'seems to fill your entire mouth, making it hard to get the saliva into your throat.\n' +
          'It\'s too bad, though, because your throat stings all the way down, as if you had\n' +
          'swallowed razor blades earlier. A small groan reaches your ears and you realize it\n' +
          'is your own voice.\n' +
          '\nThe noise reaches your companion\'s ears as well, and you hear her shoes click\n' +
          'closer to you, every step resonating loudly inside your skull. Blissfully, it stops\n' +
          'as soon as she reaches your side. Her cold hands press to your throat and wrist, and\n' +
          'you hear a sharp intake of breath through your own teeth.\n' +
          '\nThis is your chance. "Where am I?" Your voice sounds like the razor blades are still\n' +
          'clogging your throat and feel twice as bad.\n' +
          '\nThe hands move away sharply with a gasp. Your brow furrows slowly at her reaction.\n' +
          'She takes a moment to collect herself and moves her hand to your forehead. "You\'re in\n' +
          'a safe place."\n' +
          '\n"That\'s a dodgy answer." Razor blades. "Safe from what."\n' +
          'She looks behind you, to her left. "Pulse is normal, no fever. Awake enough to be\n' +
          'talking, so I will forego the other tests."')
    

#back to the main story
print('\n"Where am I?" Your throat burns with every word.\n' +
      'She glances between you and the space behind you. "How about we just \n' +
      'get you off this slab, hm?" Her body language is completely different. \n' +
      'She moves away and her head disappears from view.\n' +
      '\nYou hear the ratcheting in your teeth, clenched together so hard at every other\n' +
      'loud sound that pounds inside your skull. The straps loosen immediately and you\n' +
      'watch them fly over your body to the other side of the table.\n' +
      'You take a deep breath once the last strap is gone. Every ache and\n' +
      'pain diminishes or disappears, the horrendous clicking becoming a sharp\n' +
      'pain somewhere behind your eyes.\n')
input()
print('You sieze the opportunity and throw your right leg off the table first,\n' +
      'using the imbalance to push yourself up. The woman pulls on your shoulder\n' +
      'to help you sit up while you swing your left leg to join its partner.\n' +
      'You look down at your legs. Both are intact and covered in jeans.\n' +
      'You are wearing a simple solid color t-shirt. You even have sneakers on.\n' +
      'You swallow again, the razor blades morphed into a cheese grater. "You \n' +
      'never answered me." You try to clear your throat, but it makes everything\n' +
      'so much worse, forcing you to turn your head, eyes closed.\n' +
      '"Sure I did." Her voice breaks. "Somewhere safe." She turns around immediately\n' +
      'and heads back to the table a few feet away.\n' +
      'You look to your left, toward the machines. They are all in fact linked up to\n' +
      'you. You have no idea how you missed the needles stuck in your arms, the nodes\n' +
      'stuck up under your simple t-shirt with plenty of slack on the wire. \n' +
      'Another brow furrow and you can feel the nodes around your head.')


print("\n1: What the hell")
print("2: Am I free to go")

choice = int(input("\nEnter 1 or 2: "))
#if else for choices
if choice == 1:
    points = points + 1
    print('\n"What the hell!" The words are out of you before you can even think.\n' +
          'Your heart is fast again, beating wildly against your ribcage. Your\n' +
          'hands fly quickly to one of the nodes attached to your head.\n' +
          '\n"No! Stop!" You hear her, but the words don\'t mean anything. The node\n' +
          'is already detached from your temple.\n' +
          '\nEverything hurts again, this time a burning sensation that starts at your\n' +
          'toes and flows all the way to your temple. There is nothing but fire and it\n' +
          'started there. You\'re sure you have a body in there somewhere, but the fire\n' +
          'licks at your eyes, at your fingers. You remember being in a room somewhere,\n' +
          'with a woman, but none of that matters now. All that matters is the fire.\n' +
          '\nThe fire.\n' +
          '\nThe stickiness returns and you feel the fire recede. The ceiling has\n' +
          'appears to be some orange hue. You can hear the wheezing in your deep breaths,\n' +
          'struggling to swallow enough air in and out of your lungs.\n' +
          '\n"Please. These machines are helping you recuperate. Let them do their work and\n' +
          'you will be free to go." There is a weight on your shoulder that you assume is\n' +
          'her hand.\n' +
          '\n"What." Air continues to elude you. "the hell." Your eyes blink and \n' +
          'everything has a bluish tint. "was that?"\n' +
          '\nShe purses her lips and glances to her left, your right. Instinctively, you\n' +
          'look in that direction as well.')
elif choice == 2:
    points = points + 3
    print('\nThe machinery connected to you doesn\'t appear to do anything.\n' +
          'There\'s no beeps or tickers tracking anything. There is no visible\n' +
          'output. You assume they are just there for show. You turn your attention back\n' +
          'to the ginger.\n' +
          '"Am I free to go?" Your throat is still a cheese grater, but at least you sound\n' +
          'better.\n' +
          'Ginger turns around to you and shrugs. "I\'ll take all the leads off and needles out\n' +
          'whenever the machines are done."\n' +
          'You glance to the machines again. "But they aren\'t doing anything."\n' +
          'Ginger looks between you and the area to your right, her left again. Her lips purse.\n')

#back to the main story
print('\nThe right wall isn\'t even a wall. It is just a massive mirror. Reflected\n' +
      'in it is a the entire room, all the machines along the left wall, the \n' +
      'tables in the room, the slab you are sitting on, Ginger, and you.\n' +
      '\nThe wires connect to various parts of your body, three on your head, which\n' +
      'you now see has been shaved. You lift a hand to feel the stubble that was once\n' +
      'your hair. The needles sticking out of your hand tug at the skin, poke \n' +
      'around in the vein, a bruise under the skin from movement. It\'s soft, whatever\n' +
      'stubble is left.\n\n"Why did you shave my head?"\n' +
      '\nGinger looks back to you, but you cannot pull yourself away from your \n' +
      'reflection. "Access."\n' +
      '\n"Access for what?"\n' +
      '\nThere is a hesitation in her voice. "The surgery."\n' +
      '\nYour ribcage is attacked by your heart again. You look back to her. "Surgery?"\n' +
      '\nShe nods. "I have a few questions to ask you, then we can get you out of \n' +
      'here, okay?"\n\nYour eyes are wide, your throat tight. "What surgery?"\n' +
      '\nGinger shakes her head and moves to the table. "Just a few questions, then\nyou can go."\n')


#if else for choices
print("\n1: I'm not answering your questions")
print("2: As long as I can go")

choice = int(input("\nEnter 1 or 2: "))
#if else for choices
if choice == 1:
    points = points + 1
    print('\nThe pain, the wires, the needles. None of this makes sense. None of \n' +
          'it is "safe". "I\'m not answering any questions. I want these things \n' +
          'off me and I want out." \n\nGinger bites her lip and looks to the mirror \n' +
          'again. "The time that it takes to answer the questions will fill the \n' +
          'time you have left connected to the machines."\n\n You swallow again, cheese \n' +
          'grater still in your throat. "Don\'t leave me much of a choice now, do you."\n' +
          'Ginger smiles weakly, but tactfully remains silent.')
elif choice == 2:
    points = points + 3
    

print('\nGinger nods and turns around to grab the clipboard. "Okay, first question."')

print('\nYour friend is about to get married. You are chosen to play a key role\n' +
      'in the ceremony, but you do not agree with the marriage. Would you:')

print("\n1: Say nothing and trust your friend's choice")
print("2: Object to the wedding and risk your friendship")

choice = int(input("\nEnter 1 or 2: "))
#if else for choices
if choice == 1:
    points = points + 3
elif choice == 2:
    points = points + 1

print('\nGinger jots down your answer. "Thank you. Couple more questions."')

print('You\'re at home watching television. A tickle on your arm draws attention\n' +
      'to a wasp crawling on it. How do you react?')

print("\n1: Freak out and try to kill it")
print("2: Carefully get outside and let it fly away")

choice = int(input("\nEnter 1 or 2: "))
#if else for choices
if choice == 1:
    points = points + 1
elif choice == 2:
    points = points + 3

print('Ginger hums and jots something down on the clipboard. "Good, good. Okay, last one."')

print('You are serving on a jury. The evidence has left no room for reasonable\n' +
      'doubt, leading you to believe the accused is guilty. But, morally, you agree\n' +
      'with what they are accused of. How do you vote?')

print("\n1: Guilty")
print("2: Not Guilty")

choice = int(input("\nEnter 1 or 2: "))
#if else for choices
if choice == 1:
    points = points + 3
elif choice == 2:
    points = points + 1

print('\nThe last question answered, Ginger nods and looks toward the mirror again.\n' +
      'You follow her gaze, but all you see is her and whatever monstrosity you have\n' +
      'turned into. Wires and needles, no hair, no definition. You barely recognize yourself.\n' +
      '\nGinger moves toward the machines and starts to flip switches and turn them off.\n' +
      '"You are safe to remove the leads on your own. I have to be the one to \n' +
      '\nremove the needles." You take a deep breath. The cheese grater is missing \n' +
      'from your throat.You raise a hand to remove the node on your temple. Nothing of \n' +
      'importance happens. You still feel a little sticky.\n' +
      '\nOnce all of the leads are done, Ginger shows back up to remove the needles.\n' +
      'You assist when she tells you to.\n' +
      'Ginger promised this was the end. "So I\'m free to go now?"\n' +
      '\nGinger turns to you, then to the mirror. You look to the mirror and see your\n' +
      'reflection. After a moment, Ginger turns back to you. "The door is right over\n' +
      'there. Your cooperation has been appreciated."\n' +
      'Before you have a chance to question her further, Ginger and her \n' +
      'clipboard are gone.\n\nThe bottle of water sits on the table.')
input()

#test the paragon and renegade
if points <= 10:
    print('Next to the bottle of water is a familiar set of dogtags. It has your name,\n' +
          'rank, and serial number on one of them. The other is one you made yourself that\n' +
          'has your date of dishonorable discharge.')
elif points < 14:
    print('Next to the bottle of water is a busted up cell phone. No longer under the \n' +
          'watchful eye of Ginger, you pick it up. Poking the button at the bottom pulls \n' +
          'up a picture of you with your significant other as the lock screen background. \n' +
          'Time to let them know you\'re all right.')
elif points >= 14:
    print('Next to the bottle of water is a wallet. You retrieve the wallet and open \n' +
          'it up to a golden shield in a circle. Your Deputy\'s badge sparkles beside\n' +
          'your identification card.')

    
