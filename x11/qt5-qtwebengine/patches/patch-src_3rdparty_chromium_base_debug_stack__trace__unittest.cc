$NetBSD: patch-src_3rdparty_chromium_base_debug_stack__trace__unittest.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/debug/stack_trace_unittest.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/debug/stack_trace_unittest.cc
@@ -86,6 +86,7 @@ TEST_F(StackTraceTest, OutputToStream) {
             std::string::npos)
       << "Unable to resolve symbols.";
 
+#if !defined(OS_BSD)
   // Expect a demangled symbol.
   // Note that Windows Release builds omit the function parameters from the
   // demangled stack output, otherwise this could be "testing::Test::Run()".
@@ -103,9 +104,10 @@ TEST_F(StackTraceTest, OutputToStream) {
   EXPECT_TRUE(backtrace_message.find(__func__) != std::string::npos)
       << "Expected to find " << __func__ << " in backtrace:\n"
       << backtrace_message;
+#endif
 }
 
-#if !defined(OFFICIAL_BUILD) && !defined(NO_UNWIND_TABLES)
+#if !defined(OFFICIAL_BUILD) && !defined(NO_UNWIND_TABLES) && !defined(OS_BSD)
 // Disabled in Official builds, where Link-Time Optimization can result in two
 // or fewer stack frames being available, causing the test to fail.
 TEST_F(StackTraceTest, TruncatedTrace) {
