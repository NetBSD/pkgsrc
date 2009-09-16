# $NetBSD: buildlink3.mk,v 1.24 2009/09/16 01:15:35 reed Exp $

BUILDLINK_TREE+=	libxfce4util

.if !defined(LIBXFCE4UTIL_BUILDLINK3_MK)
LIBXFCE4UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4util+=	libxfce4util>=4.6.0
BUILDLINK_PKGSRCDIR.libxfce4util?=	../../x11/libxfce4util

.include "../../devel/glib2/buildlink3.mk"
.endif # LIBXFCE4UTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4util
