# $NetBSD: buildlink3.mk,v 1.5 2025/02/02 13:06:01 pho Exp $

BUILDLINK_TREE+=	hs-text-iso8601

.if !defined(HS_TEXT_ISO8601_BUILDLINK3_MK)
HS_TEXT_ISO8601_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text-iso8601+=	hs-text-iso8601>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-text-iso8601+=	hs-text-iso8601>=0.1.1nb1
BUILDLINK_PKGSRCDIR.hs-text-iso8601?=	../../time/hs-text-iso8601

.include "../../math/hs-integer-conversion/buildlink3.mk"
.include "../../time/hs-time-compat/buildlink3.mk"
.endif	# HS_TEXT_ISO8601_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text-iso8601
