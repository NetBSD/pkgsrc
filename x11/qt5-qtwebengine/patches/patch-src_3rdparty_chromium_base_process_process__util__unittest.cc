$NetBSD: patch-src_3rdparty_chromium_base_process_process__util__unittest.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/process/process_util_unittest.cc.orig	2020-07-08 21:41:45.000000000 +0000
+++ src/3rdparty/chromium/base/process/process_util_unittest.cc
@@ -1307,7 +1307,7 @@ std::string TestLaunchProcess(const Comm
   options.fds_to_remap.emplace_back(fds[1], STDOUT_FILENO);
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   options.clone_flags = clone_flags;
 #else
   CHECK_EQ(0, clone_flags);
@@ -1377,7 +1377,7 @@ TEST_F(ProcessUtilTest, LaunchProcess) {
   EXPECT_EQ("wibble", TestLaunchProcess(kPrintEnvCommand, env_changes,
                                         no_clear_environ, no_clone_flags));
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Test a non-trival value for clone_flags.
   EXPECT_EQ("wibble", TestLaunchProcess(kPrintEnvCommand, env_changes,
                                         no_clear_environ, CLONE_FS));
@@ -1391,7 +1391,7 @@ TEST_F(ProcessUtilTest, LaunchProcess) {
                                   true /* clear_environ */, no_clone_flags));
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 MULTIPROCESS_TEST_MAIN(CheckPidProcess) {
   const pid_t kInitPid = 1;
   const pid_t pid = syscall(__NR_getpid);
