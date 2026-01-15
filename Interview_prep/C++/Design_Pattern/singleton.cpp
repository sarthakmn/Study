/* 
A Singleton is a design pattern that ensures only one instance of a class is created in the entire program.
Rules :
private constructor
static funtion & return static object;
*/
#include <iostream>
using namespace std;

class AudioManager{
    private :
        AudioManager(){}
    public :
        AudioManager (const AudioManager&) = delete;
        AudioManager& operator =(const AudioManager&) = delete;
        static AudioManager& getInstance(){
            static AudioManager am;
            return am;
        }
};

int main(void){
    AudioManager& am1 = AudioManager::getInstance();
    AudioManager& am2 = AudioManager::getInstance();
    cout << &am1 << endl << &am2 << endl;
    return 0;
}