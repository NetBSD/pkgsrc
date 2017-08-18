$NetBSD: patch-mozilla_dom_system_OSFileConstants.cpp,v 1.9 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/dom/system/OSFileConstants.cpp.orig	2017-07-07 05:36:18.000000000 +0000
+++ mozilla/dom/system/OSFileConstants.cpp
@@ -699,7 +699,7 @@ static const dom::ConstantSpec gLibcProp
 
   { "OSFILE_SIZEOF_STATVFS", JS::Int32Value(sizeof (struct statvfs)) },
 
-  { "OSFILE_OFFSETOF_STATVFS_F_BSIZE", JS::Int32Value(offsetof (struct statvfs, f_bsize)) },
+  { "OSFILE_OFFSETOF_STATVFS_F_FRSIZE", JS::Int32Value(offsetof (struct statvfs, f_frsize)) },
   { "OSFILE_OFFSETOF_STATVFS_F_BAVAIL", JS::Int32Value(offsetof (struct statvfs, f_bavail)) },
 
 #endif // defined(XP_UNIX)
