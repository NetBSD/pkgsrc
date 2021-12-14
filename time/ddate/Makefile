# $NetBSD: Makefile,v 1.1 2021/12/14 10:34:07 nia Exp $

DISTNAME=	ddate-0.2.2
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=bo0ts/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bo0ts/ddate
COMMENT=	Discordian calendar date(1) command
LICENSE=	public-domain

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

pre-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ddate \
	    ${DESTDIR}${PREFIX}/bin/ddate
	${INSTALL_MAN} ${WRKSRC}/ddate.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ddate.1

.include "../../mk/bsd.pkg.mk"
