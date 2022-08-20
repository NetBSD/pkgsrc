# $NetBSD: buildlink3.mk,v 1.3 2022/08/20 08:08:23 wiz Exp $

BUILDLINK_TREE+=	hs-bower-json

.if !defined(HS_BOWER_JSON_BUILDLINK3_MK)
HS_BOWER_JSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bower-json+=	hs-bower-json>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-bower-json+=	hs-bower-json>=1.0.0.1nb2
BUILDLINK_PKGSRCDIR.hs-bower-json?=	../../www/hs-bower-json

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-better-errors/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_BOWER_JSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bower-json
