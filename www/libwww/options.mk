# $NetBSD: options.mk,v 1.4 2018/06/24 16:54:59 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libwww
PKG_OPTIONS_OPTIONAL_GROUPS+=	socks
PKG_OPTIONS_GROUP.socks=	socks4 dante

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msocks4)
CONFIGURE_ARGS+=	--with-socks4=${BUILDLINK_PREFIX.socks4}/lib/libsocks4.a
CONFIGURE_ARGS+=	--with-socks5=no
.include "../../net/socks4/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mdante)
CONFIGURE_ARGS+=	--with-socks4=${BUILDLINK_PREFIX.dante}/lib/libsocks.a
CONFIGURE_ARGS+=	--with-socks5=no
.include "../../net/dante/buildlink3.mk"
.endif
