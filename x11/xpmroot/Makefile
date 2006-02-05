# $NetBSD: Makefile,v 1.48 2006/02/05 23:11:49 joerg Exp $
#

DISTNAME=       fvwm-${PKG_VERSION}
PKGNAME=	xpmroot-${PKG_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=   ftp://ftp.fvwm.org/pub/fvwm/version-2/ \
		ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.fvwm.org/generated/manpages/xpmroot.html
COMMENT=	Sets the root window to an Xpm pixmap

PKG_VERSION=	2.4.19
USE_X11BASE=	YES
GNU_CONFIGURE=	YES

MAKE_ENV+=	VERSION=${PKG_VERSION:Q}
CONFIGURE_ARGS+=	--without-extras --disable-dmalloc --without-gnome

INSTALLATION_DIRS=	bin man/man1

do-build:
	@(cd ${WRKSRC}/libs && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} all)
	@(cd ${WRKSRC}/utils && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} xpmroot)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/xpmroot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/utils/xpmroot.1 ${PREFIX}/man/man1

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
