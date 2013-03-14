# $NetBSD: Makefile,v 1.13 2013/03/14 17:06:12 kim Exp $
#

DISTNAME=		webnew-1.3
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://oss.gw.com/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://kimmo.suominen.com/sw/webnew/
COMMENT=		Retrieve modification times of web documents

USE_TOOLS+=		perl:run

NO_CONFIGURE=		yes
BUILD_TARGET=		all DEST=${PREFIX} PERL=${PERL5}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/webnew ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webnew.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
