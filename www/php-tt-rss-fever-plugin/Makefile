# $NetBSD: Makefile,v 1.3 2017/09/03 08:53:17 wiz Exp $

DISTNAME=	fever-1.2
PKGNAME=	${PHP_PKG_PREFIX}-tt-rss-${DISTNAME:S/-/-plugin-/}
CATEGORIES=	www
MASTER_SITES=	-https://tt-rss.org/forum/download/file.php?id=452
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tt-rss.org/forum/viewtopic.php?f=22&t=1981
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
