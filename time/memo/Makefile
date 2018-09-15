# $NetBSD: Makefile,v 1.1 2018/09/15 15:14:26 khorben Exp $

GITHUB_PROJECT=	memo
DISTNAME=	0.6
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrVanDalo/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/mrVanDalo/memo/
COMMENT=	A simple memo tool written in bash
LICENSE=	gnu-gpl-v3
WRKSRC=		${WRKDIR}/${PKGNAME}

USE_LANGUAGES=	# none

DEPENDS+=	bash-[0-9]*:../../shells/bash
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

NO_BUILD=	yes
AUTO_MKDIRS=	yes

REPLACE_INTERPRETER+=	envbash
REPLACE.envbash.old=	'/bin/bash'
REPLACE.envbash.new=	${PREFIX}/bin/bash
REPLACE_FILES.envbash=	memo

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL} -m 0755 ${WRKSRC}/memo ${DESTDIR}${PREFIX}/bin/memo
	${INSTALL} -m 0644 ${WRKSRC}/doc/memo.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/memo.1
	${INSTALL} -m 0644 ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/memo/README.md

.include "../../mk/bsd.pkg.mk"
