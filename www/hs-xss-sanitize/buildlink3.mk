# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:32 pho Exp $

BUILDLINK_TREE+=	hs-xss-sanitize

.if !defined(HS_XSS_SANITIZE_BUILDLINK3_MK)
HS_XSS_SANITIZE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-xss-sanitize+=	hs-xss-sanitize>=0.3.6
BUILDLINK_ABI_DEPENDS.hs-xss-sanitize+=	hs-xss-sanitize>=0.3.6nb2
BUILDLINK_PKGSRCDIR.hs-xss-sanitize?=	../../www/hs-xss-sanitize

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../textproc/hs-css-text/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../textproc/hs-tagsoup/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HS_XSS_SANITIZE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-xss-sanitize
