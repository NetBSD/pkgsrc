# $NetBSD: Makefile,v 1.12 1998/07/04 05:11:15 mycroft Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/27 00:25:46 se Exp
#

DISTNAME=	kdelibs-beta4-1
PKGNAME=	kdelibs-4.1b
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.appl-opt.physik.uni-essen.de/pub/linux/kde/stable/Beta4/distribution/tgz/source/ \
		ftp://ftp.net.lut.ac.uk/kde/stable/Beta4/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta4/distribution/tgz/source/
EXTRACT_SUFX=	.src.tar.bz2

MAINTAINER=	tron@netbsd.org

BUILD_DEPENDS=	bzip2:../../archivers/bzip2 \
		moc:../../x11/qt
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	qt-1.33:../../x11/qt
DEPENDS+=	giflib-3.0:../../graphics/giflib

EXTRACT_CMD=		bzip2
EXTRACT_BEFORE_ARGS=	-d <
EXTRACT_AFTER_ARGS=	| pax -r

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
