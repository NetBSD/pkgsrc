$NetBSD: patch-preserve.c,v 1.1 2021/02/20 14:37:23 bsiegert Exp $

memcpy with overlapping arguments is undefined behavior, use memmove.
See PR pkg/55809.

--- preserve.c.orig	2013-02-26 05:37:27.000000000 +0000
+++ preserve.c
@@ -109,7 +109,7 @@ void get_history()
                         yr = hist[i].year;
                         mth= hist[i].month+1;
                         if (mth>12) { mth=1; yr++; }
-                        memcpy(&hist[0], &hist[1], sizeof(hist[0])*i);
+                        memmove(&hist[0], &hist[1], sizeof(hist[0])*i);
                         memset(&hist[i], 0, sizeof(struct hist_rec));
                         hist[i].year=yr; hist[i].month=mth; n--;
                     }
@@ -277,7 +277,7 @@ void update_history()
                   yr = hist[i].year;
                   mth= hist[i].month+1;
                   if (mth>12) { mth=1; yr++; }
-                  memcpy(&hist[0],&hist[1],sizeof(hist[0])*i);
+                  memmove(&hist[0],&hist[1],sizeof(hist[0])*i);
                   memset(&hist[i], 0, sizeof(struct hist_rec));
                   hist[i].year=yr; hist[i].month=mth; n--;
                }
