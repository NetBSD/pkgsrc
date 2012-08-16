$NetBSD: patch-psgml.el,v 1.1 2012/08/16 11:54:56 wiz Exp $

Fix build with emacs24. From FreeBSD ports.

--- psgml.el.orig	2005-03-05 16:23:40.000000000 +0000
+++ psgml.el
@@ -722,9 +722,9 @@ as that may change."
 
 (defun sgml-markup (entry text)
   (cons entry
-	(` (lambda ()
+	`(lambda ()
 	     (interactive)
-	     (sgml-insert-markup (, text))))))
+	     (sgml-insert-markup ,text))))
 
 (defun sgml-insert-markup (text)
   (let ((end (sgml-mouse-region))
@@ -1040,13 +1040,13 @@ as that may change."
 (defun sgml-compute-insert-dtd-items ()
   (loop for e in sgml-custom-dtd collect
         (vector (first e)
-                (` (sgml-doctype-insert (, (cadr e)) '(, (cddr e))))
+                `(sgml-doctype-insert ,(cadr e) ',(cddr e))
                 t)))
 
 (defun sgml-compute-custom-markup-items ()
   (loop for e in sgml-custom-markup collect
         (vector (first e)
-                (` (sgml-insert-markup  (, (cadr e))))
+                `(sgml-insert-markup  ,(cadr e))
                 t)))
 
 (defun sgml-build-custom-menus ()
@@ -1229,12 +1229,14 @@ All bindings:
     (make-local-variable 'text-property-default-nonsticky)
     ;; see `sgml-set-face-for':
     (add-to-list 'text-property-default-nonsticky '(face . t)))
-  (make-local-hook 'post-command-hook)
+  (if (fboundp 'make-local-hook)
+    (eval '(make-local-hook 'post-command-hook)))
   (add-hook 'post-command-hook 'sgml-command-post 'append 'local)
   (unless sgml-running-lucid
     ;; XEmacs 20.4 doesn't handle local activate-menubar-hook
     ;; it tries to call the function `t' when using the menubar
-    (make-local-hook 'activate-menubar-hook))
+    (if (fboundp 'make-local-hook)
+      (eval '(make-local-hook 'activate-menubar-hook))))
   (add-hook 'activate-menubar-hook 'sgml-update-all-options-menus
 	    nil 'local)
   (run-hooks 'text-mode-hook 'sgml-mode-hook)
