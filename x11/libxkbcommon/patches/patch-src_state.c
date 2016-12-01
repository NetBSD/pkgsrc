$NetBSD: patch-src_state.c,v 1.1 2016/12/01 20:54:52 wiedi Exp $

Fix conflict with NetBSD's popcount.
https://github.com/xkbcommon/libxkbcommon/issues/41

--- src/state.c.orig	2016-10-31 11:19:02.000000000 +0000
+++ src/state.c
@@ -1359,7 +1359,7 @@ key_get_consumed(struct xkb_state *state
             if (XkbLevelsSameSyms(level, no_mods_level))
                 continue;
 
-            if (entry == matching_entry || popcount(entry->mods.mask) == 1)
+            if (entry == matching_entry || popcountu(entry->mods.mask) == 1)
                 consumed |= entry->mods.mask & ~entry->preserve.mask;
         }
         break;
