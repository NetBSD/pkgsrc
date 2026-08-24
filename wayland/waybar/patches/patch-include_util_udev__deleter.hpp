$NetBSD: patch-include_util_udev__deleter.hpp,v 1.1 2026/08/24 14:25:32 kikadf Exp $

* Use udev only for linux

--- include/util/udev_deleter.hpp.orig	2026-05-24 09:05:13.454406135 +0000
+++ include/util/udev_deleter.hpp
@@ -1,5 +1,6 @@
 #pragma once
 
+#ifdef HAVE_LIBUDEV
 #include <libudev.h>
 
 namespace waybar::util {
@@ -18,4 +19,5 @@ struct UdevEnumerateDeleter {
 struct UdevMonitorDeleter {
   void operator()(udev_monitor* ptr) const { udev_monitor_unref(ptr); }
 };
-}  // namespace waybar::util
\ No newline at end of file
+}  // namespace waybar::util
+#endif // HAVE_LIBUDEV
