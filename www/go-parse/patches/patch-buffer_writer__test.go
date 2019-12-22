$NetBSD: patch-buffer_writer__test.go,v 1.1 2019/12/22 10:38:16 bsiegert Exp $

--- buffer/writer_test.go.orig	2018-11-06 02:48:29.000000000 +0000
+++ buffer/writer_test.go
@@ -1,4 +1,4 @@
-package buffer // import "github.com/tdewolff/parse/buffer"
+package buffer
 
 import (
 	"fmt"
