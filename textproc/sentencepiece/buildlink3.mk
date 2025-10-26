# $NetBSD: buildlink3.mk,v 1.3 2025/10/26 12:15:39 ryoon Exp $

BUILDLINK_TREE+=	sentencepiece

.if !defined(SENTENCEPIECE_BUILDLINK3_MK)
SENTENCEPIECE_BUILDLINK3_MK:=

# C++17
GCC_REQD+=	7

BUILDLINK_API_DEPENDS.sentencepiece+=	sentencepiece>=0.2.0
BUILDLINK_PKGSRCDIR.sentencepiece?=	../../textproc/sentencepiece
.endif	# SENTENCEPIECE_BUILDLINK3_MK

BUILDLINK_TREE+=	-sentencepiece
