$NetBSD: patch-src_modules_simpleclock.cpp,v 1.1 2026/08/24 14:25:32 kikadf Exp $

* fmt::localtime was removed in fmtlib-12

--- src/modules/simpleclock.cpp.orig	2025-12-18 09:42:22.535423519 +0000
+++ src/modules/simpleclock.cpp
@@ -17,7 +17,9 @@ waybar::modules::Clock::Clock(const std:
 auto waybar::modules::Clock::update() -> void {
   tzset();  // Update timezone information
   auto now = std::chrono::system_clock::now();
-  auto localtime = fmt::localtime(std::chrono::system_clock::to_time_t(now));
+  auto t = std::chrono::system_clock::to_time_t(now);
+  std::tm localtime{};
+  localtime_r(&t, &localtime);
   auto text = fmt::format(fmt::runtime(format_), localtime);
   label_.set_markup(text);
 
