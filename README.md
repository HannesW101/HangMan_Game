Simple hangman game that allows the user to guess for a hidden word knowing the amount of letters in the word.
The game is won if all the letters of the random word is guessed and revealed before all the body parts are hung.
The game is lost if all the body parts are hung before all the letters of the random word is guessed and revealed (6 incorrect guesses will lose you the game).
If the game is lost the full word with all its letters will be revealed top left.
The words are randomly generated from a dataset of +/- 2000 words taken from common English words in the Oxford dictionary.
The words are generated using a pseudo random number generator which is simply seeded using the current time of day of the users computer (in seconds).
The word generated depends on the difficulty selected by the user:
  - Easy is words with length < = 6
  - Medium is words with length > 6 and < = 9
  - Hard is words with length > 10

Currently there is a hint system that supplies the user with a hint when a total of 2 body parts have been hung, and again when a total of 5 body parts have been hung.

Note that there is an improvement that can be made, currently the program handles "-" as a regular word that is hidden and thus the user needs to somehow guess the character "-" in the word which is not very possible.
There are about 15 words in the dataset that contain "-" so it is only a minor improvement.
There could also be something of a scoreboard that could be added that tracks the number of words the user guessed correctly in a row (like a guessing streak) which will reset the moment a user loses.
There could even be a highscore saved in a file that loads each time the program is run.
Another interesting idea is to add a timer that allows the user to only have a certain amount of seconds to guess the next letter, if they run out of time another body part will automatically be hung and the timer will reset.

Below is an example of the program running:




This is the main UI that pops up when the program is run.

![pic1](https://github.com/HannesW101/HangMan_Game/assets/86373722/591d2c33-1c27-41bf-a7d6-4dd7027959cb)

The user can then select which difficulty they would like to play on (refer to the top at the beginning of this document to see the differences in difficulties) the game will default to "Easy".

![pic2](https://github.com/HannesW101/HangMan_Game/assets/86373722/d04f7fc3-d0d1-47d1-b6bb-c05ee8311980)

When the user is ready they can press the "Start Game!" button which, as the name suggests, will begin the game. A few other widgets will appear now on the screen most notably the text box below which allows the user to input a character to guess and then a button below that labeled "Submit Your Guess" which will lock in the users guess. Also top left there will appear panels or platforms which indicate the length of the random word that was chosen.

![pic3](https://github.com/HannesW101/HangMan_Game/assets/86373722/fb326a23-fb33-4983-9bfe-41e53bd7576a)

Correct guesses will lead to letters being revealed top left above the platforms and incorrect guesses will lead to more body parts being hung.

![pic5](https://github.com/HannesW101/HangMan_Game/assets/86373722/e9b76b2e-6fb9-4f7f-b1c9-ce50340826c8)

As the user guesses letters those guesses will appear in a listbox on the right hand side of the program so the user can keep track of every letter they have guessed. Note that if the user guesses the same letter more than once, there will be no penalty (a body part will not be hung).

![pic6](https://github.com/HannesW101/HangMan_Game/assets/86373722/22a01225-7a41-4104-8915-261264ccedde)

A hint button appears bottom right after 2 and 5 body parts are hung (total of 2 hints per game) simply click this button and a letter will be revealed after which the hint button will disappear again.

![pic7](https://github.com/HannesW101/HangMan_Game/assets/86373722/f4089eb2-7a64-4df7-9398-eb15d5335835)

Below is the UI after a game has finished (in this case the user has won) you can simply reselect a difficulty and restart another game.

![pic8](https://github.com/HannesW101/HangMan_Game/assets/86373722/a3b93e9e-f6a1-4326-bc0b-b9cdba9d6def)

