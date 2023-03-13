# $NetBSD: buildlink3.mk,v 1.1 2023/03/13 14:17:12 wiz Exp $

BUILDLINK_TREE+=	sentencepiece

.if !defined(SENTENCEPIECE_BUILDLINK3_MK)
SENTENCEPIECE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sentencepiece+=	sentencepiece>=0.1.97
BUILDLINK_PKGSRCDIR.sentencepiece?=	../../textproc/sentencepiece
.endif	# SENTENCEPIECE_BUILDLINK3_MK

BUILDLINK_TREE+=	-sentencepiece
