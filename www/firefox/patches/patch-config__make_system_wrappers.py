$NetBSD: patch-config__make_system_wrappers.py,v 1.3 2020/02/26 17:48:58 maya Exp $

This is a workaround for building firefox with clang from base,
with a conflict with __isinf(__x) in libc++ vs netbsd headers.

--- config/make-system-wrappers.py.orig	2019-12-02 12:22:52.000000000 +0000
+++ config/make-system-wrappers.py
@@ -7,6 +7,9 @@ import os
 from mozbuild.util import FileAvoidWrite
 
 header_template = '''#pragma GCC system_header
+#ifdef __NetBSD__
+#define __isinf(x) __builtin_isinf(x)
+#endif
 #pragma GCC visibility push(default)
 {includes}
 #pragma GCC visibility pop
