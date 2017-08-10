$NetBSD: patch-toolkit_xre_nsAppRunner.cpp,v 1.7 2017/08/10 14:46:15 ryoon Exp $

--- toolkit/xre/nsAppRunner.cpp.orig	2017-07-31 16:20:53.000000000 +0000
+++ toolkit/xre/nsAppRunner.cpp
@@ -227,11 +227,13 @@
 extern uint32_t gRestartMode;
 extern void InstallSignalHandlers(const char *ProgramName);
 
+#ifdef MOZ_RUST
 // This workaround is fixed in Rust 1.19. For details, see bug 1358151.
 // Implementation in toolkit/library/rust/shared/lib.rs
 extern "C" {
   void rust_init_please_remove_this_after_updating_rust_1_19();
 }
+#endif
 
 #define FILE_COMPATIBILITY_INFO NS_LITERAL_CSTRING("compatibility.ini")
 #define FILE_INVALIDATE_CACHES NS_LITERAL_CSTRING(".purgecaches")
@@ -3120,8 +3122,10 @@ XREMain::XRE_mainInit(bool* aExitFlag)
     return 1;
   *aExitFlag = false;
 
+#ifdef MOZ_RUST
   // This workaround is fixed in Rust 1.19. For details, see bug 1358151.
   rust_init_please_remove_this_after_updating_rust_1_19();
+#endif
 
   atexit(UnexpectedExit);
   auto expectedShutdown = mozilla::MakeScopeExit([&] {
