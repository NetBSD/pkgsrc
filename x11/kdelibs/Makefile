# $NetBSD: Makefile,v 1.61 2002/09/01 04:26:11 hubertf Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/27 00:25:46 se Exp
#

DISTNAME=	kdelibs-1.1.2
PKGREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_LOCAL}/kde1
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=       http://www.kde.org/
COMMENT=	Support libraries for the KDE integrated X11 desktop

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.2.1:../../graphics/png
DEPENDS+=	qt1-1.44:../../x11/qt1
DEPENDS+=	tiff-[0-9]*:../../graphics/tiff

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig
GNU_CONFIGURE=	yes

EVAL_PREFIX+=	QT1DIR=qt1
CONFIGURE_ARGS=	"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${QT1DIR}/qt1"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	"-Wl,-R${QT1DIR}/qt1/lib" \
		"-L${QT1DIR}/qt1/lib"

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -Wl,-R${X11BASE}/lib -L${X11BASE}/lib"

.include "../../mk/bsd.pkg.mk"
