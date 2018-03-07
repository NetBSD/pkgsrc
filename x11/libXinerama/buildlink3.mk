# $NetBSD: buildlink3.mk,v 1.10 2018/03/07 11:57:36 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && \
    !exists(${X11BASE}/lib/pkgconfig/xinerama.pc) && \
    !exists(${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xinerama.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libXinerama

.  if !defined(LIBXINERAMA_BUILDLINK3_MK)
LIBXINERAMA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXinerama+=	libXinerama>=1.0.1
BUILDLINK_PKGSRCDIR.libXinerama?=	../../x11/libXinerama

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.  endif # LIBXINERAMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXinerama

.endif
