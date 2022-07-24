$NetBSD: patch-vtemu_vt__parser.c,v 1.1 2022/07/24 08:56:54 rin Exp $

Fix TTIMEST without Ps argument; IM should be turned off in this case.

Cherry-picked from upstream commit 2c3d00d:
https://github.com/arakiken/mlterm/commit/2c3d00d530930c262322d4b1d431352cf68e2245

--- vtemu/vt_parser.c.orig
+++ vtemu/vt_parser.c
@@ -4900,8 +4900,10 @@ inline static int parse_vt100_escape_sequence(
 
           vt_parser->im_is_active = im_is_active(vt_parser);
         } else if (*str_p == 't') {
-          /* ps[0] = 0 (Close), ps[0] = 1 (Open) */
+          /* ps[0] = 0, -1 (Close), ps[0] = 1 (Open) */
 
+          if (ps[0] == -1)
+            ps[0] = 0;
           if (ps[0] != im_is_active(vt_parser)) {
             switch_im_mode(vt_parser);
           }
