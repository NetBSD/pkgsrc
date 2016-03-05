# $NetBSD: buildlink3.mk,v 1.3 2016/03/05 11:27:57 jperkin Exp $

BUILDLINK_TREE+=	libgcal

.if !defined(LIBGCAL_BUILDLINK3_MK)
LIBGCAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgcal+=	libgcal>=0.9.6
BUILDLINK_ABI_DEPENDS.libgcal?=	libgcal>=0.9.6nb2
BUILDLINK_PKGSRCDIR.libgcal?=	../../time/libgcal

.include "../../devel/check/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBGCAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgcal
