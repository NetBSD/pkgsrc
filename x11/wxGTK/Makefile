# $NetBSD: Makefile,v 1.5 2000/12/12 18:09:57 jlam Exp $
#

DISTNAME=		wxGTK-2.2.3
WRKSRC=			${WRKDIR}/wxGTK
CATEGORIES=		x11
MASTER_SITES=		ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/source/

MAINTAINER=		tsarna@netbsd.org
HOMEPAGE=		http://www.freiburg.linux.de/~wxxt/

DEPENDS+=		gtk+>=1.2.7:../../x11/gtk
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png>=1.0.3:../../graphics/png
DEPENDS+=		tiff>=3.5.2:../../graphics/tiff

USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-gtk
CONFIGURE_ARGS+=	--with-libjpeg=sys
CONFIGURE_ARGS+=	--with-zlib=sys
CONFIGURE_ARGS+=	--with-libpng=sys
CONFIGURE_ARGS+=	--with-libtiff=sys
CONFIGURE_ARGS+=	--disable-threads
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include

DOCDIR=			${PREFIX}/share/doc/wx/gtk

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE
	${INSTALL_DATA} ${WRKSRC}/SYMBOLS.txt ${DOCDIR}/SYMBOLS

.include "../../mk/bsd.pkg.mk"
