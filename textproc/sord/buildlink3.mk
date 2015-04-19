# $NetBSD: buildlink3.mk,v 1.1 2015/04/19 23:23:10 rodent Exp $

BUILDLINK_TREE+=	sord

.if !defined(SORD_BUILDLINK3_MK)
SORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sord+=	sord>=0.12.2
BUILDLINK_PKGSRCDIR.sord?=	../../textproc/sord

.include "../../textproc/serd/buildlink3.mk"
.endif	# SORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-sord
