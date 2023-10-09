# $NetBSD: buildlink3.mk,v 1.9 2023/10/09 04:55:01 pho Exp $

BUILDLINK_TREE+=	hs-xss-sanitize

.if !defined(HS_XSS_SANITIZE_BUILDLINK3_MK)
HS_XSS_SANITIZE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-xss-sanitize+=	hs-xss-sanitize>=0.3.7
BUILDLINK_ABI_DEPENDS.hs-xss-sanitize+=	hs-xss-sanitize>=0.3.7.1nb2
BUILDLINK_PKGSRCDIR.hs-xss-sanitize?=	../../www/hs-xss-sanitize

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../textproc/hs-css-text/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../textproc/hs-tagsoup/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HS_XSS_SANITIZE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-xss-sanitize
