$NetBSD: patch-src_cxx__supportlib_SystemTools_ProcessMetricsCollector.h,v 1.1 2019/01/06 09:52:50 markd Exp $

In !PS_SUPPORTS_MULTIPLE_PIDS case need "-ax" to get all processes and
when parsing the output need to skip to the beginning of next line on
all lines, not just those of the pids we care about.

--- src/cxx_supportlib/SystemTools/ProcessMetricsCollector.h.orig	2013-10-27 00:00:00.000000000 +0000
+++ src/cxx_supportlib/SystemTools/ProcessMetricsCollector.h
@@ -236,14 +236,14 @@ private:
 
 			if (pidAllowed) {
 				result[metrics.pid] = metrics;
+			}
 
-				start = strchr(start, '\n');
-				if (start != NULL) {
-					// Skip to beginning of next line.
-					start++;
-					if (*start == '\0') {
-						start = NULL;
-					}
+			start = strchr(start, '\n');
+			if (start != NULL) {
+				// Skip to beginning of next line.
+				start++;
+				if (*start == '\0') {
+					start = NULL;
 				}
 			}
 		}
@@ -313,10 +313,16 @@ public:
 			fmtArg.append("pid,ppid,%cpu,rss,vsize,pgid,uid,command");
 		#endif
 
+		#ifndef PS_SUPPORTS_MULTIPLE_PIDS
+		string allpidsArg = "-ax";
+		#endif
+
 		const char *command[] = {
 			"ps", fmtArg.c_str(),
 			#ifdef PS_SUPPORTS_MULTIPLE_PIDS
 				pidsArg.c_str(),
+			#else
+				allpidsArg.c_str(),
 			#endif
 			NULL
 		};
