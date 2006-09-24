# $NetBSD: options.mk,v 1.1 2006/09/24 16:28:49 salo Exp $

# this should use the same gecko option as epiphany
PKG_OPTIONS_VAR=	PKG_OPTIONS.epiphany

.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfirefox)
CPPFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/dom
CPPFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/pref
CPPFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/webbrwsr
.else
BROKEN=		seamonkey backend is currently not supported
.endif
