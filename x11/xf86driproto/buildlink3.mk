# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:53 joerg Exp $

BUILDLINK_DEPMETHOD.xf86driproto?=	build

BUILDLINK_TREE+=	xf86driproto

.if !defined(XF86DRIPROTO_BUILDLINK3_MK)
XF86DRIPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xf86driproto+=	xf86driproto>=2.0.3
BUILDLINK_PKGSRCDIR.xf86driproto?=	../../x11/xf86driproto

.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.endif # XF86DRIPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xf86driproto
