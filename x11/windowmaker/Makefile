# $NetBSD: Makefile,v 1.14 1998/08/20 15:17:38 tsarna Exp $

DISTNAME=		WindowMaker-0.16.1
PKGNAME=		windowmaker-0.16.1
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/beta/srcs/ \
			ftp://ftp.windowmaker.org/pub/contrib/icons/
DISTFILES+=		${DISTNAME}${EXTRACT_SUFX}\
			WindowMaker-data.tar.gz

MAINTAINER=		magick@bundy.lip.owl.de
HOMEPAGE=		http://windowmaker.org/

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png-1.0.2:../../graphics/png
DEPENDS+=		tiff-3.4:../../graphics/tiff
BUILD_DEPENDS=		bison:../../devel/bison
#libPropList needs bison for the parser. Yacc runs through, but WMaker crashes
#afterwards

CONFIGURE_ENV+=		INSTALL="${INSTALL}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_DATA="${INSTALL_DATA}" \
			INSTALL_SCRIPT="${INSTALL_SCRIPT}"

CONFLICTS=		windowmaker-0.6.3

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gfx-incs=-I${LOCALBASE}/include \
			--with-gfx-libs=-L${LOCALBASE}/lib \

pre-configure:
	@(cd ${WRKSRC} && tar xvzf libPropList.tar.gz && cd libPropList && \
	 ./configure && ${MAKE})

post-install:
	(cd ${WRKDIR}/WindowMaker-data/pixmaps/ ; for i in * ; do \
	 ${INSTALL_DATA} $$i ${PREFIX}/share/WindowMaker/Pixmaps/ ; \
	 done )

.include "../../mk/bsd.pkg.mk"
