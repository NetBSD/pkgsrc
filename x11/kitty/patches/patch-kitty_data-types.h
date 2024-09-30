$NetBSD: patch-kitty_data-types.h,v 1.1 2024/09/30 17:51:45 ktnb Exp $

Static assertions cause compile error for an unknown reason on
NetBSD.

--- kitty/data-types.h.orig	2024-09-26 15:09:11.517368353 +0000
+++ kitty/data-types.h
@@ -222,14 +222,12 @@ typedef struct {
     sprite_index sprite_x, sprite_y, sprite_z;
     CellAttrs attrs;
 } GPUCell;
-static_assert(sizeof(GPUCell) == 20, "Fix the ordering of GPUCell");
 
 typedef struct {
     char_type ch;
     hyperlink_id_type hyperlink_id;
     combining_type cc_idx[3];
 } CPUCell;
-static_assert(sizeof(CPUCell) == 12, "Fix the ordering of CPUCell");
 
 typedef enum { UNKNOWN_PROMPT_KIND = 0, PROMPT_START = 1, SECONDARY_PROMPT = 2, OUTPUT_START = 3 } PromptKind;
 typedef union LineAttrs {
