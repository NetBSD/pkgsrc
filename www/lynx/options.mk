# $NetBSD: options.mk,v 1.2 2004/08/22 19:32:52 jlam Exp $

.if defined(LYNX_SCREEN_LIB) && !empty(LYNX_SCREEN_LIB:Mslang)
PKG_DEFAULT_OPTIONS+=	slang
.endif
.if defined(LYNX_SCREEN_LIB) && !empty(LYNX_SCREEN_LIB:Mncurses)
PKG_DEFAULT_OPTIONS+=	ncurses
.endif
.if defined(LYNX_SCREEN_LIB) && !empty(LYNX_SCREEN_LIB:Mcurses)
PKG_DEFAULT_OPTIONS+=	curses
.endif
.if defined(USE_INET6) && !empty(USE_INET6:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	inet6
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.lynx
PKG_SUPPORTED_OPTIONS=	curses inet6 ncurses slang socks4 socks5
.include "../../mk/bsd.options.mk"

###
### We can't compile support for both the "slang" screen library and
### SOCKS support.
###
.if !empty(PKG_OPTIONS:Mslang) && !empty(PKG_OPTIONS:Msocks*)
PKG_FAIL_REASON+=	"SOCKS may not be enabled together with the \"slang\"" \
			"screen library.  If SOCKS support is desired," \
			"please change ${PKG_OPTIONS_VAR} to include" \
			"\"curses\" or \"ncurses\" instead."
.endif

###
### Set the screen library to "slang", "ncurses", or plain "curses".
###
.if !empty(PKG_OPTIONS:Mslang)
.  include "../../devel/libslang/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mncurses)
USE_NCURSES=		color
.  include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-color-style
.elif !empty(PKG_OPTIONS:Mcurses)
.  include "../../mk/curses.buildlink3.mk"
.  if !empty(MACHINE_PLATFORM:MNetBSD-1.[56]*-i386)
CONFIGURE_ARGS+=	--enable-color-style
.  endif
.else
PKG_FAIL_REASON+=	"${PKG_OPTIONS_VAR} must contain one of" \
			"one of \"slang\", \"ncurses\", or \"curses\"!"
.endif

###
### SOCKS support
###
.if !empty(PKG_OPTIONS:Msocks4)
CONFIGURE_ARGS+= 	--with-socks
.  include "../../net/socks4/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Msocks5)
CONFIGURE_ARGS+= 	--with-socks5
.  include "../../net/socks5/buildlink3.mk"
.endif

###
### IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=       --enable-ipv6
.endif
