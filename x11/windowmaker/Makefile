# $NetBSD: Makefile,v 1.15 1998/11/26 19:16:29 tron Exp $

DISTNAME=		WindowMaker-0.20.2
PKGNAME=		windowmaker-0.20.2
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/beta/srcs/ \
			ftp://ftp.windowmaker.org/pub/contrib/icons/
DISTFILES+=		${DISTNAME}${EXTRACT_SUFX}\
			WindowMaker-data.tar.gz

MAINTAINER=		magick@bundy.lip.owl.de
HOMEPAGE=		http://windowmaker.org/

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		giflib-3.0:../../graphics/giflib
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png-1.0.2:../../graphics/png
DEPENDS+=		tiff-3.4:../../graphics/tiff

CONFIGURE_ENV+=		INSTALL="${INSTALL}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_DATA="${INSTALL_DATA}" \
			INSTALL_SCRIPT="${INSTALL_SCRIPT}"

CONFLICTS=		windowmaker-0.6.3 windowmaker-0.16.1

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-nlsdir=${PREFIX}/share/locale \
			--with-gfx-incs="-I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
			--with-gfx-libs=-L${LOCALBASE}/lib

post-install:
	(cd ${WRKDIR}/WindowMaker-data/pixmaps/ ; for i in * ; do \
	 ${INSTALL_DATA} $$i ${PREFIX}/share/WindowMaker/Pixmaps/ ; \
	 done )
	${INSTALL_DATA_DIR} ${PREFIX}/share/WindowMaker/Sounds
	${TOUCH} ${PREFIX}/share/WindowMaker/Sounds/.keep_me

.include "../../mk/bsd.pkg.mk"
