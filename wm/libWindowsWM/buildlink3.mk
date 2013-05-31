# $NetBSD: buildlink3.mk,v 1.1 2013/05/31 00:28:47 rodent Exp $

BUILDLINK_TREE+=	libWindowsWM

.if !defined(LIBWINDOWSWM_BUILDLINK3_MK)
LIBWINDOWSWM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libWindowsWM+=	libWindowsWM>=1.0.1
BUILDLINK_PKGSRCDIR.libWindowsWM?=	../../wm/libWindowsWM

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# LIBWINDOWSWM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libWindowsWM
