#include <iostream>
#include "Log.h"


int main() {
	Log logger{};
	logger.SetLevel(Log::LevelWarning);
	logger.Info("Hello World!");
	logger.Warn("Hello World!");
	logger.Error("Hello World!");
	std::cin.get();
}
