# $NetBSD: Makefile,v 1.17 2003/03/31 17:44:21 jmmv Exp $
#

DISTNAME=		wxGTK-2.4.0
CATEGORIES=		x11
MASTER_SITES=		ftp://biolpc22.york.ac.uk/pub/2.4.0/

MAINTAINER=		tsarna@netbsd.org
HOMEPAGE=		http://www.wxwindows.org
COMMENT=		GTK-based implementation of the wxWindows GUI library

USE_BUILDLINK2=		# defined
USE_PKGLOCALEDIR=	# defined
USE_X11=		# defined
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

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
