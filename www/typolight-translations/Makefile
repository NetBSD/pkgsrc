# $NetBSD: Makefile,v 1.21 2009/02/25 12:36:19 taca Exp $
#

DISTNAME=	typolight-translations-${VERS}
CATEGORIES=	www
MASTER_SITES=	http://www.typolight.org/download.html?file=tl_files/languages/ja/
DISTFILES=	${TL_DISTFILES}
EXTRACT_DIR=	${WRKSRC}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.typolight.org/download-translations.html
COMMENT=	Language files for TYPOlight CMS

DEPENDS+=	typolight>=2.6.0:../../www/typolight

# Use time stamp of latest translation.
VERS=		20090223
USE_TOOLS=	pax
NO_BUILD=	yes
NO_CONFIGURE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

pre-install:
	cd ${WRKSRC}; \
		${FIND} . -type f -name '*.orig' -print | ${XARGS} -- ${RM}

do-install:
	cd ${WRKSRC}; pax -rw . ${DESTDIR}${PREFIX}/${TL_WEBDIR}

.include "../../www/typolight/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
