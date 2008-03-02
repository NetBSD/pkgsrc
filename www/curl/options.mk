# $NetBSD: options.mk,v 1.2 2008/03/02 14:40:26 bjs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.curl
PKG_SUPPORTED_OPTIONS=	inet6 libssh2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mlibssh2)
CONFIGURE_ARGS+= 	--with-libssh2=${BUILDLINK_PREFIX.libssh2:Q}
.  include "../../security/libssh2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libssh2
.endif
