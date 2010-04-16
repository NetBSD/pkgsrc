# $NetBSD: buildlink3.mk,v 1.5 2010/04/16 13:43:36 tnn Exp $

BUILDLINK_TREE+=	libdrm

.if !defined(LIBDRM_BUILDLINK3_MK)
LIBDRM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.20
BUILDLINK_PKGSRCDIR.libdrm?=	../../x11/libdrm
.endif # LIBDRM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdrm
