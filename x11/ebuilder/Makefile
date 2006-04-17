# $NetBSD: Makefile,v 1.31 2006/04/17 13:46:52 wiz Exp $
#

DISTNAME=	ebuilder-0.56d
PKGREVISION=	5
CATEGORIES=	x11 devel
MASTER_SITES=	http://web.inter.nl.net/users/eavdmeer/src/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://web.inter.nl.net/users/eavdmeer/index.html
COMMENT=	GUI builder for the Qt library

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	flex gmake
MAKEFILE=	GNUmakefile

MAKE_ENV+=	CXXFLAGS=${CXXFLAGS:M*:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ebuilder ${PREFIX}/bin

.include "../../x11/qt2-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
