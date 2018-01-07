# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:39 rillig Exp $

BUILDLINK_TREE+=	libXTrap

.if !defined(LIBXTRAP_BUILDLINK3_MK)
LIBXTRAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXTrap+=	libXTrap>=1.0.0
BUILDLINK_PKGSRCDIR.libXTrap?=		../../x11/libXTrap

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif # LIBXTRAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXTrap
