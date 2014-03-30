$NetBSD: mailnews_extensions_enigmail_ipc_modules_subprocess.jsm,v 1.2 2014/03/30 04:13:17 ryoon Exp $

--- mailnews/extensions/enigmail/ipc/modules/subprocess.jsm.orig	2014-01-12 13:08:29.000000000 +0000
+++ mailnews/extensions/enigmail/ipc/modules/subprocess.jsm
@@ -338,9 +338,11 @@ function getPlatformValue(valueType) {
         //            library name   O_NONBLOCK RLIM_T                RLIMIT_NOFILE
         'darwin':  [ 'libc.dylib',   0x04     , ctypes.uint64_t     , 8 ],
         'linux':   [ 'libc.so.6',    2024     , ctypes.unsigned_long, 7 ],
+        'dragonfly': [ 'libc.so',    0x04     , ctypes.int64_t      , 8 ],
         'freebsd': [ 'libc.so.7',    0x04     , ctypes.int64_t      , 8 ],
         'gnu/kfreebsd': [ 'libc.so.0.1', 0x04 , ctypes.int64_t      , 8 ],
         'openbsd': [ 'libc.so.61.0', 0x04     , ctypes.int64_t      , 8 ],
+        'netbsd': [ 'libc.so',    0x04     , ctypes.int64_t      , 8 ],
         'sunos':   [ 'libc.so',      0x80     , ctypes.unsigned_long, 5 ]
     };
 
