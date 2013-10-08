$NetBSD: patch-dix_dixfonts.c,v 1.1 2013/10/08 20:33:54 wiz Exp $

Fix CVE-2013-4396.

From a4d9bf1259ad28f54b6d59a480b2009cc89ca623 Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Mon, 16 Sep 2013 21:47:16 -0700
Subject: [PATCH] Avoid use-after-free in dix/dixfonts.c: doImageText()

Save a pointer to the passed in closure structure before copying it
and overwriting the *c pointer to point to our copy instead of the
original.  If we hit an error, once we free(c), reset c to point to
the original structure before jumping to the cleanup code that
references *c.

Since one of the errors being checked for is whether the server was
able to malloc(c->nChars * itemSize), the client can potentially pass
a number of characters chosen to cause the malloc to fail and the
error path to be taken, resulting in the read from freed memory.

Since the memory is accessed almost immediately afterwards, and the
X server is mostly single threaded, the odds of the free memory having
invalid contents are low with most malloc implementations when not using
memory debugging features, but some allocators will definitely overwrite
the memory there, leading to a likely crash.

Reported-by: Pedro Ribeiro <pedrib@gmail.com>
Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Julien Cristau <jcristau@debian.org>
---
 dix/dixfonts.c |    5 +++++
 1 file changed, 5 insertions(+)

--- dix/dixfonts.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ dix/dixfonts.c
@@ -1414,6 +1414,7 @@ doImageText(ClientPtr client, ITclosureP
             GC *pGC;
             unsigned char *data;
             ITclosurePtr new_closure;
+            ITclosurePtr old_closure;
 
             /* We're putting the client to sleep.  We need to
                save some state.  Similar problem to that handled
@@ -1425,12 +1426,14 @@ doImageText(ClientPtr client, ITclosureP
                 err = BadAlloc;
                 goto bail;
             }
+            old_closure = c;
             *new_closure = *c;
             c = new_closure;
 
             data = malloc(c->nChars * itemSize);
             if (!data) {
                 free(c);
+                c = old_closure;
                 err = BadAlloc;
                 goto bail;
             }
@@ -1441,6 +1444,7 @@ doImageText(ClientPtr client, ITclosureP
             if (!pGC) {
                 free(c->data);
                 free(c);
+                c = old_closure;
                 err = BadAlloc;
                 goto bail;
             }
@@ -1453,6 +1457,7 @@ doImageText(ClientPtr client, ITclosureP
                 FreeScratchGC(pGC);
                 free(c->data);
                 free(c);
+                c = old_closure;
                 err = BadAlloc;
                 goto bail;
             }
