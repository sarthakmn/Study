#include <iostream>
using namespace std;

class AudioManager {
    int nb_frames;        // Number of frames
    int samplerate;       // Sample rate
public:
    int buffer[256];      // Audio buffer

    // Set number of frames
    void set_nbFrames(int nb_frames) {
        this->nb_frames = nb_frames;       // this points to current object data also distinguish data members from parameters
    }

    // Set sample rate
    void set_samplerate(int samplerate) {
        this->samplerate = samplerate;
    }

    // Print audio parameters and first buffer value
    void get_audioParams() {
        cout << "nbframes : " << nb_frames << endl;
        cout << "Sample Rate : " << samplerate << endl;
        cout << "Buffer[0] : " << buffer[0] << endl;
    }
};

int main() {
    AudioManager am; // Create an object of AudioManager

    // Set values using member functions
    am.set_nbFrames(20);
    am.set_samplerate(44100);

    // Set first buffer value
    am.buffer[0] = 10;

    // Print all parameters
    am.get_audioParams();

    return 0;
}