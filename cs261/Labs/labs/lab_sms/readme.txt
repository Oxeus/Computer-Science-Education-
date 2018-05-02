Overview
--------

For this lab you will create a simple text converter.  The idea is to
convert "messaging" text into normal text.  For example, "l8r" and
"lol" will be converted to "later" and "laugh out loud". Your program
should use a HashMap to hold a mapping from "sms" to "english".

Details
-------

Modify the existing SmsConvert.java file and fill in the parts as
indicated in the comments.

When you run your program it will prompt the user to enter text and
then print out the translated message. When the input is a single "."
then the program exits.

Here is a sample run:

------
Enter: lol
You said: laugh out loud

Enter: ttyl btw
You said: talk to you later by the way

Enter: brb in 5
You said: be right back in 5

Enter: .
------

Your code should be case insensitive and convert everything to lower
case. 

You should support the following translations:

sms    english
------------------
brb    be right back
btw    by the way
bff    best friends forever
fwiw    for what it's worth
gr8    great
imho    in my humble opinion
l8r    later
lol    laugh out loud
omw    on my way
np    no problem
tmi    too much information
ttyl    talk to you later
wywh    wish you were here

Turning in the assignment
-------------------------

Use the turnin program to turn in your program. The command is
~mike.noel/bin/turnin cs261 SmsConvert.java.

