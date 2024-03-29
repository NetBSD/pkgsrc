$NetBSD: patch-toolkit_modules_subprocess_subprocess__shared__unix.js,v 1.4 2023/09/05 14:08:39 ryoon Exp $

Fix broken native messaging on NetBSD and possibly other BSDs too:
https://bugzilla.mozilla.org/show_bug.cgi?id=1543602

Please remove this patch when the upstream issue is resolved.

--- toolkit/modules/subprocess/subprocess_shared_unix.js.orig	2023-08-17 21:21:43.000000000 +0000
+++ toolkit/modules/subprocess/subprocess_shared_unix.js
@@ -16,7 +16,15 @@
 
 var LIBC = ChromeUtils.getLibcConstants();
 
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
