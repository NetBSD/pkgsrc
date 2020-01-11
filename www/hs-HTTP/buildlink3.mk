# $NetBSD: buildlink3.mk,v 1.13 2020/01/11 10:25:05 pho Exp $

BUILDLINK_TREE+=	hs-HTTP

.if !defined(HS_HTTP_BUILDLINK3_MK)
HS_HTTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HTTP+=	hs-HTTP>=4000.3.14
BUILDLINK_ABI_DEPENDS.hs-HTTP+=	hs-HTTP>=4000.3.14
BUILDLINK_PKGSRCDIR.hs-HTTP?=	../../www/hs-HTTP

.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.endif	# HS_HTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HTTP
