$NetBSD: patch-eworkpanel_menu.h,v 1.1 2020/04/17 13:31:46 joerg Exp $

--- eworkpanel/menu.h.orig	2020-04-17 12:32:43.238786865 +0000
+++ eworkpanel/menu.h
@@ -22,7 +22,7 @@ static const char default_menu[] =
   <Item Type=\"Exec\" Icon=\"efinder.png\" Exec=\"efinder\">\n\
     <Name>Find</Name>\n\
   </Item>\n\
-  <Item Type=\"Exec\" Icon=\"ehelpbook.png\" Exec=\"file:"PREFIX"/share/ede/doc/index.html\">\n\
+  <Item Type=\"Exec\" Icon=\"ehelpbook.png\" Exec=\"file:" PREFIX "/share/ede/doc/index.html\">\n\
     <Name>Help</Name>\n\
   </Item>\n\
   <Item Type=\"Exec\" Icon=\"about.png\" Exec=\"$ABOUT\">\n\
