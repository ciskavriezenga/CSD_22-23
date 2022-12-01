#include "audioToFile.h"

WriteToFile::WriteToFile(std::string fileName, bool overwrite)
{
  // check if we are allowed to overwrite file
  if(!overwrite) {
    if(fileExists(fileName)){
      std::cout << "\n------WriteToFile::WriteToFile------"
        << "File already exists, not allowed to overwrite!\n";
      // NOTE: for now, simple solution: EXIT
      throw "WriteToFile::WriteToFile - not able to open file: it already exists and not allowed to overwrite it.";
    }
  }
  openFile(fileName);
}

WriteToFile::~WriteToFile()
{
  file.close();
}

bool WriteToFile::write(std::string text)
{
  if(file.is_open())
  {
    file << text;
    return true;
  } else return false;
}

bool WriteToFile::fileExists(const std::string& fileName)
{
  // create a variable of type "struct stat"
  struct stat buffer;
  //check if file exists
  if (stat(fileName.c_str(), &buffer) != -1)
  {
    return true;
  }
  return false;
}

bool WriteToFile::openFile(std::string fileName)
{
  file.open(fileName);
  return file.is_open();
}



AudioToFile::AudioToFile(CustomCallback *callback) : callback(callback){
  // instantiate fileWriter and AudioBuffer
  fileWriter = new WriteToFile("output.csv", true);
}
AudioToFile::~AudioToFile() {
  delete fileWriter;
  fileWriter = nullptr;
}

void AudioToFile::write()
{
  // TODO - CODE REVIEW
  // CODE BELOW IS HASTLY CODED ...
  const int numFrames = 256;
  const int numChannels = 1;
  // due to const inputChannels, we already need to initialize an input buffer
  float* inputBuffer = new float[numFrames];
  AudioBuffer audioBuffer = AudioBuffer {
    .inputChannels = const_cast<const float**>(&inputBuffer),
    .outputChannels = new float*[numChannels],
    .numInputChannels = numChannels,
    .numOutputChannels = numChannels,
    .numFrames = numFrames
  };
  // initialize output buffer
  audioBuffer.outputChannels[0] = new float[numFrames];

  callback->process(audioBuffer);
  for(int i = 0; i < numFrames; i++) {
    fileWriter->write(std::to_string(audioBuffer.outputChannels[0][i]) + "\n");
  }
    // delete all buffers
  delete [] inputBuffer;
  //due to cast no need to delete [] buffer.inputChannels;
  delete [] *(audioBuffer.outputChannels);
  delete [] audioBuffer.outputChannels;
}