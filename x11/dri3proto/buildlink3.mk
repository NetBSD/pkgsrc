# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:37 rillig Exp $

BUILDLINK_TREE+=	dri3proto

.if !defined(DRI3PROTO_BUILDLINK3_MK)
DRI3PROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.dri3proto?=	build

BUILDLINK_API_DEPENDS.dri3proto+=	dri3proto>=1.0
BUILDLINK_PKGSRCDIR.dri3proto?=		../../x11/dri3proto
.endif	# DRI3PROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-dri3proto
