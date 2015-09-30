# $NetBSD: options.mk,v 1.16 2015/09/30 08:25:37 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lynx
PKG_SUPPORTED_OPTIONS=	inet6

PKG_OPTIONS_OPTIONAL_GROUPS=	socksproxy
PKG_OPTIONS_GROUP.socksproxy=	dante socks4

PKG_OPTIONS_REQUIRED_GROUPS=	screen
PKG_OPTIONS_GROUP.screen=	ncurses ncursesw slang curses

PKG_SUGGESTED_OPTIONS=	curses inet6

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
SCREENTYPE=		slang
.  include "../../devel/libslang/buildlink3.mk"
post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/lynx.lss \
		${DESTDIR}${PREFIX}/share/examples/lynx/lynx.lss
.endif
.if !empty(PKG_OPTIONS:Mncurses)
SCREENTYPE=		ncurses
USE_NCURSES=		YES # color
.  include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-color-style
.endif
.if !empty(PKG_OPTIONS:Mncursesw)
SCREENTYPE=		ncursesw
LIBS+=			-lncursesw
BUILDLINK_ABI_DEPENDS.ncursesw+=	ncursesw>=5.9nb1
.  include "../../devel/ncursesw/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-color-style
.endif
.if !empty(PKG_OPTIONS:Mcurses)
SCREENTYPE=		curses
.  include "../../mk/curses.buildlink3.mk"
.  if !empty(MACHINE_PLATFORM:MNetBSD-1.[56]*-i386)
CONFIGURE_ARGS+=	--enable-color-style
.  endif
.endif

###
### SOCKS support
###
.if !empty(PKG_OPTIONS:Msocks4)
CONFIGURE_ARGS+=	--with-socks
.  include "../../net/socks4/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mdante)
CONFIGURE_ARGS+=	--with-socks
.  include "../../net/dante/buildlink3.mk"
.endif

###
### IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=       --enable-ipv6
.endif
