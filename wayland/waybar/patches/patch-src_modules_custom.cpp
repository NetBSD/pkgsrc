$NetBSD: patch-src_modules_custom.cpp,v 1.1 2026/08/24 14:25:32 kikadf Exp $

* Portable WEXITSTATUS usage

--- src/modules/custom.cpp.orig	2025-12-18 09:25:10.973327997 +0000
+++ src/modules/custom.cpp
@@ -81,7 +81,8 @@ void waybar::modules::Custom::continuous
     if (getline(&buff, &len, fp_) == -1) {
       int exit_code = 1;
       if (fp_) {
-        exit_code = WEXITSTATUS(util::command::close(fp_, pid_));
+        int status = util::command::close(fp_, pid_);
+        exit_code = WEXITSTATUS(status);
         fp_ = nullptr;
       }
       if (exit_code != 0) {
