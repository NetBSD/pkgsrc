$NetBSD: patch-mozilla-release_config__make_system_wrappers.py,v 1.1 2019/09/29 11:28:05 fox Exp $

This is a workaround for building firefox with clang from base,
with a conflict with __isinf(__x) in libc++ vs netbsd headers.

Original patch by ng0, imported from www/firefox

--- mozilla-release/config/make-system-wrappers.py.orig	2019-09-19 13:25:24.000000000 +0000
+++ mozilla-release/config/make-system-wrappers.py
@@ -6,6 +6,7 @@ import os
 from mozbuild.util import FileAvoidWrite
 
 header_template = '''#pragma GCC system_header
+#define __isinf(x) __builtin_isinf(x)
 #pragma GCC visibility push(default)
 {includes}
 #pragma GCC visibility pop
