# $NetBSD: options.mk,v 1.20 2022/07/23 14:41:52 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lynx
PKG_SUPPORTED_OPTIONS=	inet6

PKG_OPTIONS_OPTIONAL_GROUPS+=	socksproxy
PKG_OPTIONS_GROUP.socksproxy=	dante socks4

PKG_OPTIONS_OPTIONAL_GROUPS+=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls openssl

PKG_OPTIONS_REQUIRED_GROUPS+=	screen
PKG_OPTIONS_GROUP.screen=	curses wide-curses slang
PKG_OPTIONS_LEGACY_OPTS+=	ncurses:curses ncursesw:wide-curses

PKG_SUGGESTED_OPTIONS=		inet6 openssl wide-curses

.include "../../mk/bsd.options.mk"

###
### We can't compile support for both the "slang" screen library and
### SOCKS support.
###
.if !empty(PKG_OPTIONS:Mslang) && ${PKG_OPTIONS:Msocks*}
PKG_FAIL_REASON+=	"SOCKS may not be enabled together with the \"slang\"" \
			"screen library.  If SOCKS support is desired," \
			"please change ${PKG_OPTIONS_VAR} to include" \
			"\"curses\" instead."
.endif

###
### Set the screen library to "curses". "wide-curses" or "slang"
###
.if !empty(PKG_OPTIONS:Mcurses) || !empty(PKG_OPTIONS:Mwide-curses)
CONFIGURE_ARGS+=	--enable-color-style
SCREENTYPE=		${CURSES_TYPE}
.  include "../../mk/curses.buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mslang)
SCREENTYPE=		slang
.  include "../../devel/libslang/buildlink3.mk"
post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/lynx.lss \
		${DESTDIR}${PREFIX}/share/examples/lynx/lynx.lss
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
CONFIGURE_ARGS+=	--enable-ipv6
.endif


###
### TLS support
###
.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--with-gnutls=${BUILDLINK_PREFIX.gnutls}
.  include "../../security/gnutls/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
