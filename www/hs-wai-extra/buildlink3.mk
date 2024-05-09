# $NetBSD: buildlink3.mk,v 1.6 2024/05/09 01:32:55 pho Exp $

BUILDLINK_TREE+=	hs-wai-extra

.if !defined(HS_WAI_EXTRA_BUILDLINK3_MK)
HS_WAI_EXTRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-wai-extra+=	hs-wai-extra>=3.1.14
BUILDLINK_ABI_DEPENDS.hs-wai-extra+=	hs-wai-extra>=3.1.14nb1
BUILDLINK_PKGSRCDIR.hs-wai-extra?=	../../www/hs-wai-extra

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../devel/hs-call-stack/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../www/hs-cookie/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../sysutils/hs-fast-logger/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-HUnit/buildlink3.mk"
.include "../../net/hs-iproute/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-streaming-commons/buildlink3.mk"
.include "../../devel/hs-vault/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-wai-logger/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.include "../../devel/hs-word8/buildlink3.mk"
.endif	# HS_WAI_EXTRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-wai-extra
