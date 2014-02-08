$NetBSD: patch-xpcom_base_nsMemoryInfoDumper.cpp,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- xpcom/base/nsMemoryInfoDumper.cpp.orig	2014-01-28 04:04:07.000000000 +0000
+++ xpcom/base/nsMemoryInfoDumper.cpp
@@ -31,7 +31,7 @@
 #include <unistd.h>
 #endif
 
-#ifdef XP_LINUX
+#if defined(XP_LINUX) || defined(__FreeBSD__)
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -110,7 +110,7 @@ private:
 
 } // anonymous namespace
 
-#ifdef XP_LINUX // {
+#if defined(XP_LINUX) || defined(__FreeBSD__) // {
 namespace {
 
 /*
@@ -549,7 +549,7 @@ nsMemoryInfoDumper::~nsMemoryInfoDumper(
 /* static */ void
 nsMemoryInfoDumper::Initialize()
 {
-#ifdef XP_LINUX
+#if defined(XP_LINUX) || defined(__FreeBSD__)
   SignalPipeWatcher::Create();
   FifoWatcher::MaybeCreate();
 #endif
