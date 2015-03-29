#ifndef Renamer_H
#define Renamer_H

using namespace std;

class Renamer {
	public:
		Renamer();
		Renamer(int, int, int);
		void renames(string);
	
	private:
		void setFileIn(int);
		void setFileOut(int, int);
		void setCh(int);
		int setHal();
		string ifn; 
		string ofn;
		int hal;
		int last;
		int chi;
		int chf;
		int vol;
		int result;
};

#endif
