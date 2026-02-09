Bee Bencze
bencze@pdx.edu

This program was written as an assignment for CS302: Programming Methods & Software Implementation at Portland State University, taught by Karla Fant.

My app is based on the idea of a motorcycle racing event (I was told to have fun). 

Running 'make' should compile an executable named 'output' which will allow you to
run the program.

When the executable (named output) is run, a menu prompt will appear, you will be given a choice
to select an option between 1 and 9. Provided you do not select the quit option, you will continue 
to be prompted after each action until youa re ready to quite. I will provide a brief explanation 
of each input below.


1. DISPLAY: 
    Displays all riders currently stored in the database in ascending order based on rider number.

2. MANUAL REGISTRATION: 
    Allows for the manual creation of a new rider. You will be prompted to select from one of 4
    different rider types, and then will be prompted to fill in rider information, after which
    that rider will be added to the database.

3. REMOVE A CONTESTANT: 
    Allows for manual removal of a rider by number. You will be prompted for a rider's number, and
    that rider will then be removed from the database.

4. START: 
    Marks a certain rider as having started the race. Once again you will be prompted for rider
    number, and the program will search for that rider, and if found will start their race.

5. STOP: 
    Marks a certain rider as havving stopped the race. You will be prompted for a number, and then
    asked whether the rider completed the race, and what their finishing time was. If the rider
    is found and has started the race, their time will be marked and will be displayed on all
    future calls

6. AUTO-POPULATE DATABASE:
    Creates 16 rider objects (4 of each class) with varied attributes, and inserts them into
    the database automatically, this is especially helpful for testing certain functions without
    needing to manually create a variety of objects yourself

7. REMOVE ALL CONTESTANTS:
    Removes and deletes all riders from the database

8. CHECK PRO STATUS:
    Riders of the GP Racer class can have Pro licenses. You can check whether a rider is
    pro or not by using this function and searching via their rider number.

9. QUIT PROGRAM:
    Quits the program.