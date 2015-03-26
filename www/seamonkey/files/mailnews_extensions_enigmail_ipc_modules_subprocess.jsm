$NetBSD: mailnews_extensions_enigmail_ipc_modules_subprocess.jsm,v 1.3 2015/03/26 20:41:53 ryoon Exp $

--- mailnews/extensions/enigmail/ipc/modules/subprocess.jsm.orig	2015-03-23 16:38:43.000000000 +0000
+++ mailnews/extensions/enigmail/ipc/modules/subprocess.jsm
@@ -341,6 +341,7 @@ function getPlatformValue(valueType) {
         'freebsd': [ 'libc.so.7',    0x04     , ctypes.int64_t      , 8 ],
         'dragonfly':[ 'libc.so.8',   0x04,    , ctypes.int64_t      , 8 ],
         'gnu/kfreebsd': [ 'libc.so.0.1', 0x04 , ctypes.int64_t      , 8 ],
+        'netbsd':  [ 'libc.so',      0x04     , ctypes.int64_t      , 8 ],
         'openbsd': [ 'libc.so.61.0', 0x04     , ctypes.int64_t      , 8 ],
         'sunos':   [ 'libc.so',      0x80     , ctypes.unsigned_long, 5 ]
     };
