# $NetBSD: builtin.mk,v 1.5 2015/12/29 04:54:39 dholland Exp $

BUILTIN_PKG:=	xcb-util
PKGCONFIG_FILE.xcb-util=	${X11BASE}/lib/pkgconfig/xcb-atom.pc
PKGCONFIG_FILE.xcb-util+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xcb-atom.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"

.if !empty(USE_BUILTIN.xcb-util:M[yY][eE][sS])
BUILDLINK_FILES.xcb-util+=	lib/pkgconfig/xcb-atom.pc
BUILDLINK_FILES.xcb-util+=	lib/pkgconfig/xcb-aux.pc
BUILDLINK_FILES.xcb-util+=	lib/pkgconfig/xcb-event.pc
BUILDLINK_FILES.xcb-util+=	lib/pkgconfig/xcb-util.pc
.endif
