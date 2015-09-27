# $NetBSD: buildlink3.mk,v 1.5 2015/09/27 05:17:49 tnn Exp $

BUILDLINK_TREE+=	xf86driproto

.if !defined(XF86DRIPROTO_BUILDLINK3_MK)
XF86DRIPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.xf86driproto?=	build

BUILDLINK_API_DEPENDS.xf86driproto+=	xf86driproto>=2.0.3
BUILDLINK_PKGSRCDIR.xf86driproto?=	../../x11/xf86driproto

.endif # XF86DRIPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xf86driproto
