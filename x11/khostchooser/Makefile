# $NetBSD: Makefile,v 1.21 2004/01/03 18:49:59 reed Exp $
#

DISTNAME=	khostchooser-0.3
PKGREVISION=	2
WRKSRC=		${WRKDIR}/khostchooser
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.1.2/apps/network/
EXTRACT_SUFX=	.tgz

MAINTAINER=	root@garbled.net
COMMENT=	KDE Chooser replacement for X

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/kde \
		--with-qt-dir=${QTDIR}
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="${KDE_LDFLAGS}"

FIX_RPATH+=	KDE_LDFLAGS
KDE_LDFLAGS=	-L${LOCALBASE}/lib -Wl,${RPATH_FLAG}${LOCALBASE}/lib -L${X11BASE}/lib -Wl,${RPATH_FLAG}${X11BASE}/lib

.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/kdelibs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
