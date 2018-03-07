# $NetBSD: buildlink3.mk,v 1.7 2018/03/07 11:57:37 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && \
    !exists(${X11BASE}/lib/pkgconfig/xrender.pc) && \
    !exists(${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xrender.pc)
.include "../../x11/Xrender/buildlink3.mk"
.else

BUILDLINK_TREE+=	libXrender

.  if !defined(LIBXRENDER_BUILDLINK3_MK)
LIBXRENDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXrender+=	libXrender>=0.9.2
BUILDLINK_PKGSRCDIR.libXrender?=	../../x11/libXrender

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.  endif # LIBXRENDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXrender

.endif
