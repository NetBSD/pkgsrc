$NetBSD: patch-include_Motif-2.1_Xm_XmAll.h,v 1.1 2018/02/20 10:53:30 dholland Exp $

Don't include Xm/Print.h in Xm/XmAll.h, because it requires headers from
libXp that do not exist any longer.

For some reason leaving this in does not make the lesstif build fail;
it only causes failures for (some) users of lesstif.


--- include/Motif-2.1/Xm/XmAll.h~	2002-04-26 20:33:00.000000000 +0000
+++ include/Motif-2.1/Xm/XmAll.h
@@ -76,12 +76,12 @@
 #include <Xm/Manager.h>
 #include <Xm/Notebook.h>
 #include <Xm/Primitive.h>
-#include <Xm/Print.h>
+/*#include <Xm/Print.h>*/
 #include <Xm/SpinB.h>
 #include <Xm/Transfer.h>
 
 /* 2.1 stuff */
-#include <Xm/Print.h>
+/*#include <Xm/Print.h>*/
 #include <Xm/SSpinB.h>
 
 #endif /* _XM_XMALL_H */
