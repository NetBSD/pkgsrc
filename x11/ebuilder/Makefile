# $NetBSD: Makefile,v 1.21 2004/04/12 02:11:14 snj Exp $
#

DISTNAME=	ebuilder-0.56d
PKGREVISION=	1
CATEGORIES=	x11 devel
MASTER_SITES=	http://web.inter.nl.net/users/eavdmeer/src/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://web.inter.nl.net/users/eavdmeer/index.html
COMMENT=	GUI builder for the Qt library

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_BUILDLINK3=	yes
USE_X11=	yes
USE_GNU_TOOLS+=	make
MAKEFILE=	GNUmakefile

MAKE_ENV+=	CXXFLAGS="${CXXFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ebuilder ${PREFIX}/bin

.include "../../x11/qt2-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
