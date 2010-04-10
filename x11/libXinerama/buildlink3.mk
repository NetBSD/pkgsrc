# $NetBSD: buildlink3.mk,v 1.6 2010/04/10 21:09:21 tnn Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && !exists(${X11BASE}/lib/pkgconfig/xinerama.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libXinerama

.if !defined(LIBXINERAMA_BUILDLINK3_MK)
LIBXINERAMA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXinerama+=	libXinerama>=1.0.1
BUILDLINK_PKGSRCDIR.libXinerama?=	../../x11/libXinerama

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.endif # LIBXINERAMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXinerama

.endif
