# $NetBSD: buildlink3.mk,v 1.1 2018/02/11 20:13:08 wiz Exp $

BUILDLINK_TREE+=	xorgproto

.if !defined(XORGPROTO_BUILDLINK3_MK)
XORGPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xorgproto+=	xorgproto>=2018.1
BUILDLINK_PKGSRCDIR.xorgproto?=	../../x11/xorgproto
.endif	# XORGPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xorgproto
