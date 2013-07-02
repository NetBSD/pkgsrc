# $NetBSD: buildlink3.mk,v 1.1 2013/07/02 11:37:34 rodent Exp $

BUILDLINK_TREE+=	libgcal

.if !defined(LIBGCAL_BUILDLINK3_MK)
LIBGCAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgcal+=	libgcal>=0.9.6
BUILDLINK_PKGSRCDIR.libgcal?=	../../time/libgcal

.include "../../devel/check/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBGCAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgcal
