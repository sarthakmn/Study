/*
No if / else anywhere
No switching based on string or enum
Adding new states is easy
Each state is responsible for its own transitions
*/

#include <iostream>
using namespace std;

class MediaPlayer;

// ----- Interface -----
class PlayerState {
public:
    virtual void play(MediaPlayer*) = 0;
    virtual void pause(MediaPlayer*) = 0;
    virtual ~PlayerState() {}
};

// ----- Context -----
class MediaPlayer {
    PlayerState* state;
public:
    MediaPlayer(PlayerState* initState) : state(initState) {}

    void setState(PlayerState* newState) {
        state = newState;
    }
    void play()  { state->play(this); }
    void pause() { state->pause(this); }
};

// ----- Concrete States -----
class PlayingState : public PlayerState {
public:
    void play(MediaPlayer* player) override {
        cout << "Already Playing\n";
    }

    void pause(MediaPlayer* player) override;
};

class PausedState : public PlayerState {
public:
    void play(MediaPlayer* player) override;
    void pause(MediaPlayer* player) override {
        cout << "Already Paused\n";
    }
};

// ----- State Transitions -----
void PlayingState::pause(MediaPlayer* player) {
    cout << "Playback Paused\n";
    static PausedState paused;
    player->setState(&paused);
}

void PausedState::play(MediaPlayer* player) {
    cout << "Playback Started\n";
    static PlayingState playing;
    player->setState(&playing);
}

// ----- Main -----
int main() {
    static PausedState paused;      // initial state
    MediaPlayer player(&paused);

    player.play();   // Paused → Playing
    player.pause();  // Playing → Paused
    player.pause();  // Already Paused

    return 0;
}
