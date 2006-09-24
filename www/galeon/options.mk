# $NetBSD: options.mk,v 1.1 2006/09/24 16:30:09 salo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.galeon

.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfirefox)
CONFIGURE_ARGS+=	--with-mozilla=firefox
.else
BUILDLINK_RPATHDIRS.seamonkey+=	lib/seamonkey
.endif
