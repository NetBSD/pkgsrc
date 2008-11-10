# $NetBSD: Makefile,v 1.8 2008/11/10 17:21:38 wiz Exp $
#

DISTNAME=		xchrono
PKGNAME=		xchrono-19900813
PKGREVISION=		2
CATEGORIES=		time x11
MASTER_SITES=		http://www.mit.edu/afs/athena/contrib/softbone/source/src/xchrono/
EXTRACT_SUFX=		.shar

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://infoshako.sk.tsukuba.ac.jp/jdoc/X-utilities/xchrono
COMMENT=		Multi-timezone X11-based clock

USE_IMAKE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xchrono
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchrono/

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
