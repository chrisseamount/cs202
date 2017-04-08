#pragma once
#include<ostream>
#include<istream>

using std::ostream;
using std::istream;

//This is important for Networking. It serializes the player direction, x, and y axis.

struct Player
{
	int positionX;
	int positionY;
	int playerDirection;

	char* someNullTerminatedName;

	/*
	This wraps the struct of an object of a Player. 
	It's important for networking, and we definetely need these functions.
	ex:
		nameOfPlayerObject.serialize();
		nameOfPlayerObject.deserialize();
	*/
	ostream& serialize(std::ostream& os) const {
		char null = '\0';
		os.write((char*)&positionX, sizeof(positionX));
		os.write((char*)&positionY, sizeof(positionY));
		os.write((char*)&playerDirection, sizeof(playerDirection));
		os.write(someNullTerminatedName, strlen(someNullTerminatedName));
		os.write(&null, 1);
		return os;
	}

	istream& deserialize(std::istream& is) {
		char buffer[1024];
		int i = 0;
		is.read((char*)&positionX, sizeof(positionX));
		is.read((char*)&positionY, sizeof(positionY));
		is.read((char*)&playerDirection, sizeof(playerDirection));

		do{ buffer[i] = is.get(); ++i; } while (buffer[i] != '\0');
		if (someNullTerminatedName != NULL) free(someNullTerminatedName);
		someNullTerminatedName = (char*)malloc(i);
		for (i = 0; buffer[i] != '\0'; ++i) { someNullTerminatedName[i] = buffer[i]; }
		return is;
	}
};
