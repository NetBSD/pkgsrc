# $NetBSD: buildlink3.mk,v 1.1 2021/05/04 14:24:33 prlw1 Exp $

BUILDLINK_TREE+=	utf8-cpp

.if !defined(UTF8_CPP_BUILDLINK3_MK)
UTF8_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.utf8-cpp+=	utf8-cpp>=2.3.4
BUILDLINK_PKGSRCDIR.utf8-cpp?=		../../textproc/utf8-cpp
BUILDLINK_DEPMETHOD.utf8-cpp?=		build
.endif	# UTF8_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-utf8-cpp
