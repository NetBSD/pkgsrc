# $NetBSD: Makefile,v 1.31 2004/04/27 21:59:24 dmcmahill Exp $
#

DISTNAME=		wxGTK-2.4.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wxwindows/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tsarna@NetBSD.org
HOMEPAGE=		http://www.wxwindows.org/
COMMENT=		GTK-based implementation of the wxWindows GUI library

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-opengl
CONFIGURE_ARGS+=	--with-libjpeg=sys
CONFIGURE_ARGS+=	--with-zlib=sys
CONFIGURE_ARGS+=	--with-libpng=sys
CONFIGURE_ARGS+=	--with-libtiff=sys
CONFIGURE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}

CPPFLAGS+=		-Dunix=1	# src/common/unzip.c needs this

DOCDIR=			${PREFIX}/share/doc/wx/gtk

.include "../../mk/bsd.prefs.mk"

.if !empty(WXGTK_USE_GTK1:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUBST+=		GTKVER=
.include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-gtk2
PLIST_SUBST+=		GTKVER=2
.include "../../x11/gtk2/buildlink3.mk"
.endif

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
