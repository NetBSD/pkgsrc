# $NetBSD: Makefile,v 1.2 2003/06/02 01:16:17 jschauma Exp $
#

DISTNAME=		xchrono
PKGNAME=		xchrono-19900813
CATEGORIES=		time x11
MASTER_SITES=		http://www.mit.edu/afs/athena/contrib/softbone/source/src/xchrono/
EXTRACT_SUFX=		.shar

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://infoshako.sk.tsukuba.ac.jp/jdoc/X-utilities/xchrono
COMMENT=		multi-timezone X11-based clock

USE_IMAKE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xchrono
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchrono/

.include "../../mk/bsd.pkg.mk"
