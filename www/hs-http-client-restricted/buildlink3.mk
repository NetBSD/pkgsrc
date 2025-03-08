# $NetBSD: buildlink3.mk,v 1.6 2025/03/08 05:13:51 pho Exp $

BUILDLINK_TREE+=	hs-http-client-restricted

.if !defined(HS_HTTP_CLIENT_RESTRICTED_BUILDLINK3_MK)
HS_HTTP_CLIENT_RESTRICTED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-client-restricted+=	hs-http-client-restricted>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-http-client-restricted+=	hs-http-client-restricted>=0.1.0nb5
BUILDLINK_PKGSRCDIR.hs-http-client-restricted?=		../../www/hs-http-client-restricted

.include "../../net/hs-crypton-connection/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-bsd/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HS_HTTP_CLIENT_RESTRICTED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-client-restricted
