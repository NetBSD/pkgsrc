# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:44 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../x11/xcursor/buildlink3.mk"
.else

BUILDLINK_TREE+=	libXcursor

.if !defined(LIBXCURSOR_BUILDLINK3_MK)
LIBXCURSOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXcursor+=	libXcursor>=1.1.1
BUILDLINK_PKGSRCDIR.libXcursor?=	../../x11/libXcursor

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # LIBXCURSOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXcursor

.endif
