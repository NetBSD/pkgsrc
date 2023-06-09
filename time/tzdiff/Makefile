# $NetBSD: Makefile,v 1.1 2023/06/09 04:21:39 taca Exp $
DISTNAME=	tzdiff-1.1.1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=belgianbeer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/belgianbeer/tzdiff
COMMENT=	Showing time pairs between target timezone and localtime
LICENSE=	2-clause-bsd

NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tzdiff ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tzdiff.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
