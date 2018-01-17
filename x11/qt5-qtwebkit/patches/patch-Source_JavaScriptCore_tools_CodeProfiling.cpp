$NetBSD: patch-Source_JavaScriptCore_tools_CodeProfiling.cpp,v 1.4 2018/01/17 19:37:33 markd Exp $

* Add NetBSD support

--- Source/JavaScriptCore/tools/CodeProfiling.cpp.orig	2017-06-04 20:16:06.000000000 +0000
+++ Source/JavaScriptCore/tools/CodeProfiling.cpp
@@ -33,7 +33,7 @@
 #include <signal.h>
 #endif
 
-#if OS(LINUX) || OS(DARWIN)
+#if OS(LINUX) || OS(DARWIN) || OS(NETBSD)
 #include <sys/time.h>
 #endif
 
@@ -48,7 +48,7 @@ WTF::MetaAllocatorTracker* CodeProfiling
 #pragma clang diagnostic ignored "-Wmissing-noreturn"
 #endif
 
-#if (OS(DARWIN) && !PLATFORM(EFL) && !PLATFORM(GTK) && CPU(X86_64)) || (OS(LINUX) && CPU(X86))
+#if (OS(DARWIN) && !PLATFORM(EFL) && !PLATFORM(GTK) && CPU(X86_64)) || ((OS(LINUX) || OS(NETBSD)) && CPU(X86))
 // Helper function to start & stop the timer.
 // Presently we're using the wall-clock timer, since this seems to give the best results.
 static void setProfileTimer(unsigned usec)
@@ -80,6 +80,13 @@ static void profilingTimer(int, siginfo_
     CodeProfiling::sample(reinterpret_cast<void*>(context.gregs[REG_EIP]),
                           reinterpret_cast<void**>(context.gregs[REG_EBP]));
 }
+#elif OS(NETBSD) && CPU(X86)
+static void profilingTimer(int, siginfo_t*, void* uap)
+{
+    mcontext_t context = static_cast<ucontext_t*>(uap)->uc_mcontext;
+    CodeProfiling::sample(reinterpret_cast<void*>(context.__gregs[_REG_EIP]),
+                          reinterpret_cast<void**>(context.__gregs[_REG_EBP]));
+}
 #endif
 
 // Callback triggered when the timer is fired.
@@ -141,7 +148,7 @@ void CodeProfiling::begin(const SourceCo
     if (alreadyProfiling)
         return;
 
-#if (OS(DARWIN) && !PLATFORM(EFL) && !PLATFORM(GTK) && CPU(X86_64)) || (OS(LINUX) && CPU(X86))
+#if (OS(DARWIN) && !PLATFORM(EFL) && !PLATFORM(GTK) && CPU(X86_64)) || ((OS(LINUX) || OS(NETBSD)) && CPU(X86))
     // Regsiter a signal handler & itimer.
     struct sigaction action;
     action.sa_sigaction = reinterpret_cast<void (*)(int, siginfo_t *, void *)>(profilingTimer);
