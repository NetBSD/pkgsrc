# $NetBSD: Makefile,v 1.10 2003/09/17 19:41:14 grant Exp $
#

DISTNAME=	blackbox-0.65.0
PKGNAME=	bsetroot-0.1
PKGREVISION=	4
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blackboxwm/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://blackboxwm.sourceforge.net/
COMMENT=	Tools to set the root windows background

USE_BUILDLINK2=	YES
USE_GCC_SHLIB=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

BUILD_DIRS=	${WRKSRC}/nls ${WRKSRC}/util

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/util/bsetbg ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/bsetroot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/bsetbg.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bsetroot.1 ${PREFIX}/man/man1
	( cd ${WRKSRC}/nls && ${MAKE} install )

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
