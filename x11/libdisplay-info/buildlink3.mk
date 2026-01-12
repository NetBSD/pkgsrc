# $NetBSD: buildlink3.mk,v 1.2 2026/01/12 22:20:29 gutteridge Exp $

BUILDLINK_TREE+=	libdisplay-info

.if !defined(LIBDISPLAY_INFO_BUILDLINK3_MK)
LIBDISPLAY_INFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdisplay-info+=	libdisplay-info>=0.2.0
BUILDLINK_ABI_DEPENDS.libdisplay-info?=	libdisplay-info>=0.3.0
BUILDLINK_PKGSRCDIR.libdisplay-info?=	../../x11/libdisplay-info

.endif	# LIBDISPLAY_INFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdisplay-info
