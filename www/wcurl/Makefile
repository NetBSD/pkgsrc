# $NetBSD: Makefile,v 1.2 2024/09/20 06:45:29 kim Exp $

DISTNAME=	wcurl-2024.07.10
CATEGORIES=	www
# Not there yet
#MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/w/wcurl/}
# Tar file top directory name includes commit hash
#MASTER_SITES=	https://salsa.debian.org/debian/${PKGBASE}/-/archive/${PKGVERSION_NOREV}/
# Conventional tar file found here at this mirror
MASTER_SITES=	${MASTER_SITE_GITHUB:=Debian/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://salsa.debian.org/debian/wcurl
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
