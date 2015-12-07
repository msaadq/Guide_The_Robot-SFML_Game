
/*
class Robot{
	int x, y;

public:
	Robot(RenderWindow &window2, Event &event2){
		Texture robot;
		robot.loadFromFile("E://Robot Empty.png");
		Sprite rob_sprite(robot);

		x=25;
		y=25;

		if(x==25 && y==25){
			window2.draw(rob_sprite);
			rob_sprite.setOrigin(25,25);
		}

		rob_sprite.setPosition(x,y);
		window2.draw(rob_sprite);
		window2.display();

		if(event2.type==Event::KeyPressed){

			switch(event2.key.code){
			case Keyboard::Right:
				x+=50;
				break;
			case Keyboard::Left:
				x-=50;
				break;
			case Keyboard::Up:
				y-=50;
				break;
			case Keyboard::Down:
				y+=50;
				break;
			case Keyboard::D:
				rob_sprite.rotate(90);
				cout<<rob_sprite.getRotation()<<endl;
				break;
			case Keyboard::A:
				rob_sprite.rotate(-90);
				break;
			default:
				break;
			}
		}
	}
};
*/