# $NetBSD: buildlink3.mk,v 1.1 2015/07/02 12:38:32 rodent Exp $

BUILDLINK_TREE+=	libXprintAppUtil

.if !defined(LIBXPRINTAPPUTIL_BUILDLINK3_MK)
LIBXPRINTAPPUTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXprintAppUtil+=	libXprintAppUtil>=1.0.1
BUILDLINK_PKGSRCDIR.libXprintAppUtil?=	../../x11/libXprintAppUtil

.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXprintUtil/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# LIBXPRINTAPPUTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXprintAppUtil
