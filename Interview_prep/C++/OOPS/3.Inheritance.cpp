#include <iostream>
using namespace std;

/*
Access Specifiers :
Public : access from any object
protected : access from derived class
private : access from same class member functions

Base Member     |	Public Inheritance	    | Protected Inheritance	 |  Private Inheritance
public	        |           public	        |        protected	     |        private
protected	    |           protected	    |        protected	     |        private
private	        |           private         |    	 private         |  	  private
*/

// Base class
class AudioDevice {
public:
    int volume;
    AudioDevice() : volume(50) {
        cout << "AudioDevice constructor called!" << endl;
    }
    void setVolume(int v) {
        volume = v;
    }
    void showVolume() {
        cout << "Volume: " << volume << endl;
    }
};

// Derived class
class Speaker : public AudioDevice {
public:
    string brand;
    Speaker(string b) : brand(b) {
        cout << "Speaker constructor called!" << endl;
    }
    void showBrand() {
        cout << "Brand: " << brand << endl;
    }
};

int main() {
    Speaker spk("Sony");
    spk.setVolume(80);
    spk.showBrand();
    spk.showVolume();
    return 0;
}
