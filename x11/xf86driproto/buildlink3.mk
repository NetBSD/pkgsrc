# $NetBSD: buildlink3.mk,v 1.4 2014/04/29 06:30:26 obache Exp $

BUILDLINK_TREE+=	xf86driproto

.if !defined(XF86DRIPROTO_BUILDLINK3_MK)
XF86DRIPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.xf86driproto?=	build

BUILDLINK_API_DEPENDS.xf86driproto+=	xf86driproto>=2.0.3
BUILDLINK_PKGSRCDIR.xf86driproto?=	../../x11/xf86driproto

BUILDLINK_DEPMETHOD.libpciaccess?=	build
.include "../../sysutils/libpciaccess/buildlink3.mk"
.endif # XF86DRIPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xf86driproto
