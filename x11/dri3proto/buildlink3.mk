# $NetBSD: buildlink3.mk,v 1.1 2015/03/09 21:33:28 tnn Exp $

BUILDLINK_TREE+=	dri3proto

.if !defined(DRI3PROTO_BUILDLINK3_MK)
DRI3PROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.dri3proto?=	build

BUILDLINK_API_DEPENDS.dri3proto+=	dri3proto>=1.0
BUILDLINK_PKGSRCDIR.dri3proto?=	../../x11/dri3proto
.endif	# DRI3PROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-dri3proto
