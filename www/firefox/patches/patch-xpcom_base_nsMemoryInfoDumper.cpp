$NetBSD: patch-xpcom_base_nsMemoryInfoDumper.cpp,v 1.1 2013/12/15 13:54:37 ryoon Exp $

--- xpcom/base/nsMemoryInfoDumper.cpp.orig	2013-12-05 16:08:00.000000000 +0000
+++ xpcom/base/nsMemoryInfoDumper.cpp
@@ -30,7 +30,7 @@
 #include <unistd.h>
 #endif
 
-#ifdef XP_LINUX
+#if defined(XP_LINUX) || defined(__FreeBSD__)
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -109,7 +109,7 @@ private:
 
 } // anonymous namespace
 
-#ifdef XP_LINUX // {
+#if defined(XP_LINUX) || defined(__FreeBSD__) // {
 namespace {
 
 /*
@@ -548,7 +548,7 @@ nsMemoryInfoDumper::~nsMemoryInfoDumper(
 /* static */ void
 nsMemoryInfoDumper::Initialize()
 {
-#ifdef XP_LINUX
+#if defined(XP_LINUX) || defined(__FreeBSD__)
   SignalPipeWatcher::Create();
   FifoWatcher::MaybeCreate();
 #endif
