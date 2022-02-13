# $NetBSD: buildlink3.mk,v 1.1 2022/02/13 11:15:02 pin Exp $

BUILDLINK_TREE+=	wmutils-libwm

.if !defined(WMUTILS_LIBWM_BUILDLINK3_MK)
WMUTILS_LIBWM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wmutils-libwm+=	wmutils-libwm>=1.2
BUILDLINK_PKGSRCDIR.wmutils-libwm?=	../../wm/wmutils-libwm

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.endif	# WMUTILS_LIBWM_BUILDLINK3_MK

BUILDLINK_TREE+=	-wmutils-libwm
