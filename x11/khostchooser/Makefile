# $NetBSD: Makefile,v 1.18 2002/10/21 13:48:54 wiz Exp $
#

DISTNAME=	khostchooser-0.3
PKGREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.1.2/apps/network/
EXTRACT_SUFX=	.tgz

MAINTAINER=	root@garbled.net
COMMENT=	KDE Chooser replacement for X

BUILD_USES_MSGFMT=	yes

WRKSRC=		${WRKDIR}/khostchooser

USE_BUILDLINK2=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/kde \
		--with-qt-dir=${QTDIR}
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -Wl,-R${X11BASE}/lib -L${X11BASE}/lib"

.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/kdelibs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
