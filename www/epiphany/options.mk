# $NetBSD: options.mk,v 1.1 2006/09/24 16:28:20 salo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.epiphany

.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfirefox)
CPPFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/find
CFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/find
CPPFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/necko
CFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/necko
CPPFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/pref
CFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/pref
.else
BROKEN=		seamonkey backend is currently not supported
.endif
