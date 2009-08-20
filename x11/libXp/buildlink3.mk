# $NetBSD: buildlink3.mk,v 1.4 2009/08/20 17:59:10 joerg Exp $

BUILDLINK_TREE+=	libXp

.if !defined(LIBXP_BUILDLINK3_MK)
LIBXP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXp+=	libXp>=1.0.0
BUILDLINK_PKGSRCDIR.libXp?=	../../x11/libXp

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/printproto/buildlink3.mk"
.endif # LIBXP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXp
