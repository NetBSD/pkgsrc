$NetBSD: patch-shibsp_SPConfig.cpp,v 1.2 2015/10/23 07:35:08 pettai Exp $

--- shibsp/SPConfig.cpp.orig	2015-10-19 17:25:56.000000000 -0700
+++ shibsp/SPConfig.cpp	2015-10-19 17:26:43.000000000 -0700
@@ -447,7 +447,7 @@
         getServiceProvider()->init();
         return true;
     }
-    catch (exception& ex) {
+    catch (std::exception& ex) {
         if (rethrow)
             throw;
         Category::getInstance(SHIBSP_LOGCAT ".Config").fatal("caught exception while loading configuration: %s", ex.what());
