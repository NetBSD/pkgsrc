# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:51 pho Exp $

BUILDLINK_TREE+=	hs-time-locale-compat

.if !defined(HS_TIME_LOCALE_COMPAT_BUILDLINK3_MK)
HS_TIME_LOCALE_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-time-locale-compat+=	hs-time-locale-compat>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-time-locale-compat+=	hs-time-locale-compat>=0.1.1.5nb2
BUILDLINK_PKGSRCDIR.hs-time-locale-compat?=	../../time/hs-time-locale-compat

.include "../../devel/hs-old-locale/buildlink3.mk"
.endif	# HS_TIME_LOCALE_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-time-locale-compat
