# $NetBSD: Makefile,v 1.8 1998/04/20 11:56:35 frueauf Exp $
# FreeBSD Id: Makefile,v 1.6 1997/11/27 00:35:27 se Exp
#

DISTNAME=	kdebase-Beta3-1
PKGNAME=	kdebase-3.1b
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta3/distribution/tgz/source/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt.1.3[0-9]:${PORTSDIR}/x11/qt \
		gif.[23].:${PORTSDIR}/graphics/giflib \
		jpeg.[67].:${PORTSDIR}/graphics/jpeg \
		kdecore.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kdeui.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		jscript.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kfm.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		mediatool.0.9[0-9]:${PORTSDIR}/x11/kdelibs

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
PLIST_DIRS=	${PREFIX}/share/applnk \
		${PREFIX}/share/apps/kappfinder \
		${PREFIX}/share/mimelnk

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@find ${PLIST_DIRS} -type f | \
	    ${SED} "s/${PREFIX:S/\//\\\//g}\///g" >>${PLIST_SRC}
	@find ${PLIST_DIRS} -type d | sort -r | \
	    ${SED} "s/${PREFIX:S/\//\\\//g}\//\@dirrm /g" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
