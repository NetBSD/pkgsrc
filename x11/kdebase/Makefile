# $NetBSD: Makefile,v 1.30 1999/02/18 23:37:54 tron Exp $
# FreeBSD Id: Makefile,v 1.6 1997/11/27 00:35:27 se Exp
#

DISTNAME=	kdebase-1.1
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.1/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.1/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=       http://www.kde.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/msgfmt:../../devel/gettext
DEPENDS+=	Mesa-3.0:../../graphics/Mesa
DEPENDS+=	kdelibs-1.1:../../x11/kdelibs
DEPENDS+=	xpm-3.4k:../../graphics/xpm

CONFLICTS=	kdebase-*

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--x-inc=${PREFIX}/include -I${LOCALBASE}/include" \
		"--x-lib=${PREFIX}/lib -L${LOCALBASE}/lib" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

PLIST_SRC=	${WRKDIR}/PLIST
PLIST_DIRS=	share/kde/applnk share/kde/apps/kappfinder share/kde/icons \
		share/kde/mimelnk

post-install:
	@${MKDIR} ${PREFIX}/share/doc/kde/HTML/it
	@${MKDIR} ${PREFIX}/share/kde/sounds
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${PREFIX}; find ${PLIST_DIRS} -type f >>${PLIST_SRC})
	@(cd ${PREFIX}; find ${PLIST_DIRS} -type d | sort -r | \
	    ${SED} "s/^/\@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
