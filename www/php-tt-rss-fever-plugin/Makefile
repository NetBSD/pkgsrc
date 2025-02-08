# $NetBSD: Makefile,v 1.5 2025/02/08 04:07:19 taca Exp $

DISTNAME=	fever-1.2
PKGNAME=	${PHP_PKG_PREFIX}-tt-rss-${DISTNAME:S/-/-plugin-/}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=dasmurphy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dasmurphy/tinytinyrss-fever-plugin/
COMMENT=	Fever emulation plugin for Tiny Tiny RSS

DEPENDS+=	${PHP_PKG_PREFIX}-tt-rss>=1.7.9:../../www/php-tt-rss

WRKSRC=		${WRKDIR}/fever
USE_LANGUAGES=	# none
USE_TOOLS=	pax

INSTALLATION_DIRS=	share/tt-rss/plugins/fever

do-build:

do-install:
	cd ${WRKSRC} && pax -rw -pp * ${DESTDIR}${PREFIX}/share/tt-rss/plugins/fever

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
