# $NetBSD: Makefile,v 1.19 2004/01/20 12:28:26 agc Exp $
#

DISTNAME=	ebuilder-0.56d
PKGREVISION=	1
CATEGORIES=	x11 devel
MASTER_SITES=	http://web.inter.nl.net/users/eavdmeer/src/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://web.inter.nl.net/users/eavdmeer/index.html
COMMENT=	GUI builder for the Qt library

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_BUILDLINK2=	yes
USE_X11=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

MAKE_ENV+=	CXXFLAGS="${CXXFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ebuilder ${PREFIX}/bin

.include "../../x11/qt2-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
