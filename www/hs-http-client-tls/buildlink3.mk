# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:31 pho Exp $

BUILDLINK_TREE+=	hs-http-client-tls

.if !defined(HS_HTTP_CLIENT_TLS_BUILDLINK3_MK)
HS_HTTP_CLIENT_TLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-client-tls+=	hs-http-client-tls>=0.3.5
BUILDLINK_ABI_DEPENDS.hs-http-client-tls+=	hs-http-client-tls>=0.3.5.3nb2
BUILDLINK_PKGSRCDIR.hs-http-client-tls?=	../../www/hs-http-client-tls

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../net/hs-connection/buildlink3.mk"
.include "../../security/hs-cryptonite/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.endif	# HS_HTTP_CLIENT_TLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-client-tls
