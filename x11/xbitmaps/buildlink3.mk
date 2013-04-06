# $NetBSD: buildlink3.mk,v 1.5 2013/04/06 13:46:35 rodent Exp $

BUILDLINK_TREE+=	xbitmaps

.if !defined(XBITMAPS_BUILDLINK3_MK)
XBITMAPS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.xbitmaps?=	build

BUILDLINK_API_DEPENDS.xbitmaps+=	xbitmaps>=1.0
BUILDLINK_PKGSRCDIR.xbitmaps?=	../../x11/xbitmaps
.endif # XBITMAPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xbitmaps
