#include <Windows.h>
#include <node.h>
#include "./tsize.h"

using namespace v8;

void terminalSize(const FunctionCallbackInfo<Value>& args) {
  	Isolate* isolate = Isolate::GetCurrent();

  	HandleScope handle_scope(isolate);

	  Local<Array> array = Array::New(isolate, 2);

    array->Set(0, Integer::New(isolate, 0));
    array->Set(1, Integer::New(isolate, 0));
    
    BOOL b;
    HANDLE sb;
    CONSOLE_SCREEN_BUFFER_INFO info;
    SHORT w;
    SHORT h;
    
    sb = CreateFile("CONOUT$",GENERIC_READ,FILE_SHARE_WRITE,0,OPEN_EXISTING,0,0);
    if (sb == INVALID_HANDLE_VALUE) {
    	args.GetReturnValue().Set(array);
    	return;
	}
	
	b = GetConsoleScreenBufferInfo(sb,&info);
	if(b == 0) {
    	args.GetReturnValue().Set(array);
    	return;
	}
	
	// populate the array and return
	h = (info.srWindow.Bottom - info.srWindow.Top) + 1;
	w = (info.srWindow.Right - info.srWindow.Left) + 1;
    array->Set(0, Integer::New(isolate, h));
    array->Set(1, Integer::New(isolate, w));

    args.GetReturnValue().Set(array);
}

