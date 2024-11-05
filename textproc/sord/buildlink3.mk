# $NetBSD: buildlink3.mk,v 1.3 2024/11/05 17:20:04 adam Exp $

BUILDLINK_TREE+=	sord

.if !defined(SORD_BUILDLINK3_MK)
SORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sord+=	sord>=0.12.2
BUILDLINK_ABI_DEPENDS.sord+=	sord>=0.16.10nb1
BUILDLINK_PKGSRCDIR.sord?=	../../textproc/sord

.include "../../devel/zix/buildlink3.mk"
.include "../../textproc/serd/buildlink3.mk"
.endif	# SORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-sord
