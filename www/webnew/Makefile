# $NetBSD: Makefile,v 1.3 2003/07/22 04:14:39 martti Exp $
#

DISTNAME=		webnew-1.3
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.tac.nyc.ny.us/kim/webnew/
COMMENT=		Retrieve modification times of web documents

USE_PERL5=		# defined

NO_CONFIGURE=		yes
ALL_TARGET=		all DEST=${PREFIX} PERL=${PERL5}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/webnew ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webnew.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
