#include <iostream>
#include <utility>
using namespace std;

class AudioManager {
    int nb_frames;
    int samplerate;
public:
    // Default constructor
    AudioManager() : nb_frames(0), samplerate(44100) {
        cout << "Default constructor called! nb_frames = " << nb_frames << ", samplerate = " << samplerate << endl;
    }

    // Parameterized constructor
    AudioManager(int nb, int sr) : nb_frames(nb), samplerate(sr) {
        cout << "Parameterized constructor called! nb_frames = " << nb_frames << ", samplerate = " << samplerate << endl;
    }

    // Copy constructor
    AudioManager(const AudioManager& other) : nb_frames(other.nb_frames), samplerate(other.samplerate) {
        cout << "Copy constructor called! nb_frames = " << nb_frames << ", samplerate = " << samplerate << endl;
    }

    // Move constructor
    // Purpose: Efficiently transfer resources from a temporary (rvalue) object to a new object.
    // Instead of copying, it "moves" the data, leaving the source in a valid but unspecified state.
    // Used when an object is being initialized from a temporary or with std::move().
    AudioManager(AudioManager&& other) noexcept : nb_frames(other.nb_frames), samplerate(other.samplerate) {
        cout << "Move constructor called! nb_frames = " << nb_frames << ", samplerate = " << samplerate << endl;
        // Invalidate the source object's data to show it has been moved from
        other.nb_frames = 0;
        other.samplerate = 0;
    }

    // Destructor
    ~AudioManager() {
        cout << "Destructor called! Cleaning up AudioManager object." << endl;
    }

    void set_nbFrames(int nb) {
        nb_frames = nb;
    }
    void set_samplerate(int sr) {
        samplerate = sr;
    }
    void printParams() {
        cout << "nb_frames: " << nb_frames << ", samplerate: " << samplerate << endl;
    }
};

int main() {
    cout << "Creating am1 with default constructor..." << endl;
    AudioManager am1;
    am1.printParams();

    cout << "\nCreating am2 with parameterized constructor..." << endl;
    AudioManager am2(128, 48000);
    am2.printParams();

    cout << "\nCreating am3 as a copy of am2..." << endl;
    AudioManager am3 = am2; // Copy constructor
    am3.printParams();

    cout << "\nCreating am4 using move constructor from am2..." << endl;
    AudioManager am4 = std::move(am2); // Move constructor
    am4.printParams();
    cout << "am2 after move: "; am2.printParams();

    cout << "\nChanging am1 parameters..." << endl;
    am1.set_nbFrames(256);
    am1.set_samplerate(22050);
    am1.printParams();

    cout << "End of main, destructors will be called automatically." << endl;
    return 0;
}