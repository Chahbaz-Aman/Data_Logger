#include "stdafx.h"

using namespace System;
using namespace System::IO;
using namespace System::IO::Ports;
using namespace System::Resources;


int main(array<System::String ^> ^args)
{
	SerialPort nano("COM5", 9600); 
	String^ line;
	String^ end = gcnew String("EOF\r");
	ResXResourceSet^ set = gcnew ResXResourceSet("C:\\Users\\Asus\\source\\repos\\Arduino_over_USB\\Arduino_over_USB\\Strings.resx");
	String^ header = set->GetString("header");
	String^ path = set->GetString("path");

	Console::SetWindowSize(81,20);
	Console::Clear();
	nano.Open();
	
	if (File::Exists(path)) {
		File::Delete(path);
	}

	StreamWriter^ file = gcnew StreamWriter(path);
	Console::WriteLine(header); 
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
