#include "arena.h"

DWORD Arena::pid;
HANDLE Arena::phandle;
HWND Arena::hwnd;

Character *Arena::Player1Yellow = NULL;
Character *Arena::Player2Orange = NULL;
float Arena::YellowPX;
float Arena::YellowPY;
float Arena::OrangePX;
float Arena::OrangePY;
int Arena::Runner;

float Arena::getPlayerOnePosition(HWND hwnd, DWORD pid, HANDLE phandle){
	DWORD address;
	float value;

	address = getAndressPositionXYellow(hwnd, pid, phandle);
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	return value;
}

DWORD Arena::setPlayerOnePosition(HWND hwnd, DWORD pid, HANDLE phandle, float value){
	DWORD address;

	address = getAndressPositionXYellow(hwnd, pid, phandle);
	WriteProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	return value;
}

float Arena::getPlayerTwoPosition(HWND hwnd, DWORD pid, HANDLE phandle){
	DWORD address;
	float value;

	address = getAndressPositionXOrange(hwnd, pid, phandle);
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	return value;
}

DWORD Arena::setPlayerTwoPosition(HWND hwnd, DWORD pid, HANDLE phandle, float value){
	DWORD address;

	address = getAndressPositionXOrange(hwnd, pid, phandle);
	WriteProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	return value;
}

void Arena::playerOne(HWND hwnd, DWORD pid, HANDLE phandle){//Control averything about player ONE
	DWORD value;
	int f;
	while (1){
		apertaA(0,&f);
		apertaG(0);
		apertaF();
		apertaD(100,&f);
		apertaG(0);
		apertaF();
	}
}

void Arena::playerTwo(HWND hwnd, DWORD pid, HANDLE phandle){//Control everything about player TWO.
	DWORD value;
	int f;
	while (1){
		apertaM(0);
		apertaN();
		apertaRightNarrow(0,&f);
		apertaLeftNarrow(0,&f);
	}
}

int Arena::getRunner(HWND hwnd, DWORD pid, HANDLE phandle){// return 0 nobody is running (starting game), return 1 Yellow is running, return 2 Orange is Running, return 3 == fail.
	DWORD Runner = getAndressRunningCharacter(hwnd, pid, phandle);
	if (Runner == 0x00000000) return 0; //return 0 nobody is running (starting game)
	DWORD Orange = getAndressPositionXOrange(hwnd, pid, phandle);
	DWORD Yellow = getAndressPositionXYellow(hwnd, pid, phandle);
	if (Orange == Runner) return 2; //return 2 Orange is Running
	if (Yellow == Runner) return 1; //return 1 Yellow is running

	return 3; //return 3 == fail
}


DWORD Arena::getAndressRunningCharacter(HWND hwnd, DWORD pid, HANDLE phandle){
	DWORD address;
	DWORD InicialAndress = 0x002C608C;
	DWORD value;
	DWORD baseAndress;

	baseAndress = GetProcessBaseAddress(hwnd, pid);
	address = InicialAndress + baseAndress;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0x00;
	if (value == 0x00000000) return 0x00000000;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0x690;
	if (value == 0x00000000) return 0x00000000;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0xc;
	if (value == 0x00000000) return 0x00000000;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0xb8;
	if (value == 0x00000000) return 0x00000000;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0x8;
	if (value == 0x00000000) return 0x00000000;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0x50;
	if (value == 0x00000000) return 0x00000000;

	return address;
}

DWORD Arena::getAndressPositionXOrange(HWND hwnd, DWORD pid, HANDLE phandle){
	DWORD address;
	DWORD InicialAndress = 0x002C608C;
	DWORD value;
	DWORD baseAndress;

	baseAndress = GetProcessBaseAddress(hwnd, pid);
	address = InicialAndress + baseAndress;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0x0;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0x548;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0xc;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0xb0;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0x8;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0x50;

	return address;
}

DWORD Arena::getAndressPositionXYellow(HWND hwnd, DWORD pid, HANDLE phandle){
	DWORD address;
	DWORD InicialAndress = 0x002C608C;
	DWORD value;
	DWORD baseAndress;

	baseAndress = GetProcessBaseAddress(hwnd, pid);
	address = InicialAndress + baseAndress;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0x0;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0x550;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0xc;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0xb0;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0x8;
	ReadProcessMemory(phandle, (LPVOID)address, &value, sizeof(value), 0);
	address = value + 0x50;

	return address;
}

DWORD Arena::GetProcessBaseAddress(HWND window, DWORD pID)
{
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);
	MODULEENTRY32 module;
	module.dwSize = sizeof(MODULEENTRY32);
	Module32First(snapshot, &module);
	DWORD base = (DWORD)module.modBaseAddr;
	//################################################## Show the process list
	//do {// If uncomented show alll base andress.
	//	printf("ModuleName: %S\n", module.szExePath);
	//printf("Base Addr : 0x%08X\n\n", module.modBaseAddr);
	//} while (Module32Next(snapshot, &module));
	//##################################################
	CloseHandle(snapshot);
	return base;
}

void Arena::apertaG(int delay)
// ver site http://www.codeproject.com/Articles/7305/Keyboard-Events-Simulation-using-keybd-event-funct
{
	keybd_event(VkKeyScan('G'), 0xa2, 0, 0); // ‘A’ Press
	Sleep(delay);//O pulo pode demorar de 0 até 600 tempos do sleep (pulo completo = 600)
	keybd_event(VkKeyScan('G'), 0xa2, KEYEVENTF_KEYUP, 0); // ‘A’ Release
	Sleep(10);
}

void Arena::apertaA(int delay, int *f)
// ver site http://www.codeproject.com/Articles/7305/Keyboard-Events-Simulation-using-keybd-event-funct
{
	keybd_event(VkKeyScan('A'), 0x9e, 0, 0); // ‘A’ Press
	Sleep(delay);
	keybd_event(VkKeyScan('A'), 0x9e, KEYEVENTF_KEYUP, 0); // ‘A’ Release
	Sleep(10);
	*f = 0;//Make flag f(flagFreeHorizontal) free to other thread starts.
}

void Arena::apertaLeftNarrow(int delay, int *f)
// ver site http://www.codeproject.com/Articles/7305/Keyboard-Events-Simulation-using-keybd-event-funct
{
	keybd_event(VK_LEFT, 0x9e, 0, 0); // ‘A’ Press
	Sleep(delay);
	keybd_event(VK_LEFT, 0x9e, KEYEVENTF_KEYUP, 0); // ‘A’ Release
	Sleep(10);
	*f = 0;//Make flag f(flagFreeHorizontal) free to other thread starts.
}

void Arena::apertaRightNarrow(int delay, int *f)
// ver site http://www.codeproject.com/Articles/7305/Keyboard-Events-Simulation-using-keybd-event-funct
{
	keybd_event(VK_RIGHT, 0x9e, 0, 0); // ‘A’ Press
	Sleep(delay);
	keybd_event(VK_RIGHT, 0x9e, KEYEVENTF_KEYUP, 0); // ‘A’ Release
	Sleep(10);
	*f = 0;//Make flag f(flagFreeHorizontal) free to other thread starts.
}


void Arena::apertaF()
// ver site http://www.codeproject.com/Articles/7305/Keyboard-Events-Simulation-using-keybd-event-funct
{
	keybd_event(VkKeyScan('F'), 0xa1, 0, 0); // ‘A’ Press
	Sleep(100);
	keybd_event(VkKeyScan('F'), 0xa1, KEYEVENTF_KEYUP, 0); // ‘Angfdmgnfamgnfdgmfangfmdngfam’ Release
	Sleep(10);
}

void Arena::apertaN()
// ver site http://www.codeproject.com/Articles/7305/Keyboard-Events-Simulation-using-keybd-event-funct
{
	keybd_event(VkKeyScan('N'), 0xb1, 0, 0); // ‘A’ Press
	Sleep(1000);
	keybd_event(VkKeyScan('N'), 0xb1, KEYEVENTF_KEYUP, 0); // ‘A’ Release
	Sleep(10);
}

void Arena::apertaD(int delay, int *f)
//see web site http://www.codeproject.com/Articles/7305/Keyboard-Events-Simulation-using-keybd-event-funct
{
	keybd_event(VkKeyScan('D'), 0xa0, 0, 0); // ‘A’ Press
	Sleep(delay);
	keybd_event(VkKeyScan('D'), 0xa0, KEYEVENTF_KEYUP, 0); // ‘A’ Release
	Sleep(10);
	*f = 0;//Make flag f(flagFreeHorizontal) free to other thread starts.
}

void Arena::apertaM(int delay)
//see web site http://www.codeproject.com/Articles/7305/Keyboard-Events-Simulation-using-keybd-event-funct
{
	keybd_event(VkKeyScan('M'), 0xb2, 0, 0); // ‘M’ Press
	Sleep(delay);
	keybd_event(VkKeyScan('M'), 0xb2, KEYEVENTF_KEYUP, 0); // ‘M’ Release
	Sleep(10);
}

void Arena::apertaS(int delay){
	keybd_event(VkKeyScan('S'), 0x9f, 0, 0); // ‘A’ Press
	Sleep(delay);
	keybd_event(VkKeyScan('S'), 0x9f, KEYEVENTF_KEYUP, 0); // ‘A’ Release
	Sleep(10);
}

void Arena::apertaDownNarrow(int delay){
	keybd_event(VK_DOWN, 0x9e, 0, 0); // ‘A’ Press
	Sleep(delay);
	keybd_event(VK_DOWN, 0x9e, KEYEVENTF_KEYUP, 0); // ‘A’ Release
	Sleep(10);
}

void Arena::apertaUpNarrow(int delay){
	keybd_event(VK_UP, 0x9e, 0, 0); // ‘A’ Press
	Sleep(delay);
	keybd_event(VK_UP, 0x9e, KEYEVENTF_KEYUP, 0); // ‘A’ Release
	Sleep(10);
}

void Arena::apertaW(int delay){
	keybd_event(VkKeyScan('W'), 0x91, 0, 0); // ‘A’ Press
	Sleep(delay);
	keybd_event(VkKeyScan('W'), 0x91, KEYEVENTF_KEYUP, 0); // ‘A’ Release
	Sleep(10);
}
void Arena::setPlayerYellow(Character& py){
	Player1Yellow = &py;
	
}

void Arena::setPlayerOrange(Character& po){
	Player2Orange = &po;
}

void Arena::updateInformations(){
	
	int RunnerYellow, RunnerOrange;

	if (Runner == 1){// Runner 0 nobody is running (starting game), Runner 1 Yellow is running, Runner 2 Orange is Running, Runner 3 == fail.
		RunnerYellow = 1;
		RunnerOrange = 2;
	}
	if (Runner == 2){// Runner 0 nobody is running (starting game), Runner 1 Yellow is running, Runner 2 Orange is Running, Runner 3 == fail.
		RunnerYellow = 2;
		RunnerOrange = 1;
	}
	if (Runner == 0){// Runner 0 nobody is running (starting game), Runner 1 Yellow is running, Runner 2 Orange is Running, Runner 3 == fail.
		RunnerYellow = 0;
		RunnerOrange = 0;
	}
	if (Runner == 3){// Runner 0 nobody is running (starting game), Runner 1 Yellow is running, Runner 2 Orange is Running, Runner 3 == fail.
		RunnerYellow = 3;
		RunnerOrange = 3;
	}

	(*Player1Yellow).updateInformation(YellowPX, YellowPY, OrangePX, OrangePY, RunnerYellow);
	(*Player2Orange).updateInformation(OrangePX, OrangePY, YellowPX, YellowPY, RunnerOrange);
}

Arena::Arena(){
	Player1Yellow = new Character;
	Player2Orange = new Character;
}

void Arena::updateControls(){
	(*Player1Yellow).setCommands(apertaD, apertaA, apertaG, apertaF, apertaS, apertaW);
	(*Player2Orange).setCommands(apertaLeftNarrow, apertaRightNarrow, apertaM, apertaN, apertaDownNarrow, apertaUpNarrow);
}

void Arena::findGame(){
	hwnd = FindWindow(NULL, "Nidhogg");// You need put here the title of the main windows of the process that you wanna read and write on.
	if (!hwnd)
	{
		cout << "Window not found!\n";
		system("pause");
		//cin.get();
	}
	else
	{
		GetWindowThreadProcessId(hwnd, &pid);
		//PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_QUERY_INFORMATION | PROCESS_CREATE_THREAD; // This are the kinds os autorizations to manipulate memory from onther process.
		phandle = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_QUERY_INFORMATION | PROCESS_CREATE_THREAD, 0, pid);// This line give the autorizations to use the space of memory from another process.
		if (!phandle)
		{
			cout << "Could not get handle!\n";
			cin.get();
		}
		else
		{
			//thread first(playerOne, hwnd, pid, phandle);//Starts Player One Thread
			//thread second(playerTwo, hwnd, pid, phandle);//Starts Player Two Thread
			cout << "It is working!" << endl;

			/*int old = 0;
			printf("\n\nStarting FIGHT!\n\n");
						
			while (1){
				int who = getRunner(hwnd, pid, phandle);
				if (old != who){
					if (who == 0) printf("NOBODY is Running!\n");
					if (who == 1) printf("Yellow is Running!\n");
					if (who == 2) printf("Orange is Running!\n");
					if (who == 3) printf("CODE FAILLLL!\n");
					old = who;
				}//fim if
			}//fim while*/

			
		}
	}

}

void Arena::fight(){
	while (1){
		//YellowPY;
		//OrangePY;
		YellowPX =  getPlayerOnePosition(hwnd, pid, phandle);
		OrangePX =  getPlayerTwoPosition(hwnd, pid, phandle);
		Runner = getRunner(hwnd, pid, phandle);
		updateInformations();
	}
}

void Arena::startFight(){
	findGame();// Find the PID HANDLER AND PHANDLER of the game.
	updateControls();// Link the commands with the characters.
	(*Player1Yellow).setAvatarColor(1);
	(*Player2Orange).setAvatarColor(2);
	thread first(fight);// Start the Thread.
	first.detach();// Avoid kernel stop thead after the function is over.
}