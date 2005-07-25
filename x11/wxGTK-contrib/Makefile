# $NetBSD: Makefile,v 1.1.1.1 2005/07/25 20:26:55 wiz Exp $
#

.include "../../x11/wxGTK/Makefile.common"

PKGNAME=		${DISTNAME:S/wxGTK/wxGTK-contrib/}
MAINTAINER=		dotz@irc.pl
COMMENT=		GTK-based implementation of the wxWidgets GUI library (contrib libraries)

MAKE_ENV+=		INSTALL_DATA_DIR="${INSTALL_DATA_DIR}"
MAKE_ENV+=		LIBTOOL=${LOCALBASE}/bin/libtool
USE_TOOLS+=		gmake

do-build:
	cd ${WRKSRC}/contrib/src && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS}

do-install:
	cd ${WRKSRC}/contrib/src && ${SETENV} ${MAKE_ENV} ${MAKE} install ${MAKE_FLAGS}

.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
