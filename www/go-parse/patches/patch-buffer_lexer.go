$NetBSD: patch-buffer_lexer.go,v 1.1 2019/12/22 10:38:16 bsiegert Exp $

--- buffer/lexer.go.orig	2018-11-06 02:48:29.000000000 +0000
+++ buffer/lexer.go
@@ -1,4 +1,4 @@
-package buffer // import "github.com/tdewolff/parse/buffer"
+package buffer
 
 import (
 	"io"
