# $NetBSD: buildlink3.mk,v 1.20 2023/04/19 08:09:00 adam Exp $

BUILDLINK_TREE+=	xscreensaver

.if !defined(XSCREENSAVER_BUILDLINK3_MK)
XSCREENSAVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xscreensaver+=	xscreensaver>=4.14
BUILDLINK_ABI_DEPENDS.xscreensaver+=	xscreensaver>=6.05.1nb4
BUILDLINK_PKGSRCDIR.xscreensaver?=	../../x11/xscreensaver

.include "../../textproc/libxml2/buildlink3.mk"
.endif # XSCREENSAVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xscreensaver
