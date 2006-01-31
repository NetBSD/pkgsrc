# $NetBSD: options.mk,v 1.1 2006/01/31 04:15:29 epg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.neon
PKG_SUPPORTED_OPTIONS=	gssapi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
CONFIGURE_ARGS+=	--with-gssapi
.  include "../../mk/krb5.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gssapi
.endif
