# $NetBSD: Makefile,v 1.53 2000/08/15 23:20:51 hubertf Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/27 00:25:46 se Exp
#

DISTNAME=	kdelibs-1.1.2
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=       http://www.kde.org/

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.6:../../graphics/png
DEPENDS+=	qt1-1.44:../../x11/qt1
DEPENDS+=	tiff-*:../../graphics/tiff

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

EVAL_PREFIX+=	QT1DIR=qt1
CONFIGURE_ARGS=	"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${QT1DIR}/qt1"
CFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -Wl,-R${X11BASE}/lib -L${X11BASE}/lib"

.include "../../mk/bsd.pkg.mk"
