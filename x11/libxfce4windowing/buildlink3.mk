# $NetBSD: buildlink3.mk,v 1.13 2026/09/02 19:05:17 wiz Exp $

BUILDLINK_TREE+=	libxfce4windowing

.if !defined(LIBXFCE4WINDOWING_BUILDLINK3_MK)
LIBXFCE4WINDOWING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4windowing+=	libxfce4windowing>=4.20.0nb1
BUILDLINK_ABI_DEPENDS.libxfce4windowing?=	libxfce4windowing>=4.20.6nb2
BUILDLINK_PKGSRCDIR.libxfce4windowing?=		../../x11/libxfce4windowing

.include "../../devel/libwnck3/buildlink3.mk"
.include "../../x11/libdisplay-info/buildlink3.mk"
.endif	# LIBXFCE4WINDOWING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4windowing
