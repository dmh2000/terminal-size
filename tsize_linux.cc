#include <node.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "./tsize.h"

using namespace v8;

void terminalSize(const FunctionCallbackInfo<Value>& args) {
  struct winsize window;
  int status;

  Isolate* isolate = Isolate::GetCurrent();

  HandleScope handle_scope(isolate);

  Local<Array> array = Array::New(isolate, 2);

  status = ioctl(0,TIOCGWINSZ,&window);
  if (status == 0) {
    // Fill out the values
    array->Set(0, Integer::New(isolate, window.ws_row));
    array->Set(1, Integer::New(isolate, window.ws_col));
  }

  args.GetReturnValue().Set(array);
}
