# $NetBSD: Makefile,v 1.4 2003/07/21 17:28:47 martti Exp $
#

DISTNAME=		xchrono
PKGNAME=		xchrono-19900813
CATEGORIES=		time x11
MASTER_SITES=		http://www.mit.edu/afs/athena/contrib/softbone/source/src/xchrono/
EXTRACT_SUFX=		.shar

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://infoshako.sk.tsukuba.ac.jp/jdoc/X-utilities/xchrono
COMMENT=		Multi-timezone X11-based clock

USE_IMAKE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xchrono
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchrono/

.include "../../mk/bsd.pkg.mk"
