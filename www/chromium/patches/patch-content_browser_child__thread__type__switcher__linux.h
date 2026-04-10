$NetBSD: patch-content_browser_child__thread__type__switcher__linux.h,v 1.16 2026/04/10 17:31:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/child_thread_type_switcher_linux.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ content/browser/child_thread_type_switcher_linux.h
@@ -36,7 +36,7 @@ class ChildThreadTypeSwitcher : public m
   void SetPid(base::ProcessId child_pid);
 
   // mojom::ThreadTypeSwitcher:
-  void SetThreadType(int32_t ns_tid, base::ThreadType thread_type) override;
+  void SetThreadType(uint64_t ns_tid, base::ThreadType thread_type) override;
 
  private:
   base::ProcessId child_pid_ = base::kNullProcessHandle;
