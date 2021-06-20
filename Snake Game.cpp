#pragma comment(lib, "winmm.lib")
#include<bits/stdc++.h>
#include<conio.h>
#include<GL/glut.h>
#include<windows.h>
using namespace std;

int x, y, state, st, score = 0, score1 = 0, level = 0;
int t, f1 = 0, op;
static int menu_id, submenu_id;
int prey_time = 0, x_bigger, y_bigger, prey_flag = 0;

class node {
public:
	int j, k, p, q;
	node* next;
};

void new_prey();
void bigger_prey();

class S {
public:
	node* head, * tail;

	S() {
		head = new node;
		tail = new node;

		head->p = head->j = 60;
		head->q = head->k = 40;

		tail->p = tail->j = 60;
		tail->q = tail->k = 20;

		head->next = tail;
		tail->next = NULL;
	}

	void erase(int m, int n) {
		glColor3f(0.0, 0.1, 0.0);
		glBegin(GL_QUADS);
		glVertex2i(m - 10, n + 10);
		glVertex2i(m - 10, n - 10);
		glVertex2i(m + 10, n - 10);
		glVertex2i(m + 10, n + 10);
		glEnd();
	}

	void redraw(int m, int n) {
		glBegin(GL_QUADS);
		glVertex2i(m - 10, n + 10);
		glVertex2i(m - 10, n - 10);
		glVertex2i(m + 10, n - 10);
		glVertex2i(m + 10, n + 10);
		glEnd();
	}

	bool checkStrangled(int x, int y) {
		int p[3];
		glReadPixels(x, y, 1, 1, GL_RGB, GL_INT, &p[0]);

		//	cout << p[0] << "    " << p[1] << "    " << p[2] << endl;

		p[0] = p[0] / 2147483647;
		p[1] = p[1] / 2147483647;
		p[2] = p[2] / 2147483647;

		if (p[0] == 0 && p[1] == 1 && p[2] == 1)
			return true;

		return false;
	}

	void snake() {
		node* temp;
		bool b;
		int i = 1, f = 0;
		temp = head;

		while (temp != NULL && level != -1) {
			if (temp->next != NULL) {
				temp->next->p = temp->j;
				temp->next->q = temp->k;
			}

			if (temp->next == NULL)
				erase(temp->j, temp->k);

			if (temp == head) {
				if (state == 1)
					temp->q += 20;
				else if (state == 2)
					temp->q -= 20;
				else if (state == 3)
					temp->p -= 20;
				else if (state == 4)
					temp->p += 20;
			}

			if (temp == head) {
				if (level == 0) {
					if (temp->j > 10 && temp->j < 590 && temp->k > 590)	//top
						temp->q = 20;
					if (temp->j > 10 && temp->j < 590 && temp->k < 10)	//bottom
						temp->q = 580;
					if (temp->k > 10 && temp->k < 590 && temp->j > 590)	//right
						temp->p = 20;
					if (temp->k > 10 && temp->k < 590 && temp->j < 10)	//left
						temp->p = 580;
				}
				else if (temp->j > 250 && temp->j < 330 && temp->k > 590)	//top
					temp->q = 20;
				else if (temp->j > 250 && temp->j < 330 && temp->k < 10)	//bottom
					temp->q = 580;

				else if ((temp->j < 10 || temp->j > 590 || temp->k < 10 || temp->k > 590) && level != 0) {
					char title[] = "Game Over";
					PlaySound(TEXT("Resource Files/Loosing.wav"), NULL, SND_ASYNC);
					if (level == 1) {
						char msg[80];
						sprintf_s(msg, "Why? Crashed with wall\nIn Medium Difficulty\nYour Score: %d", score);
						MessageBoxA(0, msg, title, MB_OK | MB_ICONEXCLAMATION);
						f1 = 1;
						op = 1;
					}

					if (level == 2) {
						char msg[80];
						sprintf_s(msg, "Why? Crashed with wall\nIn Hard Difficulty\nYour Score: %d", score);
						MessageBoxA(0, msg, title, MB_OK | MB_ICONEXCLAMATION);
						f1 = 1;
						op = 1;
					}
					f1 = 1;
				}

				else if ((temp->j > 150 && temp->j < 450 && temp->k > 290 && temp->k < 330) && level == 2) {
					f1 = 1;
					op = 1;
					char title[] = "Game Over";
					PlaySound(TEXT("Resource Files/Loosing.wav"), NULL, SND_ASYNC);
					char msg[90];
					sprintf_s(msg, "Why? Crashed with Middle Wall\nIn Hard Difficulty\nYour Score: %d", score);
					MessageBoxA(0, msg, title, MB_OK | MB_ICONEXCLAMATION);
				}

				else if ((temp->j > 270 && temp->j < 310 && temp->k > 150 && temp->k < 450) && level == 2) {
					f1 = 1;
					op = 1;
					char title[] = "Game Over";
					PlaySound(TEXT("Resource Files/Loosing.wav"), NULL, SND_ASYNC);
					char msg[90];
					sprintf_s(msg, "Why? Crashed with Middle Wall\nIn Hard Difficulty\nYour Score: %d", score);
					MessageBoxA(0, msg, title, MB_OK | MB_ICONEXCLAMATION);
				}
			}

			//	Redraw
			if (temp == head) {
				b = checkStrangled(temp->p, temp->q);
				if (b) {
					f1 = 1;
					op = 1;
					char title[] = "Game Over";
					PlaySound(TEXT("Resource Files/Loosing.wav"), NULL, SND_ASYNC);
					state = 1;
					if (level == 0) {
						char msg[60];
						sprintf_s(msg, "Why? Strangled\nIn Easy Difficulty\nYour Score: %d", score);
						MessageBoxA(0, msg, title, MB_OK | MB_ICONEXCLAMATION);
					}

					if (level == 1) {
						char msg[60];
						sprintf_s(msg, "Why? Strangled\nIn Medium Difficulty\nYour Score: %d", score);
						MessageBoxA(0, msg, title, MB_OK | MB_ICONEXCLAMATION);
					}

					if (level == 2) {
						char msg[60];
						sprintf_s(msg, "Why? Strangled\nIn Hard Difficulty\nYour Score: %d", score);
						MessageBoxA(0, msg, title, MB_OK | MB_ICONEXCLAMATION);
					}
				}
			}

			glColor3f(0.0, 1.0, 1.0);
			if (temp == head)
				glColor3f(0.8, 0.2, 0.2);

			redraw(temp->p, temp->q);

			temp->j = temp->p;
			temp->k = temp->q;
			prey_time++;
			//cout << prey_time<<"\n";
			if (prey_flag == 1) {
				if (prey_time > 200 + score * 10) {
					erase(x_bigger + 10, y_bigger - 10);
					prey_flag = 0;
				}
				else {
					if (temp->p == (x_bigger + 10) && temp->q == y_bigger - 10) {
						erase(x_bigger + 10, y_bigger - 10);
						PlaySound(TEXT("Resource Files/bigeat.wav"), NULL, SND_ASYNC);
						score += 2;
						++score1;
						prey_flag = 0;
					}
				}
			}
			//prey_Eaten or not
			if (temp->p == (x + 10) && temp->q == y - 10) {
				PlaySound(TEXT("Resource Files/Eat prey.wav"), NULL, SND_ASYNC);
				++score;
				++score1;
				new_prey();
				if (score1 % 3 == 0 && score != 0) {
					bigger_prey();
					prey_time = 0;
					prey_flag = 1;
				}
				t = t - 3;

				if (t < 20) {
					if (level == 0) {
						char title[] = "* Congratulations! *";
						PlaySound(TEXT("Resource Files/Complete.wav"), NULL, SND_ASYNC);
						char msg[100];
						sprintf_s(msg, "You have completed the Easy version of this challenge\nYour Score: %d", score);
						MessageBoxA(0, msg, title, MB_OK);
					}
					if (level == 1) {
						char title[] = "* Congratulations! *";
						PlaySound(TEXT("Resource Files/Complete.wav"), NULL, SND_ASYNC);
						char msg[100];
						sprintf_s(msg, "You have completed the Medium version of this challenge\nYour Score: %d", score);
						MessageBoxA(0, msg, title, MB_OK);
					}
					else if (level == 2) {
						char title[] = "* Congratulations! *";
						PlaySound(TEXT("Resource Files/Complete.wav"), NULL, SND_ASYNC);
						char msg[100];
						sprintf_s(msg, "You have completed the Hard version of this challenge\nYour Score: %d", score);
						MessageBoxA(0, msg, title, MB_OK);
					}
					MessageBoxA(0, "You are a STAR!", "God's Message", MB_OK);
					f1 = 1;
				}
				f = 1;
			}
			glFlush();
			temp = temp->next;
		}

		//new node
		if (f == 1) {
			node* temp1 = new node;
			temp1->j = tail->j;
			temp1->k = tail->k;
			temp1->p = tail->p;
			temp1->q = tail->q;
			temp1->next = NULL;
			tail->next = temp1;
			tail = temp1;
		}
		f = 0;
	}
};

void DisplayText(string text, int x, int y, int font)
{
	void* p = NULL;
	if (font < 8 && font>1)
		p = ((void*)font);
	else
		p = ((void*)5);
	glColor3f(1, 0, 0);
	glRasterPos2f(x, y);
	int len = text.length();
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(p, (int)text[i]);

	glColor3f(1, 0, 0);

}

S saap;

void Timer(int value)
{
	saap.snake();
	if (!f1)
		glutTimerFunc(t, Timer, 0);
	else
	{
		if (op == 1)
			DisplayText("!!! Game Over !!!", 220, 320, 5);
		else
			DisplayText("Congrats!! You Won", 220, 320, 5);
		glFlush();
	}
}

void boundry()
{
	//glClearColor(0.0,0.0,0.0,0.0);
	//glClear(GL_COLOR_BUFFER_BIT);
	if (level == 0) {
		// No Boundary
	}
	if (level == 1)
	{
		//	glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_QUADS);

		//bottom left
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(0.0, 0.0);
		glVertex2f(10.0, 0.0);

		//top left
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(10.0, 600.0);
		glVertex2f(0.0, 600.0);

		//bottom left
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(0.0, 10.0);
		glVertex2f(0.0, 0.0);

		//bottom slit left
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(250.0, 0.0);
		glVertex2f(250.0, 10.0);

		//bottom slit right
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(330.0, 0.0);
		glVertex2f(330.0, 10.0);

		//right bottom
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(600.0, 10.0);
		glVertex2f(600.0, 0.0);

		//bottom right
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(590.0, 0.0);
		glVertex2f(600.0, 0.0);

		//top right
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(600.0, 600.0);
		glVertex2f(590.0, 600.0);

		//top right
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(600.0, 600.0);
		glVertex2f(600.0, 590.0);

		//top slit right
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(330.0, 590.0);
		glVertex2f(330.0, 600.0);

		//top slit left
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(250.0, 600.0);
		glVertex2f(250.0, 590.0);

		//top left
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(0.0, 590.0);
		glVertex2f(0.0, 600.0);

		glEnd();
		glFlush();
	}
	if (level == 2)
	{
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_QUADS);

		//bottom left
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(0.0, 0.0);
		glVertex2f(10.0, 0.0);

		//top left
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(10.0, 600.0);
		glVertex2f(0.0, 600.0);

		//bottom left
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(0.0, 10.0);
		glVertex2f(0.0, 0.0);

		//bottom slit left
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(250.0, 0.0);
		glVertex2f(250.0, 10.0);

		//bottom slit right
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(330.0, 0.0);
		glVertex2f(330.0, 10.0);

		//right bottom
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(600.0, 10.0);
		glVertex2f(600.0, 0.0);

		//bottom right
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(590.0, 0.0);
		glVertex2f(600.0, 0.0);

		//top right
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(600.0, 600.0);
		glVertex2f(590.0, 600.0);

		//top right
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(600.0, 600.0);
		glVertex2f(600.0, 590.0);

		//top slit right
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(330.0, 590.0);
		glVertex2f(330.0, 600.0);

		//top slit left
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(250.0, 600.0);
		glVertex2f(250.0, 590.0);

		//top left
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(0.0, 590.0);
		glVertex2f(0.0, 600.0);

		// + bottom
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(270.0, 150.0);
		glVertex2f(310.0, 150.0);

		// + top
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(310.0, 450.0);
		glVertex2f(270.0, 450.0);

		// + left 
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(150.0, 290.0);
		glVertex2f(150.0, 330.0);

		// + right
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(450.0, 330.0);
		glVertex2f(450.0, 290.0);

		glEnd();
		glFlush();
	}
}

void bigger_prey() {
	int i = 1;
	bool b = true;
	x_bigger = rand() % 590 + 10;
	y_bigger = rand() % 590 + 10;

	if (x_bigger >= 590 || x_bigger <= 10)
		x_bigger = 40;
	if (y_bigger <= 10 || y_bigger >= 590)
		y_bigger = 40;

	x_bigger = x_bigger - ((x_bigger - 10) % 20);
	y_bigger = y_bigger + ((590 - y_bigger) % 20);

	if (level == 2)
	{
		if (x_bigger > 130 && x_bigger < 450)
			if (y_bigger > 290 && y_bigger < 350)
				y_bigger += 40;

		if (y_bigger > 150 && y_bigger < 490)
			if (x_bigger > 250 && x_bigger < 310)
				x_bigger += 40;
	}

	glColor3f(1.0, 0.5, 0);
	glBegin(GL_QUADS);
	glVertex2i(x_bigger, y_bigger);
	glVertex2i(x_bigger + 20, y_bigger);
//	glColor3f(0.2, 0.5, 0.0);
	glVertex2i(x_bigger + 20, y_bigger - 20);
	glVertex2i(x_bigger, y_bigger - 20);
	glEnd();
	glFlush();
}
void new_prey()
{

	int i = 1;
	bool b = true;
	x = rand() % 590 + 10;
	y = rand() % 590 + 10;

	if (prey_flag == 1 && (x == x_bigger || y == y_bigger)) {
		x += 20;
		y += 20;
	}

	if (x >= 590 || x <= 10)
		x = 40;
	if (y <= 10 || y >= 590)
		y = 40;

	x = x - ((x - 10) % 20);
	y = y + ((590 - y) % 20);

	if (level == 2)
	{
		if (x > 130 && x < 450)
			if (y > 290 && y < 350)
				y += 40;

		if (y > 150 && y < 490)
			if (x > 250 && x < 310)
				x += 40;
	}


	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x + 20, y);
	glColor3f(0.2, 0.5, 0.2);
	glVertex2i(x + 20, y - 20);
	glVertex2i(x, y - 20);
	glEnd();
	glFlush();
}

void my_display()
{

}

void my_reshape(GLsizei x, GLsizei y)
{
	glutReshapeWindow(600, 600);
}

void my_keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (state == 2)
			break;
		state = 1;
		break;
	case GLUT_KEY_DOWN:
		if (state == 1)
			break;
		state = 2;
		break;
	case GLUT_KEY_LEFT:
		if (state == 4)
			break;
		state = 3;
		break;
	case GLUT_KEY_RIGHT:
		if (state == 3)
			break;
		state = 4;
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

void menu(int num)
{
	level = num;
	boundry();
	new_prey();
	t = 140;
	state = 1;
	PlaySound(TEXT("Resource Files/level.wav"), NULL, SND_ASYNC);
	glutTimerFunc(0, Timer, 0);
	glFlush();
}

void createmenu()
{
	submenu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Easy", 0);
	glutAddMenuEntry("Medium", 1);
	glutAddMenuEntry("Hard", 2);
	menu_id = glutCreateMenu(menu);
	glutAddSubMenu("Select Difficulty", submenu_id);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void myinit()
{
	srand(time(NULL));
	glClearColor(0.0, 0.1, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 600);
}

int main(int argc, char** argv)
{
	PlaySound(TEXT("Resource Files/retro.wav"), NULL, SND_ASYNC);
	char Caption[] = "* Rules *";
	char Message[] = "1. Main objective is to eat the prey.\n"
		"2. Use UP(^), DOWN(v), RIGHT(>), and LEFT(<).\n"
		"3. After starting of the game, firstright click using mouse and select the difficulty.\n"
		"4. Press OK to start the game\n";
	MessageBoxA(0, Message, Caption, MB_OK);
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Snake Master");

	PlaySound(TEXT("Resource Files/Game open.wav"), NULL, SND_ASYNC);

	glutDisplayFunc(my_display);
	glutReshapeFunc(my_reshape);
	glutSpecialFunc(my_keyboard);
	myinit();
	createmenu();
	glutMainLoop();
	return 0;
}