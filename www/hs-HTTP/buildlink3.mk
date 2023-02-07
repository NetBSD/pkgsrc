# $NetBSD: buildlink3.mk,v 1.20 2023/02/07 01:41:17 pho Exp $

BUILDLINK_TREE+=	hs-HTTP

.if !defined(HS_HTTP_BUILDLINK3_MK)
HS_HTTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HTTP+=	hs-HTTP>=4000.4.1
BUILDLINK_ABI_DEPENDS.hs-HTTP+=	hs-HTTP>=4000.4.1nb1
BUILDLINK_PKGSRCDIR.hs-HTTP?=	../../www/hs-HTTP

.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.endif	# HS_HTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HTTP
