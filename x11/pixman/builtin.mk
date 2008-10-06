# $NetBSD: builtin.mk,v 1.5 2008/10/06 11:22:09 tron Exp $

BUILTIN_PKG:=	pixman
PKGCONFIG_FILE.pixman=	${X11BASE}/lib/pkgconfig/pixman-1.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"

# Work around broken libtool archive "/usr/X11/lib/libpixman-1.la" under
# Mac OS 10.5.4 or newer which references a non-existing version of the
# PNG shared library.
.if !empty(MACHINE_PLATFORM:MDarwin-9.*-*)
BUILDLINK_TRANSFORM+=	rename:-lpixman-1.0.10.0:-lpixman-1
.endif
