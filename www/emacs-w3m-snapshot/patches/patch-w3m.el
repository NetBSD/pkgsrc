$NetBSD: patch-w3m.el,v 1.1 2011/11/30 21:05:13 minskim Exp $

--- w3m.el.orig	2010-05-19 05:12:47.000000000 +0000
+++ w3m.el
@@ -243,13 +243,13 @@ The valid values include `w3m', `w3mmee'
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
