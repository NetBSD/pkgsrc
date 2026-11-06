$NetBSD: patch-src_modules_custom__graph.cpp,v 1.1 2026/11/06 19:45:10 kikadf Exp $

* Portable WEXITSTATUS usage

--- src/modules/custom_graph.cpp.orig	2026-11-06 17:28:36.656457582 +0000
+++ src/modules/custom_graph.cpp
@@ -75,7 +75,8 @@ void waybar::modules::CustomGraph::conti
       int exit_code = 1;
       if (fp_) {
         // fp_ is cleared first: the worker can be cancelled in close() after it closed the stream
-        exit_code = WEXITSTATUS(util::command::close(std::exchange(fp_, nullptr), pid_));
+        int status = util::command::close(std::exchange(fp_, nullptr), pid_);
+        exit_code = WEXITSTATUS(status);
         pid_ = -1;
       }
       if (exit_code != 0) {
