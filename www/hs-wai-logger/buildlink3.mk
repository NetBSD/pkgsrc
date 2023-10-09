# $NetBSD: buildlink3.mk,v 1.7 2023/10/09 04:55:00 pho Exp $

BUILDLINK_TREE+=	hs-wai-logger

.if !defined(HS_WAI_LOGGER_BUILDLINK3_MK)
HS_WAI_LOGGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-wai-logger+=	hs-wai-logger>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-wai-logger+=	hs-wai-logger>=2.4.0nb4
BUILDLINK_PKGSRCDIR.hs-wai-logger?=	../../www/hs-wai-logger

.include "../../sysutils/hs-byteorder/buildlink3.mk"
.include "../../sysutils/hs-fast-logger/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.endif	# HS_WAI_LOGGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-wai-logger
