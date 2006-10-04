# $NetBSD: options.mk,v 1.2 2006/10/04 19:45:58 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libwww
PKG_OPTIONS_OPTIONAL_GROUPS+=	socks
PKG_OPTIONS_GROUP.socks=	socks4 socks5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msocks4)
CONFIGURE_ARGS+=	--with-socks4=${BUILDLINK_PREFIX.socks4}/lib/libsocks4.a
CONFIGURE_ARGS+=	--with-socks5=no
.include "../../net/socks4/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Msocks5)
CONFIGURE_ARGS+=	--with-socks4=no
CONFIGURE_ARGS+=	--with-socks5=${BUILDLINK_PREFIX.socks5}/lib/libsocks5.a
.include "../../net/socks5/buildlink3.mk"
.endif
