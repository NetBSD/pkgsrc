# $NetBSD: Makefile,v 1.46 2025/01/27 18:59:09 rillig Exp $

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-lib-3.2.1
PKGREVISION=		11
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		OpenLook Toolkit libs, includes, and man pages
LICENSE=		sun-openlook-license

MAKE_JOBS_SAFE=		no

# Not functional without fundamental images from font-sun-misc.
DEPENDS+=		font-sun-misc>=1.0.3:../../fonts/font-sun-misc
DEPENDS+=		xview-config>=3.2.1nb6:../../x11/xview-config

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
# Builds, but binaries in ../xview-clients all crash. Broken va_arg handling.
BROKEN_ON_PLATFORM=	${LP64PLATFORMS}

USE_IMAKE=		yes

post-install:
	cd ${DESTDIR}${PREFIX}/lib && ${LN} -fs libolgx.so.3.2 libolgx.so.3 && \
		${LN} -fs libxview.so.3.2 libxview.so.3

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
