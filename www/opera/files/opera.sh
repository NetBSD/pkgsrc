#! /bin/sh

OPERA_DIR=@PREFIX@/share/opera
export OPERA_DIR
LD_LIBRARY_PATH=/usr/openwin/lib
export LD_LIBRARY_PATH
exec @PREFIX@/libexec/opera
