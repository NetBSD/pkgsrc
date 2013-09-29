$NetBSD: patch-shibsp_SPConfig.cpp,v 1.1 2013/09/29 10:19:47 joerg Exp $

--- shibsp/SPConfig.cpp.orig	2013-09-29 08:49:36.000000000 +0000
+++ shibsp/SPConfig.cpp
@@ -446,7 +446,7 @@ bool SPConfig::instantiate(const char* c
         getServiceProvider()->init();
         return true;
     }
-    catch (exception& ex) {
+    catch (std::exception& ex) {
         if (rethrow)
             throw;
         Category::getInstance(SHIBSP_LOGCAT".Config").fatal("caught exception while loading configuration: %s", ex.what());
