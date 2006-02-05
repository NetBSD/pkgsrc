# $NetBSD: Makefile,v 1.5 2006/02/05 23:11:11 joerg Exp $
#

DISTNAME=		xchrono
PKGNAME=		xchrono-19900813
PKGREVISION=		1
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
