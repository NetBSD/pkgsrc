$NetBSD: patch-xwindow_fb_x__display__x68kgrf.c,v 1.6 2014/07/21 15:42:56 tsutsui Exp $

- pull post 3.3.7 fixes:
http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.3.7/mlterm-3.3.7-fixes.patch/download
 * x_display_x68kgrf.c:
  - Keyboard events from /dev/kbd are processed instead of stdin.
  - x68k_set_use_tvram_colors() and x68k_set_tvram_cmap() resets
    _display.color_cache.

--- xwindow/fb/x_display_x68kgrf.c.orig	2014-07-05 21:40:42.000000000 +0000
+++ xwindow/fb/x_display_x68kgrf.c
@@ -4,6 +4,8 @@
 
 #include  <dev/wscons/wsdisplay_usl_io.h>	/* VT_GETSTATE */
 #include  <machine/grfioctl.h>
+#include  <machine/vuid_event.h>
+#include  <dev/sun/kbio.h>
 
 
 #define get_key_state()  (0)
@@ -329,12 +331,32 @@ open_display(
 	tm.c_cc[VTIME] = 0 ;
 	tcsetattr( STDIN_FILENO , TCSAFLUSH , &tm) ;
 
-	_display.fd = STDIN_FILENO ;
-
 	kik_priv_restore_euid() ;
 	kik_priv_restore_egid() ;
 
-	_mouse.fd = open( "/dev/mouse" , O_RDWR|O_NONBLOCK|O_EXCL) ;
+	if( ( _display.fd = open( "/dev/kbd" , O_RDONLY)) >= 0)
+	{
+		int  mode ;
+
+		fcntl( _display.fd , F_SETOWN , getpid()) ;
+		fcntl( _display.fd , F_SETFL , O_NONBLOCK|O_ASYNC) ;
+		mode = 1 ;
+		ioctl( _display.fd , KIOCSDIRECT , &mode) ;
+	}
+	else
+	{
+		_display.fd = STDIN_FILENO ;
+	}
+
+	if( ( _mouse.fd = open( "/dev/mouse" , O_RDONLY)) >= 0)
+	{
+		int  format ;
+
+		format = VUID_FIRM_EVENT ;
+		ioctl( _mouse.fd , VUIDSFORMAT , &format) ;
+		fcntl( _mouse.fd , F_SETOWN , getpid()) ;
+		fcntl( _mouse.fd , F_SETFL , O_NONBLOCK|O_ASYNC) ;
+	}
 
 	kik_priv_change_euid( kik_getuid()) ;
 	kik_priv_change_egid( kik_getgid()) ;
@@ -400,13 +422,7 @@ receive_mouse_event(void)
 #define  VKEY_UP      0
 #define  VKEY_DOWN    1
 
-	struct
-	{
-		u_short  id ;
-		u_short  pad ;
-		int  value ;
-		struct timeval  time ;
-	} ev ;
+	Firm_event  ev ;
 	ssize_t  len ;
 
 	if( console_id != get_active_console())
@@ -544,7 +560,148 @@ receive_mouse_event(void)
 static int
 receive_key_event(void)
 {
-	return  receive_stdin_key_event() ;
+	static u_int16_t  keymap[] =
+	{
+		XK_Escape , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
+		'8' , '9' , '0' , '-' , '^' , '\\' , XK_BackSpace , XK_Tab ,
+		'q' , 'w' , 'e' , 'r' , 't' , 'y' , 'u' , 'i' ,
+		'o' , 'p' , '@' , '[' , XK_Return , 'a' , 's' , 'd' ,
+		'f' , 'g' , 'h' , 'j' , 'k' , 'l' , ';' , ':' ,
+		']' , 'z' , 'x' , 'c' , 'v' , 'b' , 'n' , 'm' ,
+		',' , '.' , '/' , 0 , ' ' , XK_Home , XK_Delete , XK_Prior ,
+		XK_Next , 0 /* XK_Undo */ , XK_Left , XK_Up , XK_Right , XK_Down ,
+			XK_Clear , XK_KP_Divide ,
+		XK_KP_Multiply , XK_KP_Subtract , XK_KP_7 , XK_KP_8 , XK_KP_9 , XK_KP_Add ,
+			XK_KP_4 , XK_KP_5 ,
+		XK_KP_6 , '=' /* XK_KP_Equal */ , XK_KP_1 , XK_KP_2 , XK_KP_3 ,
+			XK_Return /* XK_KP_Enter */ , XK_KP_0 , ',' ,
+		'.' , 0 , 0 /* XK_Touroku */ , XK_Help , XK_Alt_L , XK_Meta_L ,
+			XK_Meta_R , XK_Alt_R ,
+		XK_Control_R , 0 /* XK_Kana_Lock */ , 0 /* XK_Romaji */ , 0 , XK_Caps_Lock ,
+			XK_Insert , XK_Hiragana_Katakana , XK_Zenkaku_Hankaku ,
+		0 /* XK_Break */ , XK_Print , XK_F1 , XK_F2 , XK_F3 , XK_F4 , XK_F5 , XK_F6 ,
+		XK_F7 , XK_F8 , XK_F9 , XK_F10 , 0 , 0 , 0 , XK_Shift_L ,
+		XK_Control_L , XK_Super_L , XK_Super_R ,
+	} ;
+	static u_int8_t  shift_keymap[] =
+	{
+		0 , '!' , '\"' , '#' , '$' , '%' , '&' , '\'' ,
+		'(' , ')' , 0 , '=' , '~' , '|' , 0 , 0 ,
+		'Q' , 'W' , 'E' , 'R' , 'T' , 'Y' , 'U' , 'I' ,
+		'O' , 'P' , '`' , '{' , 0 , 'A' , 'S' , 'D' ,
+		'F' , 'G' , 'H' , 'J' , 'K' , 'L' , '+' , '*' ,
+		'}' , 'Z' , 'X' , 'C' , 'V' , 'B' , 'N' , 'M' ,
+		'<' , '>' , '?' , '_' ,
+	} ;
+	Firm_event  ev ;
+
+	if( _display.fd == STDIN_FILENO)
+	{
+		return  receive_stdin_key_event() ;
+	}
+
+	if( console_id != get_active_console())
+	{
+		return  0 ;
+	}
+
+	while( read( _display.fd , memset( &ev , 0 , sizeof(ev)) , sizeof(ev)) > 0)
+	{
+		XKeyEvent  xev ;
+		int  pressed ;
+		int  shift ;
+
+		pressed = (ev.value == VKEY_DOWN) ;
+
+		ev.id -- ;
+		ev.id &= 0x7f ;
+
+		if( _display.lock_state & CLKED)
+		{
+			shift = ! (_display.key_state & ShiftMask) ;
+		}
+		else
+		{
+			shift = _display.key_state & ShiftMask ;
+		}
+
+		if( ! shift ||
+		    ev.id >= sizeof(shift_keymap) / sizeof(*shift_keymap) ||
+		    ! ( xev.ksym = shift_keymap[ev.id]))
+		{
+			if( ev.id >= sizeof(keymap) / sizeof(*keymap) ||
+			    ! ( xev.ksym = keymap[ev.id]))
+			{
+				continue ;
+			}
+		}
+
+		if( pressed)
+		{
+			if( xev.ksym == XK_Shift_R ||
+			    xev.ksym == XK_Shift_L)
+			{
+				_display.key_state |= ShiftMask ;
+			}
+			else if( xev.ksym == XK_Control_R ||
+				 xev.ksym == XK_Control_L)
+			{
+				_display.key_state |= ControlMask ;
+			}
+			else if( xev.ksym == XK_Alt_R ||
+				 xev.ksym == XK_Alt_L ||
+				 xev.ksym == XK_Meta_R ||
+				 xev.ksym == XK_Meta_L)
+			{
+				_display.key_state |= ModMask ;
+			}
+			else if( xev.ksym == XK_Num_Lock)
+			{
+				_display.lock_state ^= NLKED ;
+			}
+			else if( xev.ksym == XK_Caps_Lock)
+			{
+				_display.lock_state ^= CLKED ;
+			}
+			else
+			{
+				xev.type = KeyPress ;
+				xev.state = _mouse.button_state |
+					    _display.key_state ;
+				xev.keycode = ev.id + 1 ;
+
+			#ifdef  __DEBUG
+				kik_debug_printf( KIK_DEBUG_TAG
+					"scancode %d -> ksym 0x%x state 0x%x\n" ,
+					ev.id , xev.ksym , xev.state) ;
+			#endif
+
+				receive_event_for_multi_roots( &xev) ;
+			}
+		}
+		else
+		{
+			if( xev.ksym == XK_Shift_R ||
+			    xev.ksym == XK_Shift_L)
+			{
+				_display.key_state &= ~ShiftMask ;
+			}
+			else if( xev.ksym == XK_Control_R ||
+				 xev.ksym == XK_Control_L)
+			{
+				_display.key_state &= ~ControlMask ;
+			}
+			else if( xev.ksym == XK_Alt_R ||
+				 xev.ksym == XK_Alt_L ||
+				 xev.ksym == XK_Meta_R ||
+				 xev.ksym == XK_Meta_L)
+			{
+				_display.key_state &= ~ModMask ;
+			}
+		}
+	}
+
+	return  1 ;
 }
 
 static int
@@ -590,6 +747,12 @@ x68k_set_use_tvram_colors(
 		if( _display.cmap == tcmap)
 		{
 			_display.cmap = gcmap ;
+
+			if( _display.color_cache)
+			{
+				memset( _display.color_cache , 0 ,
+					sizeof(*_display.color_cache)) ;
+			}
 		}
 
 		use_tvram_cmap = 0 ;
@@ -620,6 +783,12 @@ x68k_set_tvram_cmap(
 			gcmap = _display.cmap ;
 			_display.cmap = tcmap ;
 
+			if( _display.color_cache)
+			{
+				memset( _display.color_cache , 0 ,
+					sizeof(*_display.color_cache)) ;
+			}
+
 			return  1 ;
 		}
 	}
