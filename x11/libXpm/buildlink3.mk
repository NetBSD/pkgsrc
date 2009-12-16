# $NetBSD: buildlink3.mk,v 1.5 2009/12/16 19:57:47 joerg Exp $

BUILDLINK_TREE+=	libXpm

.if !defined(LIBXPM_BUILDLINK3_MK)
LIBXPM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXpm+=	libXpm>=3.5.4.2
BUILDLINK_PKGSRCDIR.libXpm?=	../../x11/libXpm

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif	# LIBXPM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXpm
