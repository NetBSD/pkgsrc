$NetBSD: patch-PrefsModule_derived__src_NSFramework__PrefsModule.m,v 1.1 2013/03/23 12:22:15 joerg Exp $

--- PrefsModule/derived_src/NSFramework_PrefsModule.m.orig	2013-03-23 11:45:46.000000000 +0000
+++ PrefsModule/derived_src/NSFramework_PrefsModule.m
@@ -1,5 +1,5 @@
 #include <Foundation/NSString.h>
-@interface NSFramework_PrefsModule
+@interface NSFramework_PrefsModule : NSObject
 + (NSString *)frameworkEnv;
 + (NSString *)frameworkPath;
 + (NSString *)frameworkVersion;
