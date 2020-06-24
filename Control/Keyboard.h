#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <iostream>
#include <fcntl.h>
#include <pthread.h>
#include <linux/input.h>

#include <unistd.h>

/*
credits to Keith Lantz
https://www.keithlantz.net/2011/10/a-keyboard-handler-and-timer-in-c-for-the-linux-platform/
*/

#define KEYBOARD_DEV "/dev/input/event2"

struct keyboard_state {
	signed short keys[KEY_CNT];
};

class Keyboard_State {
  private:
	pthread_t thread;
	bool active;
	int keyboard_fd;
	input_event *keyboard_ev;
	keyboard_state *keyboard_st;
	char name[256];

  protected:
  public:
    Keyboard_State();
    ~Keyboard_State();
	static void* loop(void* obj);
	void readEv();
	short getKeyState(short key);
};

#endif
