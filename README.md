### Introduction
In this project I have made the famous Snake Game using OpenGL and C++ libraries.
The game begins with the main menu wherein the user selects the level they want to play the game at.

The user tries to make the snake eat the prey which makes it’s length, speed and score increase based on the type of prey eaten:

Type 1 :<br/>
•	Increases snake’s length and score by 1 unit.<br/>
•	Vanishes only after it is eaten.<br/>
•	Red colored.<br/>

Type 2 :<br/>
•	Increases snake’s length by 1 unit and score by 2 units.<br/>
•	Vanishes after a set time period.<br/>
•	Purple colored.<br/>


The game is designed separately for all the three levels with different specifications, explained as follows:

Level 1 : <br/>
•	This is the easiest level to play.<br/>
•	There are no boundaries.<br/>
•	Only Type 1 prey is used.<br/>

Level 2 :<br/>
•	The level is of medium difficulty.<br/>
•	Boundaries exist with 2 open slits at the upper and lower boundary.<br/>
•	Both Type 1 and Type 2 prey occur at this level.<br/>

Level 3 :<br/>
•	This is the hardest level.<br/>
•	Boundaries exist on all sides along with added constraints within the level’s structure.<br/>
•	Both Type 1 and Type 2 preys appear at this level.<br/>

If after a certain time the snake either dies by strangulating itself or hitting the boundaries, the final score is displayed along with a message indicating that the player lost.
Else if the player completes the game, the score is displayed along with the message indicating that they won.

</br>

### Computer Graphics concepts used.

OpenGL is a cross-language, cross-platform application programming interface for rendering 2D and 3D vector graphics. The API is typically used to interact with a graphics processing unit, to achieve hardware-accelerated rendering. OpenGL libraries and various GL and GLU commands were used in this project. These are as follows :

•	glColor(): Set the current color.<br/>
•	glBegin() and glEnd(): Delimit the vertices of a primitive or a group of like primitives.<br/>
•	glVertex(): These functions specify a vertex.<br/>
•	glReadPixels(): Reads a block of pixels from the framebuffer.<br/>
•	glRasterPos(): Specify the raster position for pixel operations.<br/>
•	glutBitmapCharacter(): renders a bitmap character using OpenGL.<br/>
•	glClear(): Clears buffers to preset values.<br/>
•	glFlush(): Forces execution of OpenGL functions in finite time.<br/>
•	glMatrixMode(): Specifies which matrix is the current matrix.<br/>
•	glLoadIdentity(): Replaces the current matrix with the identity matrix.<br/>
•	gluOrtho2D(): Defines a 2-D orthographic projection matrix.<br/>

GLUT provides high-level utilities to simplify OpenGL programming, especially in interacting with the Operating System (such as creating a window, handling key and mouse inputs). The following GLUT functions were used in the project:

•	glutBitmapCharacter(): renders a bitmap character using OpenGL.<br/>
•	glutInit(): Initializes GLUT, must be called before other GL/GLUT functions. It takes the same arguments as the main().<br/>
•	glutInitWindowSize(): Specifies the initial window width and height, in pixels.<br/>
•	glutInitWindowPosition(): Positions the top-left corner of the initial window at (x, y). <br/>
•	glutCreateWindow(): Creates a window with the given title. <br/>
•	glutDisplayFunc(): Registers the callback function for handling window-paint event. The OpenGL graphic system calls back this handler when it receives a window re-paint request. <br/>
•	glutMainLoop(): Enters the infinite event-processing loop, i.e, put the OpenGL graphics system to wait for events, and trigger respective event handlers.<br/>
•	glutTimerFunc(): Registers a timer callback to be triggered in a specified number of milliseconds.<br/>
•	glutReshapeWindow(): Requests a change to the size of the current window.<br/>
•	glutCreateMenu(): Creates a new pop-up menu.

Various other GLUT functions like glutAddMenuEntry(), glutAttachMenu(), glutReshapeFunc(), glutSpecialFunc(), etc. are also used in the project code.


<br/>

### User defined functions.

•	erase(): Erases the block associated with the provided coordinates.<br/>

•	redraw(): Adds a particular color in the area enclosed by the new vertices corresponding to the passed arguments.<br/>

•	checkStrangled(): Checks whether the snake has been strangled by comparing the color of a point with the body of the snake.<br/>

•	snake(): Erases the tail and updates the snake’s coordinates depending on the state/direction.<br/>
  Level 0: If the snakes crosses any of the boundaries, it’s variable are updated to the other end.<br/>
  Level 1: Works same as the previous for the open slit and if the snake reaches the boundary, the player loses and the corresponding message is displayed.<br/>
  Level 2: If the snake crosses the boundaries or touches the constraints set at the middle of structure, the player loses and the corresponding message is displayed.<br/>

->	If the snake gets strangled in the process, the game ends and the corresponding message is displayed for the particular level.<br/>
-> Increments the prey time and keeps the log of whether the prey is present or not.<br/>
->	If the prey is eaten the score and length is increased by a unit and the corresponding sound is played.<br/>
->	If the time limit for the bigger prey exceeds a particular value the prey vanishes.<br/>
->	Else if it is eaten, the score is increased by two units and the corresponding sound is played.<br/>
->	If the player eats enough numbers of preys, the winning text is displayed and the winning sound is played.<br/>

•	DisplayText(): Displays the text with the specified font and position.<br/>

•	Timer(): Keeps track of the time till the game doesn’t end and based on the set flags, displays the final result using DisplayText method.<br/>

•	boundry(): Sets the boundaries for each level using GL commands.<br/>

•	bigger_prey(): Sets a random location for the prey according to level-wise constraints and colors it purple using GL commands.<br/>

•	new_prey(): Sets a random location for the prey according to level-wise constraints and colors it red using GL commands.<br/>

•	my_reshape(): Reshapes the window to (600,600), the pre-defined dimensions.<br/>

•	my_keyboard(): Sets the four states or exits depending on the key pressed.<br/>

•	menu(): Intiates the game according to the chosen level from a set state and time limit.<br/>

•	createmenu(): Creates the menu and the submenu from where the user choses the difficulty level.<br/>

•	myinit(): Initiates the timer to NULL, clears buffers to preset values, replaces the current matrix with the identity matrix and defines a 2-D orthographic projection matrix.<br/>

•	main(): The driver function, initiates the game.<br/>

<br/>

### Web Interface

##### Dialog box telling the rules of the game
<img src="https://github.com/infinity1013/Snake-Game/blob/main/Images/Dialog%20Box.png" width="400" height="170">

<br/>

##### Menu to select the difficulty level
<img src="https://github.com/infinity1013/Snake-Game/blob/main/Images/Menu.png" width="400" height="400">

<br/>

##### Entered in Easy mode
<img src="https://github.com/infinity1013/Snake-Game/blob/main/Images/Easy%20Mode.png" width="400" height="400">

<br/>

##### Entered in Medium mode
<img src="https://github.com/infinity1013/Snake-Game/blob/main/Images/Medium%20Mode.png" width="400" height="400">

<br/>

##### Entered in Hard mode
<img src="https://github.com/infinity1013/Snake-Game/blob/main/Images/Hard%20Mode.png" width="400" height="400">

<br/>

##### Special Prey in orange
<img src="https://github.com/infinity1013/Snake-Game/blob/main/Images/Special%20Prey.png" width="400" height="400">

<br/>

##### The snake is going through one edge to opposite edge
<img src="https://github.com/infinity1013/Snake-Game/blob/main/Images/Out-In.png" width="400" height="400">

<br/>

##### Snake died because it got strangled
<img src="https://github.com/infinity1013/Snake-Game/blob/main/Images/Strangled.png" width="400" height="400">

<br/>

##### Snake died because it got crashed with wall
<img src="https://github.com/infinity1013/Snake-Game/blob/main/Images/Crashed%20with%20wall.png" width="400" height="400">

<br/>

##### Game over message displayed
<img src="https://github.com/infinity1013/Snake-Game/blob/main/Images/Game%20Over.png" width="400" height="400">

<br/>

##### Player passed the Easy challenge
<img src="https://github.com/infinity1013/Snake-Game/blob/main/Images/Congratualations.jpg" width="400" height="400">

<br/>

##### Message displayed after game won
<img src="https://github.com/infinity1013/Snake-Game/blob/main/Images/won.jpg" width="400" height="400">

<br/>

