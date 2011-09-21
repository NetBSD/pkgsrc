# $NetBSD: buildlink3.mk,v 1.4 2011/09/21 14:58:37 joerg Exp $

BUILDLINK_DEPMETHOD.xbitmaps?=	build

BUILDLINK_TREE+=	xbitmaps

.if !defined(XBITMAPS_BUILDLINK3_MK)
XBITMAPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xbitmaps+=	xbitmaps>=1.0
BUILDLINK_PKGSRCDIR.xbitmaps?=	../../x11/xbitmaps
.endif # XBITMAPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xbitmaps
