# $NetBSD: Makefile,v 1.44 2022/04/17 01:44:23 gutteridge Exp $

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-lib-3.2.1
PKGREVISION=		11
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		OpenLook Toolkit libs, includes, and man pages

MAKE_JOBS_SAFE=		no

# Not functional without fundamental images from font-sun-misc.
DEPENDS+=		font-sun-misc>=1.0.3:../../fonts/font-sun-misc
DEPENDS+=		xview-config>=3.2.1nb6:../../x11/xview-config

LICENSE=		sun-openlook-license
NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
# builds, but binaries in../xview-clients all crash
NOT_FOR_PLATFORM=	*-*-alpha
NOT_FOR_PLATFORM+=	Linux-*-*

USE_IMAKE=		yes

post-install:
	cd ${DESTDIR}${PREFIX}/lib && ${LN} -fs libolgx.so.3.2 libolgx.so.3 && \
		${LN} -fs libxview.so.3.2 libxview.so.3

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
