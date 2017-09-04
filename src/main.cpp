#include <iostream>
#include <string>
using namespace std;

// Не работает выделение памяти
class TimeTable {
	int size_table;
	int capacity;
	OneTable *Table;
public:
	TimeTable(int size) {
		Table = new OneTable [size];
		capacity = 0;
	}
	void installName(string name) {
		name_station[capacity] = name;
		capacity++;
	}
	void printTable() {
		for (int i = 0; i < capacity; i++) {
			cout << name_station[i] << endl;
		}
	}
	void addToTable(string name, int hour, int minute) {
		Clock time(hour, minute);
		OneTable cell(name, time);
		Table[capacity] = cell;
		capacity++;
	}
};

class OneTable {
	string name_station;
	Clock time;
public:
	OneTable(string name, Clock tm) {
		name_station = name;
		time = tm;
	}
};


class Clock {
	int hour;
	int minute;
public:
	Clock(int hr, int mnt) {
		hour = hr;
		minute = mnt;
	}

	int getHour() { return hour; }
	int getMinute() { return minute; }
	
	void putHour(int hr) { hour = hr; }
	void putMinute(int mt) { minute = mt; }

	Clock recuclClock(Clock src, Clock add)
	{
		src.putHour(add.getHour() + src.getHour());
		if ((add.getMinute() + src.getMinute()) >= 60) {
			int tmp_min = add.getMinute() + src.getMinute();
			for (; tmp_min >= 60; tmp_min -= 60) {
				src.putHour(src.getHour() + 1);
			}
			src.putMinute(tmp_min);
		} else{
			src.putMinute(add.getMinute() + src.getMinute());
		}
		
		return src;	
	}

	Clock recuclClock(Clock src, int mt)
	{
		int hr = 0;
		if ((mt += src.getMinute()) >= 60) {
			src.putMinute(0);
			for (; mt >= 60; mt -= 60) {
				hr++;
			}
		}

		src.putHour(src.getHour() + hr);
		src.putMinute(src.getMinute() + mt);

		return src;
	}
	void printTime() {
		if (hour == 0) {
			cout << "0";
		}
		cout << hour << ":" << minute;
		if (minute == 0) {
			cout << "0";
		}
	}
};

int main()
{
	
	return 0;
}