# $NetBSD: Makefile,v 1.22 1998/09/30 20:05:30 tron Exp $
# FreeBSD Id: Makefile,v 1.6 1997/11/27 00:35:27 se Exp
#

DISTNAME=	kdebase-1.0
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=       http://www.kde.org/

DEPENDS+=	Mesa-3.0:../../graphics/Mesa
DEPENDS+=	giflib-3.0:../../graphics/giflib
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	qt-1.40:../../x11/qt
DEPENDS+=	kdelibs-1.0:../../x11/kdelibs

CONFLICTS=	kdebase-2.1b kdebase-3.1b kdebase-4.1b

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--x-inc=${PREFIX}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
		"--x-lib=${PREFIX}/lib -L${LOCALBASE}/lib" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

PLIST_SRC=	${WRKDIR}/PLIST
PLIST_DIRS=	share/applnk share/apps/kappfinder share/icons share/mimelnk

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${PREFIX}; find ${PLIST_DIRS} -type f >>${PLIST_SRC})
	@(cd ${PREFIX}; find ${PLIST_DIRS} -type d | sort -r | \
	    ${SED} "s/^/\@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
