$NetBSD: patch-w3m.el,v 1.2 2013/03/04 19:12:23 hiramatsu Exp $

Use an absolute path in invoking w3m.

--- w3m.el.orig	2013-02-25 15:15:04.000000000 +0900
+++ w3m.el	2013-02-25 15:16:14.000000000 +0900
@@ -259,13 +259,13 @@
 ;; Set w3m-command, w3m-type, w3m-version and w3m-compile-options
 (if noninteractive ;; Don't call the external command when compiling.
     (unless w3m-command
-      (setq w3m-command "w3m"))
+      (setq w3m-command "@W3M@"))
   (when (or (null w3m-command)
 	    (null w3m-type)
 	    (null w3m-version)
 	    (null w3m-compile-options))
     (let ((command (or w3m-command
-		       (w3m-which-command "w3m")
+		       (w3m-which-command "@W3M@")
 		       (w3m-which-command "w3mmee")
 		       (w3m-which-command "w3m-m17n"))))
       (when command
