$NetBSD: patch-w3mhack.el,v 1.3 2019/10/31 22:41:44 mef Exp $

CF-SX2# cd /tmp/www/emacs-w3m-snapshot/work/emacs-w3m-emacs-w3m-c9cdb7e/

CF-SX2# emacs -batch -f batch-byte-compile  mime-w3m.el
In toplevel form:
mime-w3m.el:37:1:Error: Cannot open load file: No such file or directory, mime-view
mime-w3m.el:38:1:Error: Cannot open load file: No such file or directory, w3m


--- emacs-w3m-emacs-w3m-c9cdb7e/w3mhack.el.orig	2019-09-20 20:16:36.000000000 +0900
+++ w3mhack.el	2019-10-30 21:16:09.444149861 +0900
@@ -256,6 +256,10@@ There seems to be no shell command which
 	(push (file-name-directory x) paths))
     (if (setq x (locate-library "gnus"))
 	(push (file-name-directory x) paths))
+    (if (setq x (locate-library "mime-view"))
+	(push (file-name-directory x) paths))
+    (if (setq x (locate-library "w3m"))
+	(push (file-name-directory x) paths))
     (let (print-level print-length)
       (princ (mapconcat
 	      (function directory-file-name)
