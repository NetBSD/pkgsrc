# $NetBSD: Makefile,v 1.18 1998/08/19 15:25:51 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/27 00:25:46 se Exp
#

DISTNAME=	kdelibs-1.0
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/ \
		ftp://ftp.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/

MAINTAINER=	tron@netbsd.org

BUILD_DEPENDS=	${LOCALBASE}/bin/libtool:../../devel/libtool
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	qt-1.40:../../x11/qt
DEPENDS+=	giflib-3.0:../../graphics/giflib

CONFLICTS=	kdelibs-2.1b kdelibs-3.1b kdelibs-4.1b

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--x-inc=${X11BASE}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
		"--x-lib=${X11BASE}/lib -L${LOCALBASE}/lib" \
		"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
LIBTOOL_FLAGS=	 --install-la
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

.include "../../mk/bsd.pkg.mk"
