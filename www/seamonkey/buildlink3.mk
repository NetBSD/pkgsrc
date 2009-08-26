# $NetBSD: buildlink3.mk,v 1.10 2009/08/26 19:56:39 sno Exp $

BUILDLINK_TREE+=	seamonkey

.if !defined(SEAMONKEY_BUILDLINK3_MK)
SEAMONKEY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.seamonkey+=	seamonkey>=1.0
BUILDLINK_ABI_DEPENDS.seamonkey?=	seamonkey>=1.1.17nb1
BUILDLINK_PKGSRCDIR.seamonkey?=		../../www/seamonkey

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # SEAMONKEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-seamonkey
