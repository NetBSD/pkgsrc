# $NetBSD: Makefile,v 1.8 1998/04/20 11:56:35 frueauf Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/27 00:25:46 se Exp
#

DISTNAME=	kdelibs-Beta3-1
PKGNAME=	kdelibs-3.1b
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta3/distribution/tgz/source/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt.1.3[0-9]:${PORTSDIR}/x11/qt \
		gif.[23].:${PORTSDIR}/graphics/giflib \
		jpeg.[67].:${PORTSDIR}/graphics/jpeg

USE_X11=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=${PREFIX}" \
		"--x-inc=${X11BASE}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
		"--x-lib=${X11BASE}/lib -L${LOCALBASE}/lib" \
		"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${X11BASE}/include/qt"
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

WRKSRC=		${WRKDIR}/kdelibs

.include "../../mk/bsd.pkg.mk"
