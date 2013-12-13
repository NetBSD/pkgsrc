$NetBSD: patch-qtbase_src_corelib_io_qsettings.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add statvfs(2) support mainly for NetBSD

--- qtbase/src/corelib/io/qsettings.cpp.orig	2013-11-27 01:01:16.000000000 +0000
+++ qtbase/src/corelib/io/qsettings.cpp
@@ -144,9 +144,16 @@ QT_END_INCLUDE_NAMESPACE
 
 Q_AUTOTEST_EXPORT_HELPER bool qIsLikelyToBeNfs(int handle)
 {
+#ifdef QT_STATVFS
+    struct statvfs buf;
+    if (fstatvfs(handle, &buf) != 0)
+        return false;
+#else
     struct statfs buf;
     if (fstatfs(handle, &buf) != 0)
         return false;
+#endif
+
     return qt_isEvilFsTypeName(buf.f_fstypename);
 }
 
