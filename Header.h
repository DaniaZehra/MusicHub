#pragma once
#include <iostream>
#include <windows.h>
#include <stack>
#include <queue>
#include <fstream>
#include <list>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/access.hpp>
#define TABLE_SIZE = 100;
using namespace std;
class Song {
private:
	string name;
	string artist;
	float duration;
	float energy;
	float key;
	float loudness;
	float speechiness;
	float acousticness;
	float instrumentalness;
	float liveness;
	float tempo;

public:
	Song(const string& n, const string& a) : name(n), artist(a), duration(0), energy(0), key(0), loudness(0), speechiness(0), acousticness(0), instrumentalness(0), liveness(0), tempo(0) {}
	void setName(string n)
	{
		name = n;
	}
	void setArtist(const string& a)
	{
		artist = a;
	}
	void setDuration(float dur)
	{
		duration = dur;
	}
	void setEnergy(float en)
	{
		energy = en;
	}
	void setKey(float k)
	{
		key = k;
	}
	void setLoudness(float loud)
	{
		loudness = loud;
	}
	void setSpeechiness(float spch)
	{
		speechiness = spch;
	}
	void setAcousticness(float ac)
	{
		acousticness = ac;
	}
	void setInstrumentalness(float instr)
	{
		instrumentalness = instr;
	}
	void setLiveness(float live)
	{
		liveness = live;
	}
	void setTempo(float tmp)
	{
		tempo = tmp;
	}

	string getName()
	{
		return name;
	}
	string getArtist()
	{
		return artist;
	}
	float getDuration()
	{
		return duration;
	}
	float getEnergy()
	{
		return energy;
	}
	float getKey()
	{
		return key;
	}
	float getLoudness()
	{
		return loudness;
	}
	float getSpeechiness()
	{
		return speechiness;
	}
	float getAcousticness()
	{
		return acousticness;
	}
	float getInstrumentalness()
	{
		return instrumentalness;
	}
	float getLiveness()
	{
		return liveness;
	}
	float getTempo()
	{
		return tempo;
	}
	void displayInfo();
};

class User {
public:
    string username;
    string password;
   /* PlayList* FirstPL;
    stack<Song*> ListeningHistory;
    priority_queue<int> MostListenedToSongs;
    stack<Song*> LikedSongs;*/
    User(string usern, string passw);
    User();
private:
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& username;
        ar& password;
    }
};

class UserHashTable {
    vector<list<User>> HashTable;
    void HashFunction(User u1);
public:

};
class Menu {
public:
    void SignUpPrompt();
    void LoginPrompt();
    void Welcome();
    void Logo();
};