# $NetBSD: Makefile,v 1.19 2007/01/07 09:14:14 rillig Exp $
#

DISTNAME=	blackbox-0.65.0
PKGNAME=	bsetroot-0.1
PKGREVISION=	6
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blackboxwm/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://blackboxwm.sourceforge.net/
COMMENT=	Tools to set the root windows background

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

BUILD_DIRS=	${WRKSRC}/nls ${WRKSRC}/util

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/util/bsetbg ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/bsetroot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/bsetbg.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bsetroot.1 ${PREFIX}/${PKGMANDIR}/man1
	( cd ${WRKSRC}/nls && ${MAKE} install )

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
