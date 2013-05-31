# $NetBSD: buildlink3.mk,v 1.1 2013/05/31 00:27:37 rodent Exp $

BUILDLINK_TREE+=	windowswmproto

.if !defined(WINDOWSWMPROTO_BUILDLINK3_MK)
WINDOWSWMPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.windowswmproto?=	build

BUILDLINK_API_DEPENDS.windowswmproto+=	windowswmproto>=1.0.4
BUILDLINK_PKGSRCDIR.windowswmproto?=	../../wm/windowswmproto

.include "../../x11/xproto/buildlink3.mk"
.endif	# WINDOWSWMPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-windowswmproto
