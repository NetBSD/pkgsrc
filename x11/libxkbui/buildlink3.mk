# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:25:47 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libxkbui

.if !defined(LIBXKBUI_BUILDLINK3_MK)
LIBXKBUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxkbui+=	libxkbui>=1.0.2
BUILDLINK_PKGSRCDIR.libxkbui?=	../../x11/libxkbui

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.endif # LIBXKBUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxkbui

.endif
