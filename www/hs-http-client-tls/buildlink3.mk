# $NetBSD: buildlink3.mk,v 1.16 2025/02/02 13:06:04 pho Exp $

BUILDLINK_TREE+=	hs-http-client-tls

.if !defined(HS_HTTP_CLIENT_TLS_BUILDLINK3_MK)
HS_HTTP_CLIENT_TLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-client-tls+=	hs-http-client-tls>=0.3.6
BUILDLINK_ABI_DEPENDS.hs-http-client-tls+=	hs-http-client-tls>=0.3.6.4nb1
BUILDLINK_PKGSRCDIR.hs-http-client-tls?=	../../www/hs-http-client-tls

.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../net/hs-crypton-connection/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.endif	# HS_HTTP_CLIENT_TLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-client-tls
