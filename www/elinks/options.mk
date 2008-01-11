# $NetBSD: options.mk,v 1.7 2008/01/11 14:52:42 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.elinks
PKG_SUPPORTED_OPTIONS+=	bittorrent nntp spidermonkey finger gopher
PKG_SUPPORTED_OPTIONS+=	inet6 x11 elinks-fastmem elinks-exmode expat
PKG_SUPPORTED_OPTIONS+= elinks-html-highlight elinks-root-exec
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

BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

CONFIGURE_ARGS+=	--with-x
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

.include "../../lang/spidermonkey/buildlink3.mk"

CONFIGURE_ARGS+=	--with-spidermonkey
CONFIGURE_ARGS+=	--enable-sm-scripting
.else
CONFIGURE_ARGS+=	--without-spidermonkey
CONFIGURE_ARGS+=	--disable-sm-scripting
.endif

.if !empty(PKG_OPTIONS:Mssl)

.include "../../security/openssl/buildlink3.mk"

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

.elif !empty(PKG_OPTIONS:Mgnutls)

.include "../../security/gnutls/buildlink3.mk"

CONFIGURE_ARGS+= --with-gnutls-includes=${BUILDLINK_PREFIX.gnutls}/include
CONFIGURE_ARGS+= --with-gnutls-libs=${BUILDLINK_PREFIX.gnutls}/lib
CONFIGURE_ARGS+= --without-openssl
.endif

# Requires fsplib, which is not currently in pkgsrc.
#
#.if !empty(PKG_OPTIONS:Mfsp)
#CONFIGURE_ARGS+=	--enable-fsp
#.else
#CONFIGURE_ARGS+=	--disable-fsp
#.endif

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

.if !empty(PKG_OPTIONS:Mexpat)

.include "../../textproc/expat/buildlink3.mk"

CONFIGURE_ARGS+=	--enable-xbel
.else
CONFIGURE_ARGS+=	--disable-xbel
.endif

.if !empty(PKG_OPTIONS:Melinks-fastmem)
CONFIGURE_ARGS+=	--enable-fastmem
.else
CONFIGURE_ARGS+=	--disable-fastmem
.endif

.if !empty(PKG_OPTIONS:Melinks-html-highlight)
CONFIGURE_ARGS+=	--enable-html-highlight
.else
CONFIGURE_ARGS+=	--disable-html-hightlight
.endif

.if !empty(PKG_OPTIONS:Melinks-exmode)
CONFIGURE_ARGS+=	--enable-exmode
.else
CONFIGURE_ARGS+=	--disable-exmode
.endif

.if !empty(PKG_OPTIONS:Melinks-root-exec)
CONFIGURE_ARGS+=	--disable-no-root
.else
CONFIGURE_ARGS+=	--enable-no-root
.endif
