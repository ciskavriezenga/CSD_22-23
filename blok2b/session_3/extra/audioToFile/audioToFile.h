#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "callback.h"

class WriteToFile
{
public:
  WriteToFile(std::string fileName, bool overwrite=false);
  ~WriteToFile();

  bool write(std::string text);

private:
  bool fileExists(const std::string& fileName);
  bool openFile(std::string fileName);
  std::ofstream file;
};


class AudioToFile
{
public:
  // TODO
  // add functionality to set numFrames and channels
  AudioToFile(CustomCallback *callback);
  ~AudioToFile();
  // TODO
  // add functionality to write a given range to file
  void write();
private:
  // hide default constructor
  AudioToFile() {}

  CustomCallback* callback;
  WriteToFile* fileWriter;
};
