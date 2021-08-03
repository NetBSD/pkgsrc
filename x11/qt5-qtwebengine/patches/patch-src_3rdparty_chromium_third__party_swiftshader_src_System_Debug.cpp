$NetBSD: patch-src_3rdparty_chromium_third__party_swiftshader_src_System_Debug.cpp,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/swiftshader/src/System/Debug.cpp.orig	2020-07-15 19:01:40.000000000 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/src/System/Debug.cpp
@@ -18,13 +18,13 @@
 #	include <android/log.h>
 #endif
 
-#if defined(__unix__)
+#if defined(__unix__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #	define PTRACE
 #	include <sys/ptrace.h>
 #	include <sys/types.h>
 #elif defined(_WIN32) || defined(_WIN64)
 #	include <windows.h>
-#elif defined(__APPLE__) || defined(__MACH__)
+#elif defined(__APPLE__) || defined(__MACH__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #	include <sys/sysctl.h>
 #	include <unistd.h>
 #endif
@@ -46,7 +46,7 @@ namespace {
 
 bool IsUnderDebugger()
 {
-#if defined(PTRACE) && !defined(__APPLE__) && !defined(__MACH__)
+#if defined(PTRACE) && !defined(__APPLE__) && !defined(__MACH__) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
 	static bool checked = false;
 	static bool res = false;
 
@@ -91,6 +91,28 @@ bool IsUnderDebugger()
 
 	// We're being debugged if the P_TRACED flag is set
 	return ((info.kp_proc.p_flag & P_TRACED) != 0);
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+	int res = 0;
+	struct kinfo_proc2 info;
+	size_t length;
+
+	int request[6] = {
+		CTL_KERN,
+		KERN_PROC2,
+		KERN_PROC_PID,
+		getpid(),
+		sizeof(struct kinfo_proc2),
+		1,
+	};
+
+	if (sysctl(request, 6, NULL, &length, NULL, 0) < 0)
+		return -1;
+
+	request[5] = (length / sizeof(struct kinfo_proc2));
+	if (sysctl(request, 6, &info, &length, NULL, 0) < 0)
+		return -1;
+
+	return ((info.p_flag & P_TRACED) != 0);
 #else
 	return false;
 #endif
