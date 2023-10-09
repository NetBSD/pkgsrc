# $NetBSD: buildlink3.mk,v 1.3 2023/10/09 04:54:59 pho Exp $

BUILDLINK_TREE+=	hs-http-media

.if !defined(HS_HTTP_MEDIA_BUILDLINK3_MK)
HS_HTTP_MEDIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-media+=	hs-http-media>=0.8.0
BUILDLINK_ABI_DEPENDS.hs-http-media+=	hs-http-media>=0.8.0.0nb2
BUILDLINK_PKGSRCDIR.hs-http-media?=	../../www/hs-http-media

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HS_HTTP_MEDIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-media
