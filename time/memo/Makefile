# $NetBSD: Makefile,v 1.3 2018/09/15 16:17:10 khorben Exp $

GITHUB_PROJECT=	memo
DISTNAME=	0.6
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrVanDalo/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/mrVanDalo/memo/
COMMENT=	A simple memo tool written in bash
LICENSE=	gnu-gpl-v3
WRKSRC=		${WRKDIR}/memo-${DISTNAME}

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
