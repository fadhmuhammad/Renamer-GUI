#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "Renamer.h"

using namespace std;

Renamer::Renamer(){
	ifn = "One Piece V02 #009/001.jpg";
	ofn = "One Piece V02 #009/001.jpg";	
	chi = 1;
	chf = 8;
	vol = 1;
	last = 0;
}

Renamer::Renamer(int _vol, int _chi, int _chf){
	chi = _chi;
	chf = _chf;
	vol = _vol;
	last = 0;
	ifn = "One Piece V02 #009/003.jpg";
	ofn = "One Piece V02 #009/007.jpg";
		
	if (vol < 10){
		ifn[12] = '0' + vol;
		ofn[12] = '0' + vol;
	} else if (vol > 9){
		ostringstream osc;
		osc << vol;
		string v = osc.str();
		
		ifn[11] = v[0];
		ifn[12] = v[1];
		
		ofn[11] = v[0];
		ofn[12] = v[1];
	}
}

void Renamer::setCh(int ch){
	if (ch < 10){		
		ifn[17] = '0' + ch;
		ofn[17] = '0' + ch;
	} else if (ch > 9 && ch < 100) {
		ostringstream osv;
		osv << ch;
		string c = osv.str();
		
		ifn[16] = c[0];
		ifn[17] = c[1];
	
		ofn[16] = c[0];
		ofn[17] = c[1];
	} else if (ch > 99){
		ostringstream osv;
		osv << ch;
		string c = osv.str();
	
		ifn[15] = c[0];
		ifn[16] = c[1];
		ifn[17] = c[2];
			
		ofn[15] = c[0];
		ofn[16] = c[1];
		ofn[17] = c[2];
  	}

}

void Renamer::setFileIn(int pg){
	if (pg < 10){
	 	ifn[19] = '0';
	 	ifn[20] = '0';
  		ifn[21] = '0' + pg;
  	} else if (pg > 9) {
		ostringstream oss;
  		oss << pg;
  		string s = oss.str();
  		
  		ifn[20] = s[0];
  		ifn[21] = s[1];
  	}
}

void Renamer::setFileOut(int _last, int pg){
	if (_last + pg < 9){
  		ofn[21] = '0' + pg;
  	} else if (_last + pg > 9 && _last + pg < 100){
  		ostringstream osf;
  		osf << _last + pg;
  		string f = osf.str();
  		
  		ofn[20] = f[0];
  		ofn[21] = f[1];
  	} else if (last + pg > 99) {
  		ostringstream osk;
  		osk << _last + pg;
  		string k = osk.str();
  		
		ofn[19] = k[0];
  		ofn[20] = k[1];
  		ofn[21] = k[2];
  	}
  	
}

void Renamer::renames(string _hal){
	std::istringstream iss (_hal);
	for (int i = chi; i <= chf; i++){
		setCh(i);
		iss >> hal;
		for (int j = 1; j <= hal; j++){
			setFileIn(j);
			setFileOut(last, j);	
			cout << ifn << "\t" << ofn << "\t";
			result= rename( ifn.c_str() , ofn.c_str() );
			if ( result == 0 )
	    		puts ( "File successfully renamed\n" );
			else
				perror( "Error renaming file\n" );
		}
		last = last + hal;
	}
}
