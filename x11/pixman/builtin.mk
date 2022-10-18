# $NetBSD: builtin.mk,v 1.10 2022/10/18 11:06:46 wiz Exp $

BUILTIN_PKG:=		pixman
PKGCONFIG_FILE.pixman=	${X11BASE}/lib/pkgconfig/pixman-1.pc
PKGCONFIG_FILE.pixman+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/pixman-1.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"

# Work around broken libtool archive "/usr/X11/lib/libpixman-1.la" under
# Mac OS 10.5.4 or newer which references a non-existing version of the
# PNG shared library.
CHECK_BUILTIN.pixman?=	no
.if ${CHECK_BUILTIN.pixman:M[nN][oO]} && \
    ${USE_BUILTIN.pixman:M[Yy][Ee][Ss]} && \
    !empty(MACHINE_PLATFORM:MDarwin-9.*-*)
BUILDLINK_TRANSFORM+=	opt:-lpixman-1.0.10.0:-lpixman-1
.endif
