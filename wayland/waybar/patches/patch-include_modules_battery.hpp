$NetBSD: patch-include_modules_battery.hpp,v 1.1 2026/08/24 14:25:32 kikadf Exp $

* Use udev only for linux

--- include/modules/battery.hpp.orig	2026-05-24 09:20:05.456525925 +0000
+++ include/modules/battery.hpp
@@ -40,9 +40,11 @@ class Battery : public ALabel {
   void processEvents(std::string& state, std::string& status, uint8_t capacity);
 
   std::map<fs::path, int> batteries_;
+#ifdef HAVE_LIBUDEV
   std::unique_ptr<udev, util::UdevDeleter> udev_;
   std::array<pollfd, 1> poll_fds_;
   std::unique_ptr<udev_monitor, util::UdevMonitorDeleter> mon_;
+#endif
   fs::path adapter_;
   int battery_watch_fd_;
   std::mutex battery_list_mutex_;
