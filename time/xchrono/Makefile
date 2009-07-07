# $NetBSD: Makefile,v 1.10 2009/07/07 19:52:35 joerg Exp $
#

DISTNAME=		xchrono
PKGNAME=		xchrono-19900813
PKGREVISION=		2
CATEGORIES=		time x11
MASTER_SITES=		http://www.mit.edu/afs/athena/contrib/softbone/source/src/xchrono/
EXTRACT_SUFX=		.shar

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Multi-timezone X11-based clock

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=		yes

INSTALLATION_DIRS=	share/doc/xchrono

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xchrono/

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
