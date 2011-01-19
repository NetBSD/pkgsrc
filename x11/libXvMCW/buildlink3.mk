# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/19 00:42:12 jmcneill Exp $

BUILDLINK_TREE+=	libXvMCW

.if !defined(LIBXVMCW_BUILDLINK3_MK)
LIBXVMCW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXvMCW+=	libXvMCW>=0.9.3
BUILDLINK_PKGSRCDIR.libXvMCW?=	../../x11/libXvMCW

.include "../../x11/libXvMC/buildlink3.mk"
.endif	# LIBXVMCW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXvMCW
