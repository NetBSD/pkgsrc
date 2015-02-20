$NetBSD: patch-wxc_src_treectrl.cpp,v 1.1 2015/02/20 23:39:31 joerg Exp $

--- wxc/src/treectrl.cpp.orig	2015-02-20 22:58:12.000000000 +0000
+++ wxc/src/treectrl.cpp
@@ -310,9 +310,9 @@ EWXWEXPORT(int, wxTreeCtrl_GetSelections
 			*(((wxTreeItemId**)selections)[i]) = sel[i];
             */
 	    #if wxCHECK_VERSION(2,5,0)
-            selections[i] = (int)(((wxTreeItemId*)sel[i])->m_pItem);
+            selections[i] = (int)(intptr_t)(((wxTreeItemId*)sel[i])->m_pItem);
             #else
-	    selections[i] = (int)(sel[i].m_pItem);
+	    selections[i] = (int)(intptr_t)(sel[i].m_pItem);
 	    #endif
 	  }
 	}
