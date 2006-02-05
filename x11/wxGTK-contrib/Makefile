# $NetBSD: Makefile,v 1.5 2006/02/05 23:11:44 joerg Exp $
#

.include "../../x11/wxGTK/Makefile.common"

PKGNAME=		${DISTNAME:S/wxGTK/wxGTK-contrib/}
PKGREVISION=		2
MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		GTK-based implementation of the wxWidgets GUI library (contrib libraries)

USE_TOOLS+=		gmake

do-build:
	cd ${WRKSRC}/contrib/src && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS}

do-install:
	cd ${WRKSRC}/contrib/src && ${SETENV} ${MAKE_ENV} ${MAKE} install ${MAKE_FLAGS}

.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
