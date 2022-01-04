# $NetBSD: Makefile,v 1.2 2022/01/04 22:35:24 schmonz Exp $

GITHUB_PROJECT=		httpfile
GITHUB_TAG=		20220101
DISTNAME=		${GITHUB_PROJECT}
PKGNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=janmojzis/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://mojzis.com/software/httpfile/
COMMENT=		Secure HTTP server derived from publicfile
LICENSE=		djb-nonlicense

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

TEST_TARGET=		rts

do-install:
	cd ${WRKSRC}; \
	${INSTALL_PROGRAM} httpfile ${DESTDIR}${PREFIX}/bin; \
	${INSTALL_MAN} man/httpfile.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
