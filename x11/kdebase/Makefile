# $NetBSD: Makefile,v 1.11 1998/04/28 22:53:23 tron Exp $
# FreeBSD Id: Makefile,v 1.6 1997/11/27 00:35:27 se Exp
#

DISTNAME=	kdebase-beta4-1
PKGNAME=	kdebase-4.1b
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.appl-opt.physik.uni-essen.de/pub/linux/kde/stable/Beta4/distribution/tgz/source/ \
		ftp://ftp.net.lut.ac.uk/kde/stable/Beta4/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta4/distribution/tgz/source/
EXTRACT_SUFX=	.src.tar.bz2

MAINTAINER=	tron@netbsd.org

BUILD_DEPENDS=	bzip2:../../archivers/bzip2 \
		moc:../../x11/qt
DEPENDS+=	giflib-3.0:../../graphics/giflib
DEPENDS+=	jpeg-6a:../../graphics/jpeg
DEPENDS+=	qt-1.33:../../x11/qt
DEPENDS+=	kdelibs-4.1b:../../x11/kdelibs

EXTRACT_CMD=		bzip2
EXTRACT_BEFORE_ARGS=	-d <
EXTRACT_AFTER_ARGS=	| pax -r

USE_X11=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=${PREFIX}" \
		"--x-inc=${PREFIX}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
		"--x-lib=${PREFIX}/lib -L${LOCALBASE}/lib" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

WRKSRC=		${WRKDIR}/kdebase

PLIST_SRC=	${WRKDIR}/PLIST.tmp
PLIST_DIRS=	share/applnk share/apps/kappfinder share/icons share/mimelnk

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${PREFIX}; find ${PLIST_DIRS} -type f >>${PLIST_SRC})
	@(cd ${PREFIX}; find ${PLIST_DIRS} -type d | sort -r | \
	    ${SED} "s/^/\@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
