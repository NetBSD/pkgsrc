# $NetBSD: buildlink3.mk,v 1.1 2015/04/19 23:10:52 rodent Exp $

BUILDLINK_TREE+=	serd

.if !defined(SERD_BUILDLINK3_MK)
SERD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.serd+=	serd>=0.20.0
BUILDLINK_PKGSRCDIR.serd?=	../../textproc/serd
.endif	# SERD_BUILDLINK3_MK

BUILDLINK_TREE+=	-serd
