$NetBSD: patch-ipc_ipdl_ipdl_lower.py,v 1.3 2014/02/20 13:19:03 ryoon Exp $

--- ipc/ipdl/ipdl/lower.py.orig	2013-01-04 23:44:34.000000000 +0000
+++ ipc/ipdl/ipdl/lower.py
@@ -1797,7 +1797,7 @@ def _generateMessageClass(clsname, msgid
         StmtExpr(ExprCall(
             ExprVar('StringAppendF'),
             args=[ ExprAddrOf(msgvar),
-                   ExprLiteral.String('[time:%" PRId64 "][%d]'),
+                   ExprLiteral.String('[time:%\\" PRId64 \\"][%d]'),
                    ExprCall(ExprVar('PR_Now')),
                    ExprCall(ExprVar('base::GetCurrentProcId')) ])),
         appendToMsg(pfxvar),
