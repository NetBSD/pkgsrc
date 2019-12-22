$NetBSD: patch-buffer_buffer.go,v 1.1 2019/12/22 10:38:16 bsiegert Exp $

--- buffer/buffer.go.orig	2018-11-06 02:48:29.000000000 +0000
+++ buffer/buffer.go
@@ -5,7 +5,7 @@ The `Reader` and `Writer` types implemen
 The `Lexer` type is useful for building lexers because it keeps track of the start and end position of a byte selection, and shifts the bytes whenever a valid token is found.
 The `StreamLexer` does the same, but keeps a buffer pool so that it reads a limited amount at a time, allowing to parse from streaming sources.
 */
-package buffer // import "github.com/tdewolff/parse/buffer"
+package buffer
 
 // defaultBufSize specifies the default initial length of internal buffers.
 var defaultBufSize = 4096
