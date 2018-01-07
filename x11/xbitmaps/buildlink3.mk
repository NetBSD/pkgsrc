# $NetBSD: buildlink3.mk,v 1.6 2018/01/07 13:04:43 rillig Exp $

BUILDLINK_TREE+=	xbitmaps

.if !defined(XBITMAPS_BUILDLINK3_MK)
XBITMAPS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.xbitmaps?=	build

BUILDLINK_API_DEPENDS.xbitmaps+=	xbitmaps>=1.0
BUILDLINK_PKGSRCDIR.xbitmaps?=		../../x11/xbitmaps
.endif # XBITMAPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xbitmaps
