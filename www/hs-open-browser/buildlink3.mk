# $NetBSD: buildlink3.mk,v 1.4 2023/10/09 04:54:59 pho Exp $

BUILDLINK_TREE+=	hs-open-browser

.if !defined(HS_OPEN_BROWSER_BUILDLINK3_MK)
HS_OPEN_BROWSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-open-browser+=	hs-open-browser>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-open-browser+=	hs-open-browser>=0.2.1.0nb3
BUILDLINK_PKGSRCDIR.hs-open-browser?=	../../www/hs-open-browser
.endif	# HS_OPEN_BROWSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-open-browser
