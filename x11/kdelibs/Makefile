# $NetBSD: Makefile,v 1.31 1999/03/23 17:47:59 tron Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/27 00:25:46 se Exp
#

DISTNAME=	kdelibs-1.1
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.1/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.1/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2
PATCH_SITES=	ftp://ftp.kde.org/pub/kde/security_patches/ \
		ftp://ftp.de.kde.org/pub/kde/security_patches/
PATCHFILES=	kdelibs-1.1-connect.patch

MAINTAINER=	tron@netbsd.org
HOMEPAGE=       http://www.kde.org/

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=	qt-1.42:../../x11/qt
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
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${LOCALBASE}/lib"

pre-patch:
		@${LN} -s . ${WRKSRC}/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
