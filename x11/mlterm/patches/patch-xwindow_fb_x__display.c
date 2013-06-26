$NetBSD: patch-xwindow_fb_x__display.c,v 1.2 2013/06/26 11:29:47 tsutsui Exp $

Pull fix from http://mlterm.sf.net/mlterm-3.2.0-fixes.patch
> Fix the bug which caused segmentation fault in closing input method
> status window.

Pull update for ibus on mlterm-fb from rev c881417
 https://bitbucket.org/arakiken/mlterm/commits/c8814173cb051b32ce1d1b440b4033bd0bba567d#chg-xwindow/fb/x_display.c
> fb/x_display.c: get_ps2_kcode() is added to convert usb keycode
> to ps2 keycode for iBus on NetBSD/OpenBSD framebuffer.

--- xwindow/fb/x_display.c.orig	2013-05-26 02:13:13.000000000 +0000
+++ xwindow/fb/x_display.c
@@ -169,6 +169,7 @@ static x_display_t *  opened_disps[] = {
 #if  defined(__FreeBSD__)
 static keymap_t  keymap ;
 #elif  defined(__NetBSD__)
+static u_int  kbd_type ;
 static struct wskbd_map_data  keymap ;
 static int  console_id = -1 ;
 static int  orig_console_mode = WSDISPLAYIO_MODE_EMUL ;	/* 0 */
@@ -1589,6 +1590,149 @@ receive_key_event(void)
 
 #elif  defined(__NetBSD__)
 
+/* For iBus */
+static u_int
+get_ps2_kcode(
+	u_int  kcode
+	)
+{
+	if( kbd_type == WSKBD_TYPE_USB)
+	{
+		static u_char  map_table1[] =
+		{
+			30 ,	/* A (4) */
+			48 ,	/* B */
+			46 ,	/* C */
+			32 ,	/* D */
+			18 ,	/* E */
+			33 ,	/* F */
+			34 ,	/* G (10) */
+			35 ,	/* H */
+			23 ,	/* I */
+			36 ,	/* J */
+			37 ,	/* K */
+			38 ,	/* L */
+			50 ,	/* M */
+			49 ,	/* N */
+			24 ,	/* O */
+			25 ,	/* P */
+			16 ,	/* Q (20) */
+			19 ,	/* R */
+			31 ,	/* S */
+			20 ,	/* T */
+			22 ,	/* U */
+			47 ,	/* V */
+			17 ,	/* W */
+			45 ,	/* X */
+			21 ,	/* Y */
+			44 ,	/* Z */
+			 2 ,	/* 1 (30) */
+			 3 ,	/* 2 */
+			 4 ,	/* 3 */
+			 5 ,	/* 4 */
+			 6 ,	/* 5 */
+			 7 ,	/* 6 */
+			 8 ,	/* 7 */
+			 9 ,	/* 8 */
+			10 ,	/* 9 */
+			11 ,	/* 0 */
+			28 ,	/* Enter (40) */
+			 1 ,	/* ESC */
+			14 ,	/* BackSpace */
+			15 ,	/* Tab */
+			57 ,	/* Space */
+			12 ,	/* _ - */
+			13 ,	/* + = */
+			26 ,	/* { [ */
+			27 ,	/* } ] */
+			43 ,	/* \ | */
+			 0 ,	/* (50) */
+			39 ,	/* : ; */
+			40 ,	/* " ' */
+			41 ,	/* ~ ` */
+			51 ,	/* < , */
+			52 ,	/* > . */
+			53 ,	/* ? / */
+			58 ,	/* CapsLock */
+			59 ,	/* F1 */
+			60 ,	/* F2 */
+			61 ,	/* F3 (60) */
+			62 ,	/* F4 */
+			63 ,	/* F5 */
+			64 ,	/* F6 */
+			65 ,	/* F7 */
+			66 ,	/* F8 */
+			67 ,	/* F9 */
+			68 ,	/* F10 */
+			87 ,	/* F11 */
+			88 ,	/* F12 */
+			 0 ,	/* Print Screen (70) */
+			70 ,	/* ScreenLock */
+			 0 ,	/* Pause */
+			110 ,	/* Insert */
+			102 ,	/* Home */
+			104 ,	/* Page Up */
+			111 ,	/* Delete */
+			107 ,	/* End */
+			109 ,	/* Page Down */
+			106 ,	/* Right */
+			105 ,	/* Left (80) */
+			108 ,	/* Down */
+			103 ,	/* Up */
+			69 ,	/* NumLock */
+			 0 ,	/* Num / */
+			55 ,	/* Num * */
+			74 ,	/* Num - */
+			78 ,	/* Num + */
+			 0 ,	/* Num Enter */
+			79 ,	/* Num 1 */
+			80 ,	/* Num 2 (90) */
+			81 ,	/* Num 3 */
+			75 ,	/* Num 4 */
+			76 ,	/* Num 5 */
+			77 ,	/* Num 6 */
+			71 ,	/* Num 7 */
+			72 ,	/* Num 8 */
+			73 ,	/* Num 9 */
+			82 ,	/* Num 0 */
+			83 ,	/* Num . */
+		} ;
+
+		static u_char  map_table2[] =
+		{
+			29 ,	/* Control L (224) */
+			42 ,	/* Shift L */
+			56 ,	/* Alt L */
+			 0 ,	/* Windows L */
+			97 ,	/* Control R */
+			54 ,	/* Shift R */
+			100 ,	/* Alt R (230) */
+			 0 ,	/* Windows R */
+		} ;
+
+		if( 4 <= kcode)
+		{
+			if( kcode <= 99)
+			{
+				return  map_table1[kcode - 4] ;
+			}
+			else if( 224 <= kcode)
+			{
+				if( kcode <= 231)
+				{
+					return  map_table2[kcode - 224] ;
+				}
+			}
+		}
+
+		return  0 ;
+	}
+	else
+	{
+		return  kcode ;
+	}
+}
+
 static void
 process_wskbd_event(
 	struct wscons_event *  ev
@@ -1656,7 +1800,7 @@ process_wskbd_event(
 			xev.ksym = ksym ;
 			xev.state = _mouse.button_state |
 				    _display.key_state ;
-			xev.keycode = ev->value ;
+			xev.keycode = get_ps2_kcode( ev->value) ;
 
 			receive_event_for_multi_roots( &xev) ;
 
@@ -1884,6 +2028,8 @@ open_display(void)
 		ioctl( _display.fd , WSKBDIO_SETVERSION , &mode) ;
 	#endif
 
+		ioctl( _display.fd , WSKBDIO_GTYPE , &kbd_type) ;
+
 		keymap.maplen = KS_NUMKEYCODES ;
 		keymap.map = map ;
 		ioctl( _display.fd , WSKBDIO_GETMAP , &keymap) ;
