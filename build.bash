sudo apt install -y libflac-dev libtag-dev
g++ -o tl1 $(taglib-config --cflags) tl1.cc -Xlinker $(taglib-config --libs) && ./tl1 ~/hdmusic/Bjork/VOLTA/01\ -\ Earth\ Intruders.flac

