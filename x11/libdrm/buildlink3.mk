# $NetBSD: buildlink3.mk,v 1.7 2013/05/16 05:43:14 richard Exp $

BUILDLINK_TREE+=	libdrm

.if !defined(LIBDRM_BUILDLINK3_MK)
LIBDRM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.15
BUILDLINK_PKGSRCDIR.libdrm?=	../../x11/libdrm
BUILDLINK_INCDIRS.libdrm?=	include/libdrm
.endif # LIBDRM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdrm
