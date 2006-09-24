# $NetBSD: options.mk,v 1.2 2006/09/24 16:26:54 salo Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.kazehakase
PKG_SUPPORTED_OPTIONS=	gnutls
PKG_SUGGESTED_OPTIONS+=	gnutls

.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

# Remove after upgrade to 0.3.4 or higher!
#
.if !empty(PKG_OPTIONS:Mseamonkey)
BROKEN=		seamonkey backend is currently not supported
.endif
