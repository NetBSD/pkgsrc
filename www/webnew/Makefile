# $NetBSD: Makefile,v 1.28 2023/12/21 02:55:37 zafer Exp $

DISTNAME=		webnew-1.3
PKGREVISION=		11
CATEGORIES=		www
MASTER_SITES=		https://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://kimmo.suominen.com/sw/webnew/
COMMENT=		Retrieve modification times of web documents

USE_TOOLS+=		perl:run

NO_CONFIGURE=		yes
BUILD_TARGET=		all
MAKE_FLAGS=		DEST=${PREFIX} PERL=${PERL5}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

DEPENDS+=		p5-ParallelUserAgent-[0-9]*:../../www/p5-ParallelUserAgent

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/webnew ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webnew.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
