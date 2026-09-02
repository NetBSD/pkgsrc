$NetBSD: patch-base_debug_stack__trace.cc,v 1.25 2026/09/02 13:13:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/debug/stack_trace.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ base/debug/stack_trace.cc
@@ -294,7 +294,7 @@ bool StackTrace::WillSymbolizeToStreamFo
   // Symbols are not expected to be reliable when gn args specifies
   // symbol_level=0.
   return false;
-#elif defined(__UCLIBC__) || defined(_AIX)
+#elif defined(__UCLIBC__) || defined(_AIX) || BUILDFLAG(IS_BSD)
   // StackTrace::OutputToStream() is not implemented under uclibc, nor AIX.
   // See https://crbug.com/706728
   return false;
@@ -361,7 +361,9 @@ void StackTrace::OutputToStreamWithPrefi
     }
     return;
   }
+#if !BUILDFLAG(IS_BSD)
   OutputToStreamWithPrefixImpl(os, prefix_string);
+#endif
 }
 
 std::string StackTrace::ToString() const {
@@ -370,7 +372,7 @@ std::string StackTrace::ToString() const
 
 std::string StackTrace::ToStringWithPrefix(cstring_view prefix_string) const {
   std::stringstream stream;
-#if !defined(__UCLIBC__) && !defined(_AIX)
+#if !defined(__UCLIBC__) && !defined(_AIX) && !BUILDFLAG(IS_BSD)
   OutputToStreamWithPrefix(&stream, prefix_string);
 #endif
   return std::move(stream).str();
@@ -394,7 +396,7 @@ bool StackTrace::ShouldSuppressOutput() 
 }
 
 std::ostream& operator<<(std::ostream& os, const StackTrace& s) {
-#if !defined(__UCLIBC__) && !defined(_AIX)
+#if !defined(__UCLIBC__) && !defined(_AIX) && !BUILDFLAG(IS_BSD)
   s.OutputToStream(&os);
 #else
   os << "StackTrace::OutputToStream not implemented.";
