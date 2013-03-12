$NetBSD: patch-include_X11_extensions_XInput2.h,v 1.1 2013/03/12 11:39:49 wiz Exp $

gcc 4.6 won't complain about that, but earlier versions do:
http://gcc.gnu.org/git/?p=gcc.git;a=commitdiff;h=ce3765bf44e49ef0568a1ad4a0b7f807591d6412

gcc 4.6 with -pedantic-errors shows:
/opt/xorg/include/X11/extensions/XInput2.h:172:13: error: redefinition of
typedef ‘PointerBarrier’ [-pedantic]
In file included from test.c:1:0:
/opt/xorg/include/X11/extensions/Xfixes.h:255:13: note: previous declaration
of ‘PointerBarrier’ was here

PointerBarriers is defined in XFixes.h and here. So hook onto the only thing
we can in Xfixes.h and use that to figure out if we need to typedef
ourselves. XFIXES_MAJOR is defined in xfixeswire.h, so we can't hook onto it
directly.

Adding this ifdef here means we have include order dependency of XFixes.h
before XInput2.h unless we add a similar ifdef to the fixes headers.

Signed-off-by: Peter Hutterer <peter.hutterer@who-t.net>
---
Nasty, but can't think of a better way atm.

 include/X11/extensions/XInput2.h | 4 ++++
 1 file changed, 4 insertions(+)

--- include/X11/extensions/XInput2.h.orig	2013-02-19 01:08:17.000000000 +0000
+++ include/X11/extensions/XInput2.h
@@ -169,7 +169,11 @@ typedef struct
     int                 status;
 } XIGrabModifiers;
 
+/* Xfixes.h typedefs PointerBarrier and gcc pre-4.6 (or with -pedantic) will
+   complain about the duplicate typedef */
+#if !defined _XFIXES_H_ || XFIXES_MAJOR < 5
 typedef XID PointerBarrier;
+#endif
 typedef unsigned int BarrierEventID;
 
 typedef struct
