# $NetBSD: buildlink3.mk,v 1.6 2017/04/30 01:21:25 ryoon Exp $

BUILDLINK_TREE+=	libgcal

.if !defined(LIBGCAL_BUILDLINK3_MK)
LIBGCAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgcal+=	libgcal>=0.9.6
BUILDLINK_ABI_DEPENDS.libgcal?=	libgcal>=0.9.6nb5
BUILDLINK_PKGSRCDIR.libgcal?=	../../time/libgcal

.include "../../devel/check/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBGCAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgcal
