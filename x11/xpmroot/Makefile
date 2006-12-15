# $NetBSD: Makefile,v 1.52 2006/12/15 20:33:06 joerg Exp $
#

DISTNAME=	fvwm-${PKG_VERSION}
PKGNAME=	xpmroot-${PKG_VERSION}
#PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/ \
		ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.fvwm.org/generated/manpages/xpmroot.html
COMMENT=	Sets the root window to an Xpm pixmap

PKG_VERSION=	2.4.20
USE_X11BASE=	YES
GNU_CONFIGURE=	YES

MAKE_ENV+=	VERSION=${PKG_VERSION:Q}
CONFIGURE_ARGS+=	--without-extras --disable-dmalloc --without-gnome

INSTALLATION_DIRS=	bin ${PKGMANDIR:Q}/man1

do-build:
	(cd ${WRKSRC:Q}/libs && \
		env ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} all)
	(cd ${WRKSRC:Q}/utils && \
		env ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} xpmroot)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/utils/xpmroot ${PREFIX:Q}/bin
	${INSTALL_MAN} ${WRKSRC:Q}/utils/xpmroot.1 \
		${PREFIX:Q}/${PKGMANDIR:Q}/man1

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
