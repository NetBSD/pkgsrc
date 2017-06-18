# $NetBSD: buildlink3.mk,v 1.35 2017/06/18 21:22:08 youri Exp $

BUILDLINK_TREE+=	libxfce4util

.if !defined(LIBXFCE4UTIL_BUILDLINK3_MK)
LIBXFCE4UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4util+=	libxfce4util>=4.12.0
BUILDLINK_ABI_DEPENDS.libxfce4util+=	libxfce4util>=4.12.1nb4
BUILDLINK_PKGSRCDIR.libxfce4util?=	../../x11/libxfce4util

.endif # LIBXFCE4UTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4util
