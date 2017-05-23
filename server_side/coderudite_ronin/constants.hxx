#ifndef CONSTANTS_HXX
#define CONSTANTS_HXX

#include <string>

#define Y2X(X)	#X
#define MAC2STR(Y) Y2X(Y)


const std::string appRoot = MAC2STR(APPROOT);
const std::string dataRoot = appRoot + "/data";
const std::string siteRoot = dataRoot + "/webroot";
const std::string tmpRoot = dataRoot + "/tmp";
const std::string userDataRoot = dataRoot + "/user";
const std::string dbPath = userDataRoot + "/database.db";
const std::string problemDir = userDataRoot+"/problems";

#endif // CONSTANTS_HXX
