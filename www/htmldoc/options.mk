# $NetBSD: options.mk,v 1.3 2009/07/03 14:04:12 drochner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.htmldoc
PKG_SUPPORTED_OPTIONS=		x11
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls ssl
PKG_SUGGESTED_OPTIONS=		ssl
PKG_OPTIONS_LEGACY_OPTS+=	htmldoc-gui:x11

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mssl) || !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--enable-ssl
.  if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openssl
CONFIGURE_ARGS+=	--with-openssl-libs=${SSLBASE:Q}/lib
CONFIGURE_ARGS+=	--with-openssl-includes=${SSLBASE:Q}/include
.  else
CONFIGURE_ARGS+=	--disable-openssl
.  endif
.  if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
CONFIGURE_ARGS+=	--enable-gnutls
.  else
CONFIGURE_ARGS+=	--disable-gnutls
.  endif
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

###
### X11 GUI support
###
.if !empty(PKG_OPTIONS:Mx11)
.  include "../../x11/fltk/buildlink3.mk"
.  include "../../x11/libXpm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gui --with-x
.else
CONFIGURE_ARGS+=	--without-gui --without-x
.endif
