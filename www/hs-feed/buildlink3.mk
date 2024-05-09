# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:52 pho Exp $

BUILDLINK_TREE+=	hs-feed

.if !defined(HS_FEED_BUILDLINK3_MK)
HS_FEED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-feed+=	hs-feed>=1.3.2
BUILDLINK_ABI_DEPENDS.hs-feed+=	hs-feed>=1.3.2.1nb2
BUILDLINK_PKGSRCDIR.hs-feed?=	../../www/hs-feed

.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../time/hs-old-time/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../time/hs-time-locale-compat/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../textproc/hs-xml-conduit/buildlink3.mk"
.include "../../textproc/hs-xml-types/buildlink3.mk"
.endif	# HS_FEED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-feed
