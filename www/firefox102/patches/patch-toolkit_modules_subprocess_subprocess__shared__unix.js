$NetBSD: patch-toolkit_modules_subprocess_subprocess__shared__unix.js,v 1.1 2022/07/21 23:56:39 nia Exp $

Fix broken native messaging on NetBSD and possibly other BSDs too:
https://bugzilla.mozilla.org/show_bug.cgi?id=1543602

Please remove this patch when the upstream issue is resolved.

--- toolkit/modules/subprocess/subprocess_shared_unix.js.orig	2022-05-20 10:44:23.277253777 +0000
+++ toolkit/modules/subprocess/subprocess_shared_unix.js
@@ -13,7 +13,15 @@
 
 var LIBC = OS.Constants.libc;
 
-const LIBC_CHOICES = ["libc.so", "libSystem.B.dylib", "a.out"];
+/* libc.so isn't meant to be dlopen'ed. On Linux it's usually an ld
+ * script so one cannot dlopen it. On NetBSD (and possibly other
+ * BSDs too) dlopen'ing libc.so will succeed, but some global symbols,
+ * especially environ(7), are pointing to unused memory regions
+ * because they are meant to be overridden by the main executable.
+ * So the most portable way to access libc symbols is to do it through
+ * the NULL handle, i.e. the one which NSPR calls "a.out".
+ */
+const LIBC_CHOICES = ["a.out"];
 
 const unix = {
   pid_t: ctypes.int32_t,
