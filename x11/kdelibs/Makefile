# $NetBSD: Makefile,v 1.22 1998/11/06 05:15:42 mycroft Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/27 00:25:46 se Exp
#

DISTNAME=	kdelibs-1.0
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=       http://www.kde.org/

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	qt-1.41:../../x11/qt
DEPENDS+=	giflib-3.0:../../graphics/giflib

CONFLICTS=	kdelibs-2.1b kdelibs-3.1b kdelibs-4.1b

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--x-inc=${X11BASE}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
		"--x-lib=${X11BASE}/lib -L${LOCALBASE}/lib" \
		"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
USE_LIBTOOL=	yes
LIBTOOL_FLAGS=	 --install-la
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

.include "../../mk/bsd.pkg.mk"
