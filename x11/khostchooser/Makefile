# $NetBSD: Makefile,v 1.5 2000/04/13 00:20:38 dmcmahill Exp $
#

DISTNAME=	khostchooser-0.3
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.1.2/apps/network/
EXTRACT_SUFX=	.tgz

MAINTAINER=	root@garbled.net

BUILD_DEPENDS+=	${LOCALBASE}/bin/msgfmt:../../devel/gettext
DEPENDS+=	kdelibs-1.1.2:../../x11/kdelibs
DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	libungif-*:../../graphics/libungif

WRKSRC=		${WRKDIR}/khostchooser

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/kde \
		--with-qt-dir=${X11BASE}/qt1 
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		QTDIR=${X11BASE}/qt1 \
		MOC=${X11BASE}/qt1/bin/moc \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -Wl,-R${X11BASE}/lib -L${X11BASE}/lib"

.include "../../mk/bsd.pkg.mk"
