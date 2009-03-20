# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:45 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

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

.endif
