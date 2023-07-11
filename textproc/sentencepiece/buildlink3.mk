# $NetBSD: buildlink3.mk,v 1.2 2023/07/11 06:09:29 nia Exp $

BUILDLINK_TREE+=	sentencepiece

.if !defined(SENTENCEPIECE_BUILDLINK3_MK)
SENTENCEPIECE_BUILDLINK3_MK:=

# C++17
GCC_REQD+=	7

BUILDLINK_API_DEPENDS.sentencepiece+=	sentencepiece>=0.1.97
BUILDLINK_PKGSRCDIR.sentencepiece?=	../../textproc/sentencepiece
.endif	# SENTENCEPIECE_BUILDLINK3_MK

BUILDLINK_TREE+=	-sentencepiece
