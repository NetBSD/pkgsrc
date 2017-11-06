$NetBSD: patch-gtk_fallback-c89.c,v 1.3 2017/11/06 10:00:57 tnn Exp $

Work around the fact that math.h may declare these functions
non-static.
https://bugzilla.gnome.org/show_bug.cgi?id=757748                                                                                                         

--- gtk/fallback-c89.c.orig	2017-05-25 10:47:34.000000000 +0000
+++ gtk/fallback-c89.c
@@ -24,19 +24,20 @@
 /* Workaround for round() for non-GCC/non-C99 compilers */
 #ifndef HAVE_ROUND
 static inline double
-round (double x)
+my_round (double x)
 {
   if (x >= 0)
     return floor (x + 0.5);
   else
     return ceil (x - 0.5);
 }
+#define round(x)	my_round(x)
 #endif
 
 /* Workaround for rint() for non-GCC/non-C99 compilers */
 #ifndef HAVE_RINT
 static inline double
-rint (double x)
+my_rint (double x)
 {
   if (ceil (x + 0.5) == floor (x + 0.5))
   {
@@ -55,6 +56,7 @@ rint (double x)
       return ceil (x - 0.5);
   }
 }
+#define rint(x)		my_rint(x)
 #endif
 
 #ifndef HAVE_NEARBYINT
@@ -62,10 +64,11 @@ rint (double x)
 /* This is quite similar to rint() in most respects */
 
 static inline double
-nearbyint (double x)
+my_nearbyint (double x)
 {
   return floor (x + 0.5);
 }
+#define nearbyint(x)	my_nearbyint(x)
 #endif
 
 #ifndef HAVE_DECL_ISINF
