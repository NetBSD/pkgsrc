# $NetBSD: buildlink3.mk,v 1.4 2013/04/06 13:46:34 rodent Exp $

BUILDLINK_TREE+=	dri2proto

.if !defined(DRI2PROTO_BUILDLINK3_MK)
DRI2PROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.dri2proto?=	build

BUILDLINK_API_DEPENDS.dri2proto+=	dri2proto>=2.0
BUILDLINK_PKGSRCDIR.dri2proto?=		../../x11/dri2proto

.endif # DRI2PROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-dri2proto
