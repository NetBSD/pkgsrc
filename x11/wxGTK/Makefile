# $NetBSD: Makefile,v 1.20 2003/05/02 11:57:32 wiz Exp $
#

DISTNAME=		wxGTK-2.4.0
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		ftp://biolpc22.york.ac.uk/pub/2.4.0/

MAINTAINER=		tsarna@netbsd.org
HOMEPAGE=		http://www.wxwindows.org
COMMENT=		GTK-based implementation of the wxWindows GUI library

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gtk
CONFIGURE_ARGS+=	--with-libjpeg=sys
CONFIGURE_ARGS+=	--with-zlib=sys
CONFIGURE_ARGS+=	--with-libpng=sys
CONFIGURE_ARGS+=	--with-libtiff=sys

CPPFLAGS+=		-Dunix=1	# src/common/unzip.c needs this

DOCDIR=			${PREFIX}/share/doc/wx/gtk

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
