$NetBSD: patch-config__make_system_wrappers.py,v 1.2 2019/12/03 14:21:20 ryoon Exp $

This is a workaround for building firefox with clang from base,
with a conflict with __isinf(__x) in libc++ vs netbsd headers.

--- config/make-system-wrappers.py.orig	2019-12-02 12:22:52.000000000 +0000
+++ config/make-system-wrappers.py
@@ -7,6 +7,7 @@ import os
 from mozbuild.util import FileAvoidWrite
 
 header_template = '''#pragma GCC system_header
+#define __isinf(x) __builtin_isinf(x)
 #pragma GCC visibility push(default)
 {includes}
 #pragma GCC visibility pop
