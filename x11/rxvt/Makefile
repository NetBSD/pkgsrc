# $NetBSD: Makefile,v 1.27 2001/08/29 22:41:30 jlam Exp $
# FreeBSD Id: Makefile,v 1.13 1997/03/07 12:29:49 obrien Exp
#

DISTNAME=		rxvt-2.7.3
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.rxvt.org/pub/rxvt/ \
			ftp://ftp.rxvt.org/pub/rxvt/devel/ \
			ftp://mason.primenet.com.au/pub/rxvt/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		gcw@rxvt.org
HOMEPAGE=		http://www.rxvt.org/
COMMENT=		Low memory usage xterm replacement that supports color

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
MESSAGE_SUBST+=		X11BASE="${X11BASE}"

CONFIGURE_ARGS+=	--enable-utmp \
			--enable-wtmp \
			--enable-lastlog \
			--enable-xpm-background \
			--enable-transparency \
			--enable-menubar \
			--enable-xterm-scroll \
			--enable-xim \
			--enable-ttygid \
			--enable-xgetdefault \
			--enable-frills \
			--enable-keepscrolling \
			--enable-mousewheel \
			--enable-languages \
			--with-encoding=noenc

# Note: greek support could not be enabled, as the resource file handling
# to disable it at runtime is documented but not implemented in the current
# version. See files/Rxvt and check if it works for newer versions. When
# enabling it, please fix pkg/MESSAGE as well.
#			--enable-greek

CONFIGURE_ARGS+=	--with-xpm-includes=${BUILDLINK_DIR}/include/X11
CONFIGURE_ARGS+=	--with-xpm-library=${BUILDLINK_DIR}/lib

post-patch:
	${MV} ${WRKSRC}/src/feature.h  ${WRKSRC}/src/feature.h.orig
	${SED} < ${WRKSRC}/src/feature.h.orig > ${WRKSRC}/src/feature.h \
		-e "s:/usr/lib/X11/app-defaults:${X11BASE}/lib/X11/app-defaults:"

pre-install:
	if [ ! -f ${X11BASE}/lib/X11/app-defaults/Rxvt ]; then \
		${INSTALL_DATA} ${FILESDIR}/Rxvt ${X11BASE}/lib/X11/app-defaults; \
	fi

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
