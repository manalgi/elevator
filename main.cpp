#include <iostream>
using namespace std;

int f = 0, s = 0, t = 0;

class Lift {
	public:
	int fl[10],dir,goal,location;
	//clean array
	Lift() {
		for (int i = 0; i < 10; i++) {
			fl[i] = 11;
		}
		location = 0;//which floor the elevator located
		dir = 0;//diraction of the lift
		goal = 0;
	}
	//moving lift up or down
	void step() {
		if (dir == 1) {
			location++;
		}
		if (dir == -1) {
			location--;
		}
	}
	//sorting the goals from nearest to farest
	void sort() {
		if (dir == 1) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (fl[j] != 11 && fl[i] != 11) {
						if (fl[j] > fl[i]) {
							int tmp = fl[i];
							fl[i] = fl[j];
							fl[j] = tmp;
						}
					}
				}
			}
		}

		if (dir == -1) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (fl[j] != 11 && fl[i] != 11) {
						if (fl[j] < fl[i]) {
							int tmp = fl[i];
							fl[i] = fl[j];
							fl[j] = tmp;
						}
					}
				}
			}
		}
		step();
		
	}
	//print the info about the lifts
	void print(int num) {
		if(dir==1)
		cout <<"lift number "<<num<<" is now in:"<< location << " it is going  up to floor number "  << goal<<endl;
		if (dir == -1)
			cout << "lift number " << num << " is now in:" << location << " it is going  down to floor number " << goal << endl;
		if (dir == 0)
			cout << "lift number " << num << " is now in:" << location << " waiting for order " << endl;
	}



};

class systemlift {
private:
	int floor, goal, dir = 0;
public:
	Lift first, sec, third;
	systemlift() {};
	//input the user data
	void status(int fl, int gl) {
		floor = fl;
		goal = gl;
		if (gl > fl) {
			dir = 1;
		}
		else if (gl < fl) {
			dir = -1;
		}
		check();
	}
	//check and choose the nearest avalible lift
	void check() {
		if (dir == 1 && floor!=goal) {
			if (abs(floor - first.location) <= abs(floor - sec.location) && abs(floor - first.location) <= abs(floor - third.location) && first.dir != -1) {
				if (first.dir == 0) {
					first.goal = goal;
					first.dir = 1;
				}
				else {
					first.fl[f] = goal;
					f++;
				}

			}
			else if (abs(floor - sec.location) <= abs(floor - third.location) && sec.dir != -1) {
				if (sec.dir == 0) {
					sec.goal = goal;
					sec.dir = 1;
				}
				else {
					sec.fl[s] = goal;
					s++;
				}

			}
			else {
				if (third.dir != -1)
				{
					if (third.dir == 0) {
						third.goal = goal;
						third.dir = 1;
					}
					else {
						third.fl[t] = goal;
						t++;
					}

				}
			}
			
		}


		if (dir == -1 && floor != goal) {
			if (abs(floor - first.location) <= abs(floor - sec.location) && abs(floor - first.location) <= abs(floor - third.location) && first.dir != 1) {
				if (first.dir == 0) {
					first.goal = goal;
					first.dir = -1;
				}
				else {
					first.fl[f] = goal;
					f++;
				}
			}
			else if (abs(floor - sec.location) <= abs(floor - third.location)&& sec.dir != 1) {
				if (sec.dir == 0) {
					sec.goal = goal;
					sec.dir = -1;
				}
				else {
					sec.fl[s] = goal;
					s++;
				}
			}
			else {
				if (third.dir != 1)
					if (third.dir == 0) {
						third.goal = goal;
						third.dir = -1;
					}
					else {
						third.fl[t] = goal;
						t++;
					}
			}
		}

	}
	//updating the info of the lift 
	void update() {
		if (first.location == first.goal && first.dir!=0) {
			cout << "lift number 1 achieved etage:" << first.location << endl;
			if (first.fl[0] != 11) {
				first.goal = first.fl[0];
				updatearray(first);
			
			}
			else {
				first.dir = 0;
			}
		}
		if (sec.location == sec.goal && sec.dir != 0) {
			cout << "lift number 2 achieved etage:" << sec.location << endl;
			if (sec.fl[0] != 11) {
				sec.goal = sec.fl[0];
				updatearray(sec);
			
			}
			else {
				sec.dir = 0;
			}
		}
		if (third.location == third.goal && third.dir != 0) {
			cout << "lift number 3 achieved etage:" << third.location << endl;
			if (third.fl[0] != 11) {
				third.goal = third.fl[0];
				updatearray(third);
			
			}
			else {
				third.dir = 0;
			}
		}
	}
	//updating the array 
	void updatearray(Lift &a) {
		for (int i = 0; i < 9; i++) {
			a.fl[i] = a.fl[i + 1];
		}
	}

};






int main(void) {
	int a, b;
	systemlift lift;
	while (1) {
		cout << "which floor are you: ";
		cin >> a;
		cout << "to where?: ";
		cin >> b;
		lift.status(a, b);
		
		lift.first.sort();
		lift.sec.sort();
		lift.third.sort();
		lift.update();
		lift.first.print(1);
		lift.sec.print(2);
		lift.third.print(3);
		if (f == 9)
			f = 0;
		if (s == 9)
			s = 0;
		if (t == 9)
			t = 0;
	}
	system("pause");
	return 0;
}