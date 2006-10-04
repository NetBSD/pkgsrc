# $NetBSD: Makefile,v 1.7 2006/10/04 22:04:10 wiz Exp $
#

DISTNAME=		webnew-1.3
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://kimmo.suominen.com/webnew/
COMMENT=		Retrieve modification times of web documents

USE_TOOLS+=		perl:run

NO_CONFIGURE=		yes
BUILD_TARGET=		all DEST=${PREFIX} PERL=${PERL5}

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/webnew ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webnew.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
