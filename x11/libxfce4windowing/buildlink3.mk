# $NetBSD: buildlink3.mk,v 1.1 2024/12/26 18:40:14 bsiegert Exp $

BUILDLINK_TREE+=	libxfce4windowing

.if !defined(LIBXFCE4WINDOWING_BUILDLINK3_MK)
LIBXFCE4WINDOWING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4windowing+=	libxfce4windowing>=4.20.0nb1
BUILDLINK_PKGSRCDIR.libxfce4windowing?=	../../x11/libxfce4windowing

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBXFCE4WINDOWING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4windowing
