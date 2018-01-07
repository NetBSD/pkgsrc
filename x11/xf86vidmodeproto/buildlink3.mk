# $NetBSD: buildlink3.mk,v 1.5 2018/01/07 13:04:43 rillig Exp $

BUILDLINK_TREE+=	xf86vidmodeproto

.if !defined(XF86VIDMODEPROTO_BUILDLINK3_MK)
XF86VIDMODEPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.xf86vidmodeproto?=	build

BUILDLINK_API_DEPENDS.xf86vidmodeproto+=	xf86vidmodeproto>=2.3
BUILDLINK_PKGSRCDIR.xf86vidmodeproto?=		../../x11/xf86vidmodeproto

.include "../../x11/xproto/buildlink3.mk"
.endif # XF86VIDMODEPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xf86vidmodeproto
