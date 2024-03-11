$NetBSD: patch-hacks_glx_papercube.c,v 1.1 2024/03/11 10:58:45 jperkin Exp $

Avoid "sun" conflict.

--- hacks/glx/papercube.c.orig	2024-03-11 10:54:54.580908339 +0000
+++ hacks/glx/papercube.c
@@ -858,7 +858,7 @@ initialize_moves(struct moves *moves)
   double angle = 90.0;
   double fold = FOLD_DURATION / speed;
   double pause = PAUSE_DURATION / speed;
-  double sun = SUN_DURATION / speed;
+  double sol = SUN_DURATION / speed;
   double spin = SPIN_DURATION / speed;
   double spin_rps = SPIN_RPS;
   double time = 0;
@@ -866,7 +866,7 @@ initialize_moves(struct moves *moves)
   struct field_move *field_move;
   int i;
 
-  set_move(&moves->sunrise, time, sun, 0.0, brightness);
+  set_move(&moves->sunrise, time, sol, 0.0, brightness);
 
   time = moves->sunrise.stop + pause;
 
@@ -901,12 +901,12 @@ initialize_moves(struct moves *moves)
 
   time = field_move->move.stop + pause;
 
-  set_move(&moves->spin, time, time + spin + sun,
-           0.0, (spin + sun) * spin_rps * 360);
+  set_move(&moves->spin, time, time + spin + sol,
+           0.0, (spin + sol) * spin_rps * 360);
 
   time += spin;
 
-  set_move(&moves->sunset, time, time + sun, brightness, 0.0);
+  set_move(&moves->sunset, time, time + sol, brightness, 0.0);
 
   moves->stage = Sunrise;
   set_move_time_big_bang(&moves->move_time);
