# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:53 joerg Exp $

BUILDLINK_DEPMETHOD.xf86miscproto?=	build

BUILDLINK_TREE+=	xf86miscproto

.if !defined(XF86MISCPROTO_BUILDLINK3_MK)
XF86MISCPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xf86miscproto+=	xf86miscproto>=0.9.2
BUILDLINK_PKGSRCDIR.xf86miscproto?=	../../x11/xf86miscproto

.include "../../x11/xproto/buildlink3.mk"
.endif # XF86MISCPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xf86miscproto
