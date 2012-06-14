# $NetBSD: buildlink3.mk,v 1.11 2012/06/14 07:43:08 sbd Exp $

BUILDLINK_TREE+=	xscreensaver

.if !defined(XSCREENSAVER_BUILDLINK3_MK)
XSCREENSAVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xscreensaver+=	xscreensaver>=4.14
BUILDLINK_ABI_DEPENDS.xscreensaver+=	xscreensaver>=5.15nb1
BUILDLINK_PKGSRCDIR.xscreensaver?=	../../x11/xscreensaver

.include "../../textproc/libxml2/buildlink3.mk"
.endif # XSCREENSAVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xscreensaver
