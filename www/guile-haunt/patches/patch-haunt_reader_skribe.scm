$NetBSD: patch-haunt_reader_skribe.scm,v 1.1 2021/12/17 14:52:12 nikita Exp $

Patch recommendation for version 0.2.5, next release will be backwards
compatible again, by David Thompson (the developer of the software):
"Haunt 0.2.5 only works on Guile 3. Guile 3 generated some new
warnings and I fixed them, but it broke Guile 2 builds. You can patch
out the #:declarative? lines in haunt/ui.scm, haunt/reader/skribe.scm,
and haunt/reader.scm for now"

--- haunt/reader/skribe.scm.old	2021-12-17 15:21:01.200114859 +0100
+++ haunt/reader/skribe.scm	2021-12-17 15:21:56.121640403 +0100
@@ -23,7 +23,7 @@
 ;;; Code:
 
 (define-module (haunt reader skribe)
-  #:declarative? #f
+  ;;#:declarative? #f
   #:use-module (haunt reader)
   #:use-module (haunt skribe)
   #:use-module (haunt skribe utils)
