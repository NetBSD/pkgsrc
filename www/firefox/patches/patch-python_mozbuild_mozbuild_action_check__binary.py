$NetBSD: patch-python_mozbuild_mozbuild_action_check__binary.py,v 1.1 2018/11/12 12:50:52 jperkin Exp $

Skip linker order tests on SunOS.

--- python/mozbuild/mozbuild/action/check_binary.py.orig	2018-10-31 00:08:11.000000000 +0000
+++ python/mozbuild/mozbuild/action/check_binary.py
@@ -228,6 +228,9 @@ def check_nsmodules(target, binary):
     else:
         sym_cmp = lambda guessed, actual: guessed == actual
 
+    if sys.platform.startswith('sunos'):
+        return
+
     for addr, size, sym in symbols:
         if next_addr is not None and not sym_cmp(next_addr, addr):
             print_symbols(symbols)
