# $NetBSD: Makefile,v 1.4 2018/09/15 16:25:22 khorben Exp $

DISTNAME=	memo-0.6
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrVanDalo/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/mrVanDalo/memo/
COMMENT=	A simple memo tool written in bash
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

NO_BUILD=	yes
INSTALLATION_DIRS=	bin share/doc/memo

REPLACE_BASH+=	memo

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/memo ${DESTDIR}${PREFIX}/bin/memo
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/memo.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/memo.1
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/memo/README.md

.include "../../mk/bsd.pkg.mk"
