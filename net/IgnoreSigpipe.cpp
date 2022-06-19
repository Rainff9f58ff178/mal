//
// Created by rain on 2022/6/18.
//

#include "IgnoreSigpipe.h"
#include <signal.h>
mal::IgnoreSigpipe::IgnoreSigpipe() {
    ::signal(SIGPIPE,SIG_IGN);
}
