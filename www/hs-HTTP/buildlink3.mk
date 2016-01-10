# $NetBSD: buildlink3.mk,v 1.11 2016/01/10 11:49:11 szptvlfn Exp $

BUILDLINK_TREE+=	hs-HTTP

.if !defined(HS_HTTP_BUILDLINK3_MK)
HS_HTTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HTTP+=	hs-HTTP>=4000.2.17
BUILDLINK_ABI_DEPENDS.hs-HTTP+=	hs-HTTP>=4000.2.17nb10
BUILDLINK_PKGSRCDIR.hs-HTTP?=	../../www/hs-HTTP

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_HTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HTTP
