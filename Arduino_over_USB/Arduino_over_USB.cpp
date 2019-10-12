#include "stdafx.h"

using namespace System;
using namespace System::IO;
using namespace System::IO::Ports;

int main(array<System::String ^> ^args)
{
	SerialPort nano("COM5", 9600); 
	String^ line;
	String^ end = gcnew String("EOF\r");
	String^ path = gcnew String("C:\\Users\\Asus\\Documents\\Thermal Chamber\\DataLog.csv");
	
	Console::Clear();
	nano.Open();
	
	if (File::Exists(path)) {
		File::Delete(path);
	}

	StreamWriter^ file = gcnew StreamWriter(path);
	Console::WriteLine("******************************************************************");
	Console::WriteLine("                           DATA LOGGER                            \n");
	Console::WriteLine("******************************************************************\n"); 
	Console::WriteLine(" Awaiting Start Signal...");
	if (line = nano.ReadLine()) {
		Console::Write("\n     Receiving...\n\t    Current Temperature: " + line);
	}
	do {
		line = nano.ReadLine();
		Console::Write("\b\t    Current Temperature : " + line);
		if (String::Equals(line,end))
		{
			Console::Clear();
			nano.Close();
			break;
		}
		file->Write(line);
	} while(1);

	file->Close();
	Console::WriteLine("\nEnd of Read. Press any Key to continue...");
	Console::ReadKey();
    return 0;
}
