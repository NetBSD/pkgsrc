# $NetBSD: Makefile,v 1.4 2000/11/12 20:36:38 tsarna Exp $
#

DISTNAME=	wxGTK-2.2.2
CATEGORIES=	x11
MASTER_SITES=	ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/source/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.freiburg.linux.de/~wxxt/

DEPENDS+=       gtk+>=1.2.7:../../x11/gtk
DEPENDS+=       jpeg-6b:../../graphics/jpeg
DEPENDS+=       png>=1.0.3:../../graphics/png
DEPENDS+=       tiff>=3.5.2:../../graphics/tiff

WRKSRC=		${WRKDIR}/wxGTK

USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gtk --with-libjpeg=sys --with-zlib=sys --with-libpng=sys --with-libtiff=sys  --disable-threads
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
