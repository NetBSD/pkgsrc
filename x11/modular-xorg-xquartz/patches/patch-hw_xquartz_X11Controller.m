$NetBSD: patch-hw_xquartz_X11Controller.m,v 1.1 2015/10/01 12:55:09 tnn Exp $

Clang says we must take the address of asl_log_descriptor. Do as it says.

--- hw/xquartz/X11Controller.m.orig	2014-04-18 21:33:02.000000000 +0000
+++ hw/xquartz/X11Controller.m
@@ -364,7 +364,7 @@ extern char *bundle_id_prefix;
     }
 
 #if MAC_OS_X_VERSION_MAX_ALLOWED >= 1080
-    if (asl_log_descriptor) {
+    if (&asl_log_descriptor) {
         char *asl_sender;
         aslmsg amsg = asl_new(ASL_TYPE_MSG);
         assert(amsg);
@@ -414,7 +414,7 @@ extern char *bundle_id_prefix;
 
         case 0:                                     /* child2 */
 #if MAC_OS_X_VERSION_MAX_ALLOWED >= 1080
-            if (asl_log_descriptor) {
+            if (&asl_log_descriptor) {
                 /* Replace our stdout/stderr */
                 dup2(stdout_pipe[1], STDOUT_FILENO);
                 dup2(stderr_pipe[1], STDERR_FILENO);
@@ -443,7 +443,7 @@ extern char *bundle_id_prefix;
     }
 
 #if MAC_OS_X_VERSION_MAX_ALLOWED >= 1080
-    if (asl_log_descriptor) {
+    if (&asl_log_descriptor) {
         /* Close the write ends of the pipe */
         close(stdout_pipe[1]);
         close(stderr_pipe[1]);
