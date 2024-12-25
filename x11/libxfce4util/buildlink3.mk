# $NetBSD: buildlink3.mk,v 1.37 2024/12/25 11:05:57 bsiegert Exp $

BUILDLINK_TREE+=	libxfce4util

.if !defined(LIBXFCE4UTIL_BUILDLINK3_MK)
LIBXFCE4UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4util+=	libxfce4util>=4.20.0
BUILDLINK_ABI_DEPENDS.libxfce4util+=	libxfce4util>=4.20.0
BUILDLINK_PKGSRCDIR.libxfce4util?=	../../x11/libxfce4util

.endif # LIBXFCE4UTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4util
