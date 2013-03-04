$NetBSD: patch-w3mhack.el,v 1.1 2013/03/04 19:12:23 hiramatsu Exp $

Compile mew-shimbun.el and mew-w3m.el when
emacs-w3m-mew option is set.

--- w3mhack.el.orig	2013-02-27 13:42:17.000000000 +0900
+++ w3mhack.el	2013-02-27 13:42:45.000000000 +0900
@@ -311,7 +311,7 @@
 				 2))
 			 (error nil))
 		     t)))
-	  (locate-library "mew"))
+	  (and (locate-library "mew") (getenv "EMACS-W3M-MEW")))
       (push "mew-w3m.el" ignores))
     (unless (if (featurep 'xemacs)
 		(and (featurep 'mule) (locate-library "pccl"))
