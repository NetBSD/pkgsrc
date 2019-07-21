# $NetBSD: buildlink3.mk,v 1.58 2019/07/21 22:24:18 wiz Exp $

BUILDLINK_TREE+=	libxfce4gui

.if !defined(LIBXFCE4GUI_BUILDLINK3_MK)
LIBXFCE4GUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4gui+=	libxfce4gui>=4.10.0
BUILDLINK_ABI_DEPENDS.libxfce4gui?=	libxfce4gui>=4.10.0nb11
BUILDLINK_PKGSRCDIR.libxfce4gui?=	../../x11/libxfce4gui

.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.endif	# LIBXFCE4GUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4gui
