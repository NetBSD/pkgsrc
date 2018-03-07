# $NetBSD: buildlink3.mk,v 1.2 2018/03/07 12:00:13 wiz Exp $

BUILDLINK_TREE+=	xorgproto

.if !defined(XORGPROTO_BUILDLINK3_MK)
XORGPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xorgproto+=	xorgproto>=2018.1
BUILDLINK_PKGSRCDIR.xorgproto?=		../../x11/xorgproto
BUILDLINK_DEPMETHOD.xorgproto?=		build
.endif	# XORGPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xorgproto
