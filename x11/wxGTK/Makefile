# $NetBSD: Makefile,v 1.13 2001/12/08 11:36:26 jmc Exp $
#

DISTNAME=		wxGTK-2.2.7
CATEGORIES=		x11
MASTER_SITES=		ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/source/

MAINTAINER=		tsarna@netbsd.org
HOMEPAGE=		http://www.freiburg.linux.de/~wxxt/
COMMENT=		GTK-based implementation of the wxWindows GUI library

USE_BUILDLINK_ONLY=	# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-gtk
CONFIGURE_ARGS+=	--with-libjpeg=sys
CONFIGURE_ARGS+=	--with-zlib=sys
CONFIGURE_ARGS+=	--with-libpng=sys
CONFIGURE_ARGS+=	--with-libtiff=sys
CONFIGURE_ARGS+=	--disable-threads

MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
CPPFLAGS+=		-Dunix=1	# src/common/unzip.c needs this

DOCDIR=			${PREFIX}/share/doc/wx/gtk

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE
	${INSTALL_DATA} ${WRKSRC}/SYMBOLS.txt ${DOCDIR}/SYMBOLS

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
