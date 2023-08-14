# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:25:25 wiz Exp $

BUILDLINK_TREE+=	sord

.if !defined(SORD_BUILDLINK3_MK)
SORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sord+=	sord>=0.12.2
BUILDLINK_ABI_DEPENDS.sord?=	sord>=0.16.10nb1
BUILDLINK_PKGSRCDIR.sord?=	../../textproc/sord

.include "../../textproc/serd/buildlink3.mk"
.endif	# SORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-sord
