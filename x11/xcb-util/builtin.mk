# $NetBSD: builtin.mk,v 1.7 2022/12/26 22:10:43 wiz Exp $

BUILTIN_PKG:=			xcb-util
PKGCONFIG_FILE.xcb-util=	${X11BASE}/lib/pkgconfig/xcb-atom.pc
PKGCONFIG_FILE.xcb-util+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xcb-atom.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"

.if ${USE_BUILTIN.xcb-util:tl} == yes
BUILDLINK_FILES.xcb-util+=	lib/pkgconfig/xcb-atom.pc
BUILDLINK_FILES.xcb-util+=	lib/pkgconfig/xcb-aux.pc
BUILDLINK_FILES.xcb-util+=	lib/pkgconfig/xcb-event.pc
BUILDLINK_FILES.xcb-util+=	lib/pkgconfig/xcb-util.pc
.endif
