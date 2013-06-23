$NetBSD: patch-xwindow_xlib_x__window.c,v 1.1 2013/06/23 06:02:39 tsutsui Exp $

Pull fix from http://mlterm.sf.net/mlterm-3.2.0-fixes.patch
> SF Bug #3614192

--- xwindow/xlib/x_window.c.orig	2013-05-26 02:13:13.000000000 +0000
+++ xwindow/xlib/x_window.c
@@ -3664,14 +3664,36 @@ x_window_set_icon(
 	/* set extended window manager hint's icon */
 	if( icon->cardinal && icon->cardinal[0] && icon->cardinal[1])
 	{
+		int  num ;
+		u_long *  data ;
+
+		/* width * height + 2 */
+		num = icon->cardinal[0] * icon->cardinal[1] + 2 ;
+
+		if( sizeof(u_long) != 4)
+		{
+			int  count ;
+
+			if( ! ( data = alloca( sizeof(u_long) * num)))
+			{
+				return  0 ;
+			}
+
+			for( count = 0 ; count < num ; count++)
+			{
+				data[count] = icon->cardinal[count] ;
+			}
+		}
+		else
+		{
+			data = icon->cardinal ;
+		}
+
 		/*it should be possible to set multiple icons...*/
 		XChangeProperty( root->disp->display, root->my_window,
 				 XA_NET_WM_ICON( root->disp->display),
 				 XA_CARDINAL, 32, PropModeReplace,
-				 (unsigned char *)(icon->cardinal),
-				 /* (cardinal[0])*(cardinal[1])
-				  *          = width * height */
-				 (icon->cardinal[0])*(icon->cardinal[1]) +2) ;
+				 data , num) ;
 	}
 
 	if( ( hints = XGetWMHints( root->disp->display , root->my_window)) == NULL &&
