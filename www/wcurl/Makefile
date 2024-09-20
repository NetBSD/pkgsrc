# $NetBSD: Makefile,v 1.3 2024/09/20 07:10:22 kim Exp $

DISTNAME=	wcurl-2024.07.10
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=curl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://curl.se/wcurl/
COMMENT=	Simple wrapper around curl to easily download files
# curl license (see ../../www/curl/Makefile)
# "not completely, but near enough"
LICENSE=	mit

DEPENDS+=	curl>=7.46.0:../../www/curl

USE_LANGUAGES=	# none
NO_BUILD=	yes
NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} \
	  ${WRKSRC}/${PKGBASE} \
	  ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} \
	  ${WRKSRC}/${PKGBASE}.1 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
