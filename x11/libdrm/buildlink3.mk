# $NetBSD: buildlink3.mk,v 1.8 2025/01/24 20:40:54 riastradh Exp $

BUILDLINK_TREE+=	libdrm

.if !defined(LIBDRM_BUILDLINK3_MK)
LIBDRM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.15
BUILDLINK_PKGSRCDIR.libdrm?=	../../x11/libdrm
BUILDLINK_INCDIRS.libdrm?=	include/libdrm

.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
.    include "../../sysutils/libpciaccess/buildlink3.mk"
.  endif
.endif # LIBDRM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdrm
