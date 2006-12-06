# $NetBSD: options.mk,v 1.2 2006/12/06 00:20:26 hubertf Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.elinks
PKG_SUPPORTED_OPTIONS+=	bittorrent nntp spidermonkey fsp finger gopher
PKG_SUPPORTED_OPTIONS+=	inet6 x11
PKG_OPTIONS_GROUP.tls=	gnutls ssl
PKG_OPTIONS_REQUIRED_GROUPS=	tls
PKG_SUGGESTED_OPTIONS=	ssl 

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+= --enable-ipv6
.else
CONFIGURE_ARGS+= --disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
.include "../../mk/x11.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mbittorrent)
CONFIGURE_ARGS+=	--enable-bittorrent
.else
CONFIGURE_ARGS+=	--disable-bittorrent
.endif

.if !empty(PKG_OPTIONS:Mnntp)
CONFIGURE_ARGS+=	--enable-nntp
.else
CONFIGURE_ARGS+=	--disable-nntp
.endif

.if !empty(PKG_OPTIONS:Mspidermonkey)
CONFIGURE_ARGS+=	--with-spidermonkey
CONFIGURE_ARGS+=	--enable-sm-scripting
.include "../../lang/spidermonkey/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-spidermonkey
CONFIGURE_ARGS+=	--disable-sm-scripting
.endif

.if !empty (PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-openssl
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--without-openssl
.elif !empty(PKG_OPTIONS:Mgnutls)				 
CONFIGURE_ARGS+= --with-gnutls-includes=${BUILDLINK_PREFIX.gnutls}/include
CONFIGURE_ARGS+= --with-gnutls-libs=${BUILDLINK_PREFIX.gnutls}/lib
CONFIGURE_ARGS+= --without-openssl
.include "../../security/gnutls/buildlink3.mk"
.endif							

.if !empty(PKG_OPTIONS:Mfsp)
CONFIGURE_ARGS+=	--enable-fsp
.else
CONFIGURE_ARGS+=	--disable-fsp
.endif

.if !empty(PKG_OPTIONS:Mfinger)
CONFIGURE_ARGS+=	--enable-finger
.else
CONFIGURE_ARGS+=	--disable-finger
.endif

.if !empty(PKG_OPTIONS:Mgopher)
CONFIGURE_ARGS+=	--enable-gopher
.else
CONFIGURE_ARGS+=	--disable-gopher
.endif

