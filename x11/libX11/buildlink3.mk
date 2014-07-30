# $NetBSD: buildlink3.mk,v 1.11 2014/07/30 20:34:50 jperkin Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && \
    !exists(${X11BASE}/lib/pkgconfig/x11.pc) && \
    !exists(${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/x11.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libX11

.if !defined(LIBX11_BUILDLINK3_MK)
LIBX11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.1
BUILDLINK_ABI_DEPENDS.libX11+=	libX11>=0.99
BUILDLINK_PKGSRCDIR.libX11?=	../../x11/libX11

X11_LDFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
X11_LDFLAGS+=	-L${BUILDLINK_PREFIX.libX11}/lib

.if ${OPSYS} == "OSF1" || ${OPSYS} == "MirBSD" || ${OPSYS} == "OpenBSD"
.include "../../mk/pthread.buildlink3.mk"
.endif

.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"

.if ${X11_TYPE} == "modular" || \
    exists(${X11BASE}/lib/pkgconfig/xcb.pc) || \
    exists(${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xcb.pc)
.include "../../x11/libxcb/buildlink3.mk"
.endif

.include "../../x11/xproto/buildlink3.mk"
.endif # LIBX11_BUILDLINK3_MK

BUILDLINK_TREE+=	-libX11

.endif
