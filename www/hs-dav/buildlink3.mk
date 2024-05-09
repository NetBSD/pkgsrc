# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:52 pho Exp $

BUILDLINK_TREE+=	hs-dav

.if !defined(HS_DAV_BUILDLINK3_MK)
HS_DAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dav+=	hs-dav>=1.3.4
BUILDLINK_ABI_DEPENDS.hs-dav+=	hs-dav>=1.3.4nb2
BUILDLINK_PKGSRCDIR.hs-dav?=	../../www/hs-dav

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../textproc/hs-xml-conduit/buildlink3.mk"
.include "../../textproc/hs-xml-hamlet/buildlink3.mk"
.endif	# HS_DAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dav
