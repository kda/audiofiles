#include <iomanip>
#include <iostream>
#include <cstddef>

#include <fileref.h>
#include <flacfile.h>
#include <tfile.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 0;
  }

  TagLib::FileRef f(argv[1]);
  if (f.isNull()) {
    std::cout << "failed to open: " << argv[1] << std::endl;
    return -1;
  }

  TagLib::FLAC::Properties* flacProperties = dynamic_cast<TagLib::FLAC::Properties*>(f.audioProperties());
  if (flacProperties == NULL) {
    std::cout << "not FLAC file : " << argv[1] << std::endl;
    return 0;
  }
  auto totalSeconds = flacProperties->lengthInSeconds();
  auto minutes = totalSeconds / 60;
  auto seconds = totalSeconds % 60;
  std::cout << flacProperties->sampleRate() << "/" << flacProperties->bitsPerSample()
      << " : " << minutes << ":" << std::setw(2) << std::setfill('0') << seconds << " : " << argv[1] << std::endl;
  return 0;
}
