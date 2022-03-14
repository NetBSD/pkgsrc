$NetBSD: patch-haunt_ui_serve.scm,v 1.1 2022/03/14 11:17:22 nikita Exp $

From upstream ab0b722b0719e3370a21359e4d511af9c4f14e60
and 1a91f3d0568fc095d8b0875c6553ef15b76efa4c by the upstream developer.
Do not compile or load inotify module when inotify is not available.

--- haunt/ui/serve.scm.orig	2022-03-14 12:07:00.344862709 +0100
+++ haunt/ui/serve.scm	2022-03-14 12:09:45.775494633 +0100
@@ -30,7 +30,6 @@
   #:use-module (ice-9 ftw)
   #:use-module (ice-9 threads)
   #:use-module (haunt config)
-  #:use-module (haunt inotify)
   #:use-module (haunt serve web-server)
   #:use-module (haunt site)
   #:use-module (haunt ui)
@@ -90,6 +89,21 @@
 
 ;; TODO: Detect new directories and watch them, too.
 (define (watch/linux config-file check-dir? check-file?)
+  ;; Lazy load inotify module.  Requiring the module in the
+  ;; define-module definition would cause crashes on non-Linux
+  ;; platforms where the FFI cannot bind to inotify functions.
+  (define inotify-module (resolve-module '(haunt inotify)))
+  (define make-inotify (module-ref inotify-module 'make-inotify))
+  (define inotify-add-watch! (module-ref inotify-module 'inotify-add-watch!))
+  (define inotify-pending-events?
+    (module-ref inotify-module 'inotify-pending-events?))
+  (define inotify-read-event (module-ref inotify-module 'inotify-read-event))
+  (define inotify-watch-file-name
+    (module-ref inotify-module 'inotify-watch-file-name))
+  (define inotify-event-watch (module-ref inotify-module 'inotify-event-watch))
+  (define inotify-event-file-name
+    (module-ref inotify-module 'inotify-event-file-name))
+  (define inotify-event-type (module-ref inotify-module 'inotify-event-type))
   (let ((inotify (make-inotify)))
     (define (no-op name stat result) result)
     (define (watch-directory name stat result)
