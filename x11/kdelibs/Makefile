# $NetBSD: Makefile,v 1.29 1999/03/06 00:00:28 tron Exp $
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
CONFIGURE_ARGS=	"--x-inc=${X11BASE}/include -I${LOCALBASE}/include" \
		"--x-lib=${X11BASE}/lib -L${LOCALBASE}/lib" \
		"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

pre-patch:
		@${LN} -s . ${WRKSRC}/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
