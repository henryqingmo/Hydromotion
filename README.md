# Hydromotion
A simple projectile motion simulation with custom physics engine using Qt Framework and OpenGL graphics api
## INSTALLATION:
This project is only compiled on Linux, therefore it's only available on Linux.
To Install, open up your terminal and go to your home directory. 
```
cd ~
```
Then clone the project. 
```
git clone https://github.com/henryqingmo/Hydromotion.git
```
Now go into my project folder.
```
cd Hydromotion
```
Gives access to the user to run the executable
```
sudo chmod +x QT_Hydromotion
```
Run the executable
```
./QT_Hydromotion
```
## USER GUIDE:

### Navigation:
The QUIT button exits the game
The HELP button takes you to this widget, you can click OK button to go back to MainMenu

The OptionMenu button takes you to a widget to set your music and sound. You can click OK button to go back to MainMenu

The START button takes you to the game window, you can click EXIT button to go back to MainMenu

### In Game:
Changing the slider will change the projection parameter, and simultaneously rotate or oscillate the cannon. When the fire button is pressed, the ball will be launched from the direction of the cannon with the current parameters. The ball will stop as it hits the ground, and the caculated data will be displayed on the Spinbox. 

### Note:
Since the projectile motion value is caculated using Euler's method, It's inaccurate and will deviate from the actual result. 

