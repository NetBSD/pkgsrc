# $NetBSD: Makefile,v 1.1.1.1 1999/04/01 23:03:38 garbled Exp $
#

DISTNAME=	khostchooser-0.3
CATEGORIES=	x11 kde
MASTER_SITES=	http://stud1.tuwien.ac.at/~e9025461/
EXTRACT_SUFX=	.tgz

MAINTAINER=	root@garbled.net
HOMEPAGE=       http://stud1.tuwien.ac.at/~e9025461/

BUILD_DEPENDS+=	${LOCALBASE}/bin/msgfmt:../../devel/gettext
DEPENDS+=	kdelibs-1.1:../../x11/kdelibs
DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	giflib-3.0:../../graphics/giflib

WRKSRC=		${WRKDIR}/khostchooser

USE_X11BASE=	yes
USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/kde \
		--with-qt-dir=${PREFIX} \
		--with-qt-includes=${PREFIX}/include/qt
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${LOCALBASE}/lib" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../mk/bsd.pkg.mk"
