# $NetBSD: Makefile,v 1.23 2001/12/17 06:30:20 martti Exp $
#

DISTNAME=       fvwm-${PKG_VERSION}
PKGNAME=	xpmroot-${PKG_VERSION}
CATEGORIES=	x11
MASTER_SITES=   ftp://ftp.fvwm.org/pub/fvwm/version-2/ \
		ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fvwm.org/generated/manpages/xpmroot.html
COMMENT=	Sets the root window to an Xpm pixmap

PKG_VERSION=		2.4.4
USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

MAKE_ENV+=	INSTALL_PROGRAM='${INSTALL_PROGRAM}'
MAKE_ENV+=	INSTALL_MAN='${INSTALL_MAN}'
MAKE_ENV+=	VERSION=${PKG_VERSION}
CONFIGURE_ARGS+=	--without-extras --disable-dmalloc --without-gnome

do-build:
	@(cd ${WRKSRC}/libs && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} all)
	@(cd ${WRKSRC}/utils && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} xpmroot)

do-install:
	${INSTALL_PROGRAM}	${WRKSRC}/utils/xpmroot	${PREFIX}/bin
	${INSTALL_MAN}		${WRKSRC}/utils/xpmroot.1 ${PREFIX}/man/man1

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
