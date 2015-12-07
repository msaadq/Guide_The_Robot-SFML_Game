#include "Mainmenu.cpp"
#include "Robot.cpp"
#include <clock.hpp>

void place_sprite(Sprite &, int, int, int);
void place_sprite2(RenderWindow &, Sprite &, int, int, int);
int proximity_check(Vector2f, Vector2f, Sprite);
void maneuver_rob(Texture &, Event &, int &, Sprite &, Sprite &, Sprite &, Sprite &, Sprite &, Sprite &, Sprite &, Sprite &, Sprite &, int[]);
void forward(Sprite &);
void populating(Vector2i &, Texture &, Sprite &, string, string, int, int, int, int, int[], int[], int &, int[], int, int &);

RenderWindow window2(VideoMode(1250, 700), "Guide Me");
Vector2f posR, posRB, posBB, posYB, posRP, posBP, posYP, posAC, posC;
int x = 1175, y = 75;
int cond = 1, cond1 = 1, cond2 = 1, cond3 = 1, cond4 = 1, cond5 = 1, cond6 = 1, loaded = 0, loadedR = 0, loadedB = 0, loadedY = 0;
int arr[20][21];
int p_x = 1, p_y = 1;
int num=0;



int main(){
	int arr_comd[36];
	int comd_pos = 0;
	Texture robot, red_box, blue_box, yellow_box, red_place, blue_place, yellow_place, block, clock_d, antiClock_d, up_arr, right_arr, left_arr, wait, grip, loose, play;
	string A[35];
	A[0] = "C://Users/Saad/Dropbox/Project/Robot Empty.png";
	A[1] = "C://Users/Saad/Dropbox/Project/Robot Red.png";
	A[2] = "C://Users/Saad/Dropbox/Project/Robot Blue.png";
	A[3] = "C://Users/Saad/Dropbox/Project/Robot Yellow.png";
	A[4] = "C://Users/Saad/Dropbox/Project/Red.png";
	A[5] = "C://Users/Saad/Dropbox/Project/Empty Red.png";
	A[6] = "C://Users/Saad/Dropbox/Project/Red Full.png";
	A[7] = "C://Users/Saad/Dropbox/Project/Blue.png";
	A[8] = "C://Users/Saad/Dropbox/Project/Empty Blue.png";
	A[9] = "C://Users/Saad/Dropbox/Project/Blue Full.png";
	A[10] = "C://Users/Saad/Dropbox/Project/Yellow.png";
	A[11] = "C://Users/Saad/Dropbox/Project/Empty Yellow.png";
	A[12] = "C://Users/Saad/Dropbox/Project/Yellow Full.png";
	A[13] = "C://Users/Saad/Dropbox/Project/Up.png";
	A[14] = "C://Users/Saad/Dropbox/Project/Up H.png";
	A[15] = "C://Users/Saad/Dropbox/Project/Left.png";
	A[16] = "C://Users/Saad/Dropbox/Project/Left H.png";
	A[17] = "C://Users/Saad/Dropbox/Project/Right.png";
	A[18] = "C://Users/Saad/Dropbox/Project/Right H.png";
	A[19] = "C://Users/Saad/Dropbox/Project/Clock.png";
	A[20] = "C://Users/Saad/Dropbox/Project/Clock H.png";
	A[21] = "C://Users/Saad/Dropbox/Project/Open.png";
	A[22] = "C://Users/Saad/Dropbox/Project/Open H.png";
	A[23] = "C://Users/Saad/Dropbox/Project/Close.png";
	A[24] = "C://Users/Saad/Dropbox/Project/Close H.png";
	A[25] = "C://Users/Saad/Dropbox/Project/Play.png";
	A[26] = "C://Users/Saad/Dropbox/Project/Play H.png";
	A[27] = "C://Users/Saad/Dropbox/Project/Block.png";
	A[28] = "C://Users/Saad/Dropbox/Project/C.png";
	A[29] = "C://Users/Saad/Dropbox/Project/A C.png";

	robot.loadFromFile(A[0]);
	red_box.loadFromFile(A[4]);
	red_place.loadFromFile(A[5]);
	blue_box.loadFromFile(A[7]);
	blue_place.loadFromFile(A[8]);
	yellow_box.loadFromFile(A[10]);
	yellow_place.loadFromFile(A[11]);
	block.loadFromFile(A[27]);
	clock_d.loadFromFile(A[28]);
	antiClock_d.loadFromFile(A[29]);
	up_arr.loadFromFile(A[13]);
	right_arr.loadFromFile(A[17]);
	left_arr.loadFromFile(A[15]);
	wait.loadFromFile(A[19]);
	loose.loadFromFile(A[21]);
	grip.loadFromFile(A[23]);
	play.loadFromFile(A[25]);

	Sprite rob_sprite(robot), playb(play);
	Sprite block_sur(block);
	Sprite Rbox_sprite(red_box), Rplace_sprite(red_place);
	Sprite Bbox_sprite(blue_box), Bplace_sprite(blue_place);
	Sprite Ybox_sprite(yellow_box), Yplace_sprite(yellow_place);
	Sprite c_dir(clock_d), ac_dir(antiClock_d);
	Sprite S1(up_arr), S2(left_arr), S3(right_arr), S4(wait), S5(loose), S6(grip);

	int p_1x[20], p_1y[20], p_1 = 0, p_2x[20], p_2y[20], p_2 = 0, p_3x[20], p_3y[20], p_3 = 0, p_4x[20], p_4y[20], p_4 = 0, p_5x[20], p_5y[20], p_5 = 0, p_6x[20], p_6y[20], p_6 = 0;

	Vector2i mouse_pos;

	Event event2;

	while (window2.isOpen()){


		while (window2.pollEvent(event2)){

			if (event2.type == Event::Closed)
				window2.close();

			window2.clear(Color::White);

			mouse_pos = Mouse::getPosition(window2);

			if (p_x > 4){
				p_y++;
				p_x = 1;
				if (p_y > 9)
					window2.close();
			}



			populating(mouse_pos, up_arr, S1, A[14], A[13], 99, 55, 599, 550, p_1x, p_1y, p_1, arr_comd, 1, comd_pos);

			populating(mouse_pos, left_arr, S2, A[16], A[15], 149, 100, 599, 550, p_2x, p_2y, p_2, arr_comd, 2, comd_pos);

			populating(mouse_pos, right_arr, S3, A[18], A[17], 199, 150, 599, 550, p_3x, p_3y, p_3, arr_comd, 3, comd_pos);

			populating(mouse_pos, wait, S4, A[20], A[19], 249, 200, 599, 550, p_4x, p_4y, p_4, arr_comd, 4, comd_pos);

			populating(mouse_pos, loose, S5, A[22], A[21], 149, 100, 649, 600, p_5x, p_5y, p_5, arr_comd, 5, comd_pos);

			populating(mouse_pos, grip, S6, A[24], A[23], 199, 150, 649, 600, p_6x, p_6y, p_6, arr_comd, 6, comd_pos);

			if (mouse_pos.x < 199 && mouse_pos.x > 100 && mouse_pos.y>500 && mouse_pos.y < 549){
				play.loadFromFile(A[26]);
				if (Mouse::isButtonPressed(Mouse::Left)){
					for (int i=0; arr_comd[i]>0;i++)
						maneuver_rob(robot, event2, loaded, rob_sprite, Rbox_sprite, Bbox_sprite, Ybox_sprite, Rplace_sprite, Bplace_sprite, Yplace_sprite, c_dir, ac_dir, arr_comd);
				}
					
			}
			else
				play.loadFromFile(A[25]);

			for (int i = 25; i<1250; i += 50) {
				for (int j = 25; j <= 700; j += 50){
					if ((i != 25 && i != 275 && i != 1225) && (j != 25 && j != 675))
						continue;
					place_sprite(block_sur, i, j, 1);
				}
				if (i <= 225){
					place_sprite(block_sur, i, 525, 1);

				}

			}

			place_sprite(block_sur, 75, 625, 1);
			place_sprite(block_sur, 225, 625, 1);
			place_sprite(c_dir, 625, 475, 0);
			place_sprite(ac_dir, 525, 475, 0);

			place_sprite(playb, 125, 525, 0);

			place_sprite(S1, 75, 575, 0);
			place_sprite(S2, 125, 575, 0);
			place_sprite(S3, 175, 575, 0);
			place_sprite(S4, 225, 575, 0);
			place_sprite(S5, 125, 625, 0);
			place_sprite(S6, 175, 625, 0);

			if (cond == 1){
				window2.draw(rob_sprite);
				rob_sprite.setOrigin(25, 25);
				rob_sprite.setPosition(1175, 75);
				cond = 0;
			}

			if (cond1 == 1)
				place_sprite(Rbox_sprite, 325, 75, 1);

			if (cond2 == 1)
				place_sprite(Bbox_sprite, 1175, 375, 1);

			if (cond3 == 1)
				place_sprite(Ybox_sprite, 425, 225, 1);

			place_sprite(Rplace_sprite, 425, 425, 1);
			if (cond4 != 1)
				red_place.loadFromFile(A[6]);

			place_sprite(Bplace_sprite, 625, 425, 1);
			if (cond5 != 1)
				blue_place.loadFromFile(A[9]);

			place_sprite(Yplace_sprite, 725, 325, 1);
			if (cond6 != 1)
				yellow_place.loadFromFile(A[12]);

			rob_sprite.setPosition(x, y);
			window2.draw(rob_sprite);
			window2.display();
		}
	}
	
	for (int i = 0; i<36; i++)
		cout << arr_comd[i] << endl;
	system("pause");
	return 0;
}

void place_sprite(Sprite &sprite, int a, int b, int cond){
	window2.draw(sprite);
	sprite.setOrigin(25, 25);
	sprite.setPosition(a, b);
	if (cond == 1)
		arr[(a - 25) / 50][(b - 25) / 50] = 1;
}

void place_sprite2(RenderWindow &window2, Sprite &sprite, int a, int b, int cond){
	window2.draw(sprite);
	sprite.setOrigin(25, 25);
	sprite.setPosition(a, b);
	if (cond == 1)
		arr[(a - 25) / 50][(b - 25) / 50] = 1;
}

void populating(Vector2i &mouse_pos, Texture &texture, Sprite &sprite, string string1, string string2, int x_h, int x_l, int y_h, int y_l, int p_cx[], int p_cy[], int &p_c, int arr_comd[], int condition, int &comd_pos){
	if (mouse_pos.x > x_l && mouse_pos.x< x_h && mouse_pos.y>y_l && mouse_pos.y < y_h) {
		texture.loadFromFile(string1);
		if (Mouse::isButtonPressed(Mouse::Left)){
			p_cx[p_c] = p_x;
			p_cy[p_c] = p_y;
			p_x++;
			p_c++;
			arr_comd[comd_pos] = condition;
			comd_pos++;
		}
	}
	else
		texture.loadFromFile(string2);

	for (int i = 0; i <= p_c - 1; i++){
		place_sprite(sprite, (p_cx[i] * 50) + 25, (p_cy[i] * 50) + 25, 0);
	}
}

int proximity_check(Vector2f posB, Vector2f posR, Sprite rob_sprite){
	return (((((posB.x == posR.x + 50) && (90 == rob_sprite.getRotation())) || ((posB.x == posR.x - 50) && (270 == rob_sprite.getRotation()))) && (posB.y == posR.y)) ||
		(((posB.y == posR.y + 50) && (180 == rob_sprite.getRotation())) || ((posB.y == posR.y - 50) && (0 == rob_sprite.getRotation()))) && (posB.x == posR.x)) ? 1 : 0;
}


void maneuver_rob(Texture &robot, Event &event2, int &loaded, Sprite &rob_sprite, Sprite &Rbox_sprite, Sprite &Bbox_sprite, Sprite &Ybox_sprite, Sprite &Rplace_sprite, Sprite &Bplace_sprite, Sprite &Yplace_sprite, Sprite &c_dir, Sprite &ac_dir, int arr_comd[]){

		posR = rob_sprite.getPosition();
		posRB = Rbox_sprite.getPosition();
		posBB = Bbox_sprite.getPosition();
		posYB = Ybox_sprite.getPosition();
		posRP = Rplace_sprite.getPosition();
		posBP = Bplace_sprite.getPosition();
		posYP = Yplace_sprite.getPosition();
		posC = c_dir.getPosition();
		posAC = ac_dir.getPosition();

		int i1 = posR.x, j1 = posR.y;

		if (posR == posC)
			rob_sprite.rotate(90);

		if (posR == posAC)
			rob_sprite.rotate(-90);

		switch (arr_comd[num]){

		case 1:
			forward(rob_sprite);
			break;

		case 3:
			rob_sprite.rotate(90);
			break;
		case 2:
			rob_sprite.rotate(-90);
			break;
		case 6:
			if (loaded == 0){

				if (proximity_check(posRB, posR, rob_sprite)){
					robot.loadFromFile("C://Users/Saad/Dropbox/Project/Robot Red.png");
					cond1 = 0;
					loadedR = 1;
					int x1 = (posRB.x - 25) / 50, y1 = (posRB.y - 25) / 50;
					arr[x1][y1] = 0;
				}

				if (proximity_check(posBB, posR, rob_sprite)){
					robot.loadFromFile("C://Users/Saad/Dropbox/Project/Robot Blue.png");
					cond2 = 0;
					loadedB = 1;
					int x1 = (posBB.x - 25) / 50, y1 = (posBB.y - 25) / 50;
					arr[x1][y1] = 0;
				}

				if (proximity_check(posYB, posR, rob_sprite)){
					robot.loadFromFile("C://Users/Saad/Dropbox/Project/Robot Yellow.png");
					cond3 = 0;
					loadedY = 1;
					int x1 = (posYB.x - 25) / 50, y1 = (posYB.y - 25) / 50;
					arr[x1][y1] = 0;
				}
				loaded = 1;
			}

			break;

		case 5:
			if (loaded == 1){

				if (proximity_check(posRP, posR, rob_sprite) && (loadedR == 1)){
					cond4 = 0;
					robot.loadFromFile("C://Users/Saad/Dropbox/Project/Robot Empty.png");
					loaded = 0;
					loadedR = 0;
				}

				if (proximity_check(posBP, posR, rob_sprite) && (loadedB == 1)){
					cond5 = 0;
					robot.loadFromFile("C://Users/Saad/Dropbox/Project/Robot Empty.png");
					loaded = 0;
					loadedB = 0;
				}

				if (proximity_check(posYP, posR, rob_sprite) && (loadedY == 1)){
					cond6 = 0;
					robot.loadFromFile("C://Users/Saad/Dropbox/Project/Robot Empty.png");
					loaded = 0;
					loadedY = 0;
				}

			}
			break;

		default:
			break;
			num++;
		}

		if (arr[(x - 25) / 50][(y - 25) / 50] == 1){
			x = i1;
			y = j1;
		}
}

void forward(Sprite &rob_sprite){
	int angle = rob_sprite.getRotation();
	switch (angle){
	case 0:
		y -= 50;
		break;
	case 90:
		x += 50;
		break;
	case 180:
		y += 50;
		break;
	case 270:
		x -= 50;
		break;
	}
}