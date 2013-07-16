$NetBSD: patch-private_posix__util.h,v 1.1 2013/07/16 10:12:48 joerg Exp $

--- private/posix_util.h.orig	2013-01-02 22:26:03.000000000 +0000
+++ private/posix_util.h
@@ -19,6 +19,20 @@
 #include <cppcms/cppcms_error.h>
 #include <booster/noncopyable.h>
 
+#ifdef __NetBSD__
+static int
+pthread_mutexattr_setpshared(pthread_mutexattr_t *, int)
+{
+	return -1;
+}
+
+static int
+pthread_rwlockattr_setpshared(pthread_rwlockattr_t *, int)
+{
+	return -1;
+}
+#endif
+
 namespace cppcms {
 namespace impl {
 
