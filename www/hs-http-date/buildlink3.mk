# $NetBSD: buildlink3.mk,v 1.6 2023/10/09 04:54:58 pho Exp $

BUILDLINK_TREE+=	hs-http-date

.if !defined(HS_HTTP_DATE_BUILDLINK3_MK)
HS_HTTP_DATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-date+=	hs-http-date>=0.0.11
BUILDLINK_ABI_DEPENDS.hs-http-date+=	hs-http-date>=0.0.11nb5
BUILDLINK_PKGSRCDIR.hs-http-date?=	../../www/hs-http-date

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.endif	# HS_HTTP_DATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-date
