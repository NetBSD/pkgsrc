# $NetBSD: Makefile,v 1.36 1999/07/09 23:38:40 tron Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/27 00:25:46 se Exp
#

DISTNAME=	kdelibs-1.1.1
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.1.1/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.1.1/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=       http://www.kde.org/

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=	qt-1.44:../../x11/qt
DEPENDS+=	tiff-3.4:../../graphics/tiff

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOL_FLAGS=	--cplusplus --install-la
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
CFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.prefs.mk"

.if (${OBJECT_FMT} == "a.out") && (${MACHINE_ARCH} == "sparc")
CFLAGS+=	-static
PLIST_SRC=	${WRKDIR}/PLIST

post-install:
	@${GREP} -v ^lib/lib.*\.so ${PKGDIR}/PLIST >${PLIST_SRC}
.endif

CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}" all_libraries="-L${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
