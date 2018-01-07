# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:39 rillig Exp $

BUILDLINK_TREE+=	libXevie

.if !defined(LIBXEVIE_BUILDLINK3_MK)
LIBXEVIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXevie+=	libXevie>=1.0.2
BUILDLINK_PKGSRCDIR.libXevie?=		../../x11/libXevie

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # LIBXEVIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXevie
