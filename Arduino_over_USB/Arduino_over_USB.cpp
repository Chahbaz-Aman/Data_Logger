#include "stdafx.h"

using namespace System;
using namespace System::IO;
using namespace System::IO::Ports;
using namespace System::Resources;

int main(array<System::String ^> ^args)
{
	SerialPort nano("COM5", 9600); 
	String^ resPath = gcnew String("C:\\Users\\Asus\\source\\repos\\Arduino_over_USB\\Arduino_over_USB\\Strings.resx");
		ResXResourceSet^ set = gcnew ResXResourceSet(resPath);
	String^ line;
	String^ end = gcnew String("EOF\r");
		String^ header = set->GetString("header");
		String^ path = set->GetString("path");
		int logNo = 1;
		bool f = true;

	Console::SetWindowSize(81,20);
	Console::WriteLine(header);
	
	try {
		nano.Open();
		Console::WriteLine(" Awaiting Start Signal...");
	}
	catch (...) {
		Console::WriteLine("Device Not Found.");
		f = false;
	}

	while (File::Exists(String::Concat(path, "DataLog", logNo, ".csv")))
		logNo++;
	StreamWriter^ file = gcnew StreamWriter(String::Concat(path, "DataLog", logNo, ".csv"));

	if (f) {
		if (line = nano.ReadLine()) {
			Console::Write("\n     Receiving...\n\t    Current Temperature: " + line);
		}
		do {
			line = nano.ReadLine();
			Console::Write("\b\t    Current Temperature : " + line);
			if (String::Equals(line, end))
			{
				Console::Clear();
				nano.Close();
				break;
			}
			file->Write(line);
		} while (1);
	}

	file->Close();
	Console::WriteLine("\nEnd of Read. Press any Key to continue...");
	Console::ReadKey();
    return 0;
}
