#include <iostream>
#include <string>
#include "character.h"
#include <iomanip>
#include <Windows.h>
#include <TlHelp32.h> //PROCESSENTRY
#include <windows.h>
#include <thread> 
using namespace std;

#ifndef ARENA_CLASS
#define ARENA_CLASS

class Arena
{
private:

	static DWORD pid;
	static HANDLE phandle;
	static HWND hwnd;

	static Character *Player1Yellow;
	static Character *Player2Orange;
	static float YellowPX;
	static float YellowPY;
	static float OrangePX;
	static float OrangePY;
	static int Runner;

public:
	Arena();
	static void setPlayerYellow(Character& py);
	static void setPlayerOrange(Character& po);
	static void updateInformations();
	static void updateControls();
	static void fight();
	static void startFight();

	static void findGame();
	static DWORD GetProcessBaseAddress(HWND window, DWORD pID);
	static void apertaG(int);
	static void apertaA(int);
	static void apertaF();
	static void apertaD(int);
	static void apertaW(int);
	static void apertaM(int);
	static void apertaN();
	static void apertaS(int);
	static void apertaRightNarrow(int);
	static void apertaLeftNarrow(int);
	static void apertaDownNarrow(int);
	static void	apertaUpNarrow(int);
	static DWORD getAndressPositionXYellow(HWND window, DWORD pID, HANDLE phandle);
	static DWORD getAndressPositionXOrange(HWND hwnd, DWORD pid, HANDLE phandle);
	void playerOne(HWND hwnd, DWORD pid, HANDLE phandle);
	void playerTwo(HWND hwnd, DWORD pid, HANDLE phandle);
	static DWORD setPlayerOnePosition(HWND hwnd, DWORD pid, HANDLE phandle, DWORD value);
	static DWORD getPlayerOnePosition(HWND hwnd, DWORD pid, HANDLE phandle);
	static DWORD setPlayerTwoPosition(HWND hwnd, DWORD pid, HANDLE phandle, DWORD value);
	static DWORD getPlayerTwoPosition(HWND hwnd, DWORD pid, HANDLE phandle);
	static DWORD getAndressRunningCharacter(HWND hwnd, DWORD pid, HANDLE phandle);
	static int getRunner(HWND hwnd, DWORD pid, HANDLE phandle);

};

#endif