# $NetBSD: Makefile,v 1.39 2003/04/18 23:07:17 martin Exp $
# FreeBSD Id: Makefile,v 1.13 1997/03/07 12:29:49 obrien Exp
#

DISTNAME=		rxvt-2.7.10
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.rxvt.org/pub/rxvt/ \
			ftp://mason.primenet.com.au/pub/rxvt/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		gcw@rxvt.org
HOMEPAGE=		http://www.rxvt.org/
COMMENT=		Low memory usage xterm replacement that supports color

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-utmp \
			--enable-wtmp \
			--enable-lastlog \
			--enable-xpm-background \
			--enable-transparency \
			--enable-menubar \
			--enable-rxvt-scroll \
			--enable-next-scroll \
			--enable-xterm-scroll \
			--enable-xim \
			--enable-ttygid \
			--enable-xgetdefault \
			--enable-frills \
			--enable-linespace \
			--enable-24bit \
			--enable-keepscrolling \
			--enable-mousewheel \
			--enable-slipwheeling \
			--enable-languages \
			--with-encoding=noenc

# Note: greek support could not be enabled, as the resource file handling
# to disable it at runtime is documented but does not seem to work.
# If you want to check if this works, try building with this config
# option:
#
#			--enable-greek
#
# and then map greektoggle_key to "nothing" via app-resources.
# Note: the "AltGR" (Mode shift) key *is* used on most keyboard types
# outside the ASCII-only region for inputing normal characters!

CONFIGURE_ARGS+=	--with-xpm-includes=${BUILDLINK_PREFIX.xpm}/include/X11
CONFIGURE_ARGS+=	--with-xpm-library=${BUILDLINK_PREFIX.xpm}/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "Darwin"
# Make rxvt setuid root so that tty ownership setting and utmp logging
# function correctly.
#
SPECIAL_PERMS=	${PREFIX}/bin/rxvt ${SETUID_ROOT_PERMS}
.endif

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DSunOS
.endif

post-patch:
	${MV} ${WRKSRC}/src/feature.h  ${WRKSRC}/src/feature.h.orig
	${SED} < ${WRKSRC}/src/feature.h.orig > ${WRKSRC}/src/feature.h \
		-e "s:/usr/lib/X11/app-defaults:${X11PREFIX}/lib/X11/app-defaults:"

pre-install:
	if [ ! -f ${X11PREFIX}/lib/X11/app-defaults/Rxvt ]; then \
		${INSTALL_DATA} ${FILESDIR}/Rxvt ${X11PREFIX}/lib/X11/app-defaults; \
	fi

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
