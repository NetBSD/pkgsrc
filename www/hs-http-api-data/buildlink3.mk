# $NetBSD: buildlink3.mk,v 1.1 2023/01/28 19:59:27 pho Exp $

BUILDLINK_TREE+=	hs-http-api-data

.if !defined(HS_HTTP_API_DATA_BUILDLINK3_MK)
HS_HTTP_API_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-api-data+=	hs-http-api-data>=0.5
BUILDLINK_ABI_DEPENDS.hs-http-api-data+=	hs-http-api-data>=0.5
BUILDLINK_PKGSRCDIR.hs-http-api-data?=		../../www/hs-http-api-data

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../textproc/hs-attoparsec-iso8601/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../www/hs-cookie/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../time/hs-time-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-uuid-types/buildlink3.mk"
.endif	# HS_HTTP_API_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-api-data
