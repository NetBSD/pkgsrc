$NetBSD: patch-src_terminal_sixel.c,v 1.1 2025/02/07 16:18:14 pho Exp $

There is no such function as sixel_output_set_ormode() in libsixel. Where
did it come from?

--- src/terminal/sixel.c.orig	2025-02-07 13:19:29.650027658 +0000
+++ src/terminal/sixel.c
@@ -733,7 +733,6 @@ sixel_encoder_encode_frame(
     sixel_output_set_penetrate_multiplexer(
         output, encoder->penetrate_multiplexer);
     sixel_output_set_encode_policy(output, encoder->encode_policy);
-    sixel_output_set_ormode(output, encoder->ormode);
 
 #if 0
     if (sixel_frame_get_multiframe(frame) && !encoder->fstatic) {
