$NetBSD: patch-config__make_system_wrappers.py,v 1.1 2019/09/23 08:05:18 ng0 Exp $

This is a workaround for building firefox with clang from base,
with a conflict with __isinf(__x) in libc++ vs netbsd headers.

--- config/make-system-wrappers.py.orig 2019-01-24 18:48:39.000000000 +0000
+++ config/make-system-wrappers.py
@@ -6,6 +6,7 @@ import os
 from mozbuild.util import FileAvoidWrite

 header_template = '''#pragma GCC system_header
+#define __isinf(x) __builtin_isinf(x)
 #pragma GCC visibility push(default)
 {includes}
 #pragma GCC visibility pop
