# $NetBSD: Makefile,v 1.58 2008/01/03 23:19:17 heinz Exp $
#

DISTNAME=	fvwm-${PKG_VERSION}
PKGNAME=	xpmroot-${PKG_VERSION}
#PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.fvwm.org/documentation/manpages/stable/xpmroot.php
COMMENT=	Sets the root window to an Xpm pixmap
#LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_PROGRAM} ${WRKSRC:Q}/utils/xpmroot ${DESTDIR}${PREFIX:Q}/bin
	${INSTALL_MAN} ${WRKSRC:Q}/utils/xpmroot.1 \
		${DESTDIR}${PREFIX:Q}/${PKGMANDIR:Q}/man1

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
