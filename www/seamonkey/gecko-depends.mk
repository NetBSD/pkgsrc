# $NetBSD: gecko-depends.mk,v 1.2 2008/05/31 23:02:40 tnn Exp $

.if !empty(PKG_OPTIONS:Mfirefox)
# needs .pc files
BUILDLINK_API_DEPENDS.firefox+=		firefox>=1.5nb2
BUILDLINK_API_DEPENDS.firefox+=		firefox<=2.99
.include "../../www/firefox/buildlink3.mk"
.else
# needs .pc files
BUILDLINK_API_DEPENDS.seamonkey+=	seamonkey>=1.0.5nb1
.include "../../www/seamonkey/buildlink3.mk"
.endif
