$NetBSD: patch-examples_logging.h,v 1.1 2013/04/30 22:32:43 joerg Exp $

--- examples/logging.h.orig	2013-04-30 21:44:34.000000000 +0000
+++ examples/logging.h
@@ -24,7 +24,14 @@
 #ifndef __GTKMM_UTILS_LOGGING_EXAMPLE_H__
 #define __GTKMM_UTILS_LOGGING_EXAMPLE_H__
 
+#include <ciso646>
+#ifdef _LIBCPP_VERSION
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 #include <gtkmm.h>
 
 class Calculator;
@@ -61,7 +68,7 @@ protected:
     Gtk::Label label_result;
     Gtk::Entry entry_result;
 
-    std::tr1::shared_ptr<Calculator> calculator;
+    shared_ptr<Calculator> calculator;
 };
 
 #endif // __GTKMM_UTILS_LOGGING_EXAMPLE_H__
