$NetBSD: patch-ipc_ipdl_ipdl_lower.py,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- ipc/ipdl/ipdl/lower.py.orig	2014-01-28 04:03:44.000000000 +0000
+++ ipc/ipdl/ipdl/lower.py
@@ -1811,7 +1811,7 @@ def _generateMessageClass(clsname, msgid
         StmtExpr(ExprCall(
             ExprVar('StringAppendF'),
             args=[ ExprAddrOf(msgvar),
-                   ExprLiteral.String('[time:%" PRId64 "][%d]'),
+                   ExprLiteral.String('[time:%\\" PRId64 \\"][%d]'),
                    ExprCall(ExprVar('PR_Now')),
                    ExprCall(ExprVar('base::GetCurrentProcId')) ])),
         appendToMsg(pfxvar),
