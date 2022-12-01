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
  AudioToFile(CustomCallback *callback, int numInputchannels = 1,
              int numOutputChannels = 1, int numFrames = 256);
  ~AudioToFile();
  // TODO
  // add functionality to write a given range to file
  void write();
private:
  // hide default constructor
  AudioToFile() {}

  CustomCallback* callback;
  WriteToFile* fileWriter;
  int numInputChannels = 1;
  int numOutputChannels = 1;
  int numFrames = 256;
  float **inputChannel;
  float **outputChannel;
};
