# $NetBSD: gecko-depends.mk,v 1.1 2006/09/24 16:21:33 salo Exp $

.if !empty(PKG_OPTIONS:Mfirefox)
# needs .pc files
BUILDLINK_API_DEPENDS.firefox+=		firefox>=1.5nb2
.include "../../www/firefox/buildlink3.mk"
.else
# needs .pc files
BUILDLINK_API_DEPENDS.seamonkey+=	seamonkey>=1.0.5nb1
.include "../../www/seamonkey/buildlink3.mk"
.endif
