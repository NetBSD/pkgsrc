# $NetBSD: buildlink3.mk,v 1.3 2024/11/05 17:16:45 adam Exp $

BUILDLINK_TREE+=	serd

.if !defined(SERD_BUILDLINK3_MK)
SERD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.serd+=	serd>=0.20.0
BUILDLINK_ABI_DEPENDS.serd+=	serd>=0.30.12nb1
BUILDLINK_PKGSRCDIR.serd?=	../../textproc/serd
.endif	# SERD_BUILDLINK3_MK

BUILDLINK_TREE+=	-serd
