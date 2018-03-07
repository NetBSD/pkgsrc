# $NetBSD: buildlink3.mk,v 1.4 2018/03/07 11:57:36 wiz Exp $

BUILDLINK_TREE+=	libXevie

.if !defined(LIBXEVIE_BUILDLINK3_MK)
LIBXEVIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXevie+=	libXevie>=1.0.2
BUILDLINK_PKGSRCDIR.libXevie?=		../../x11/libXevie

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.endif # LIBXEVIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXevie
