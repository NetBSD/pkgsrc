# $NetBSD: buildlink3.mk,v 1.2 2022/01/18 02:48:31 pho Exp $

BUILDLINK_TREE+=	hs-http-conduit

.if !defined(HS_HTTP_CONDUIT_BUILDLINK3_MK)
HS_HTTP_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-conduit+=	hs-http-conduit>=2.3.8
BUILDLINK_ABI_DEPENDS.hs-http-conduit+=	hs-http-conduit>=2.3.8nb1
BUILDLINK_PKGSRCDIR.hs-http-conduit?=	../../www/hs-http-conduit

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.endif	# HS_HTTP_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-conduit
