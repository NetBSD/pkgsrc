# $NetBSD: Makefile,v 1.36 2003/03/27 07:37:42 wiz Exp $
# FreeBSD Id: Makefile,v 1.13 1997/03/07 12:29:49 obrien Exp
#

DISTNAME=		rxvt-2.7.10
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.rxvt.org/pub/rxvt/ \
			ftp://mason.primenet.com.au/pub/rxvt/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		gcw@rxvt.org
HOMEPAGE=		http://www.rxvt.org/
COMMENT=		Low memory usage xterm replacement that supports color

USE_BUILDLINK2=		YES
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
			--enable-greek \
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

CONFIGURE_ARGS+=	--with-xpm-includes=${BUILDLINK_PREFIX.xpm}/include/X11
CONFIGURE_ARGS+=	--with-xpm-library=${BUILDLINK_PREFIX.xpm}/lib

post-patch:
	${MV} ${WRKSRC}/src/feature.h  ${WRKSRC}/src/feature.h.orig
	${SED} < ${WRKSRC}/src/feature.h.orig > ${WRKSRC}/src/feature.h \
		-e "s:/usr/lib/X11/app-defaults:${X11PREFIX}/lib/X11/app-defaults:"

pre-install:
	if [ ! -f ${X11PREFIX}/lib/X11/app-defaults/Rxvt ]; then \
		${INSTALL_DATA} ${FILESDIR}/Rxvt ${X11PREFIX}/lib/X11/app-defaults; \
	fi

.include "../../mk/bsd.prefs.mk"

post-install:
.if ${OPSYS} == "NetBSD"
	# Make rxvt setuid root so that utmp logging functions correctly.
	#
	${CHOWN} 0 ${PREFIX}/bin/rxvt
	${CHMOD} 4711 ${PREFIX}/bin/rxvt
.endif

.if ${OPSYS} == "SunOS"
CFLAGS+= -DSunOS
.endif

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
