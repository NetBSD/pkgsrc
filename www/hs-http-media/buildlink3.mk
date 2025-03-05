# $NetBSD: buildlink3.mk,v 1.8 2025/03/05 03:40:10 pho Exp $

BUILDLINK_TREE+=	hs-http-media

.if !defined(HS_HTTP_MEDIA_BUILDLINK3_MK)
HS_HTTP_MEDIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-media+=	hs-http-media>=0.8.1.1
BUILDLINK_ABI_DEPENDS.hs-http-media+=	hs-http-media>=0.8.1.1nb4
BUILDLINK_PKGSRCDIR.hs-http-media?=	../../www/hs-http-media

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HS_HTTP_MEDIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-media
