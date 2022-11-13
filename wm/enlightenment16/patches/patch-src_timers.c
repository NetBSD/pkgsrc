$NetBSD: patch-src_timers.c,v 1.1 2022/11/13 00:52:01 gutteridge Exp $

Fix timer lockup issue.
Upstream commit 6a0c30e77ff598e90d38dd3c58f4552a996ab4b5.

--- src/timers.c.orig	2022-05-28 14:15:04.000000000 +0000
+++ src/timers.c
@@ -1,6 +1,6 @@
 /*
  * Copyright (C) 2000-2007 Carsten Haitzler, Geoff Harrison and various contributors
- * Copyright (C) 2006-2019 Kim Woelders
+ * Copyright (C) 2006-2022 Kim Woelders
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to
@@ -25,6 +25,13 @@
 #include "list.h"
 #include "timers.h"
 
+#define DEBUG_TIMERS 0
+#if DEBUG_TIMERS
+#define Dprintf(fmt...) if(EDebug(EDBUG_TYPE_TIMERS))Eprintf(fmt)
+#else
+#define Dprintf(fmt...)
+#endif
+
 struct _timer {
    unsigned int        in_time;
    unsigned int        at_time;
@@ -109,14 +116,19 @@ TimerAdd(int dt_ms, int (*func)(void *da
 void
 TimersRun(unsigned int t_ms)
 {
-   Timer              *timer, *q_old, *q_run;
+   Timer              *timer, *q_old, *q_new, *q_run;
 
    timer = q_first;
    if (!timer)
       return;			/* No timers pending */
 
-   q_run = q_old = timer;
-   for (; timer; timer = q_first)
+   Dprintf("%s - A\n", __func__);
+
+   q_new = timer;		/* q_new is now temporarily the timer queue */
+   q_old = timer;		/* q_old is the old timer queue */
+   q_first = NULL;		/* q_first holds timers added during timer processing */
+   q_run = NULL;		/* q_run holds the last run timer */
+   for (; timer; timer = q_new)
      {
 	if (tdiff(timer->at_time, t_ms) > 0)
 	   break;
@@ -125,22 +137,25 @@ TimersRun(unsigned int t_ms)
 	   Eprintf("%s - run %p: func=%p data=%p: %8d\n", __func__, timer,
 		   timer->func, timer->data, timer->at_time - t_ms);
 
-	q_first = timer->next;
+	q_new = timer->next;
 
 	/* Run this callback */
 	timer->again = timer->func(timer->data);
 	q_run = timer;
      }
 
-   if (q_old != q_first)
+   if (q_run)
      {
 	/* At least one timer has run */
 	q_run->next = NULL;	/* Terminate expired timer list */
 
 	/* Re-schedule/remove timers that have run */
-	for (timer = q_old; timer; timer = q_old)
+	q_run = q_new;		/* Swap q_first and q_new ... */
+	q_new = q_first;	/* q_new are the new added timers */
+	q_first = q_run;	/* q_first is now the timer queue */
+	for (timer = q_old; timer; timer = q_run)
 	  {
-	     q_old = timer->next;
+	     q_run = timer->next;
 	     if (timer->again)
 	       {
 		  timer->at_time += timer->in_time;
@@ -151,6 +166,17 @@ TimersRun(unsigned int t_ms)
 		  _TimerDel(timer);
 	       }
 	  }
+
+	/* Schedule timers that have been added */
+	for (timer = q_new; timer; timer = q_run)
+	  {
+	     q_run = timer->next;
+	     _TimerSet(timer);	/* Add to timer queue */
+	  }
+     }
+   else
+     {
+	q_first = q_old;	/* Restore timer queue */
      }
 
    if (EDebug(EDBUG_TYPE_TIMERS) > 1)
@@ -160,6 +186,8 @@ TimersRun(unsigned int t_ms)
 		   timer, timer->func, timer->data, timer->at_time - t_ms,
 		   timer->in_time);
      }
+
+   Dprintf("%s - B\n", __func__);
 }
 
 int
