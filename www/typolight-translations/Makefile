# $NetBSD: Makefile,v 1.1.1.1 2008/09/15 09:59:08 taca Exp $
#

DISTNAME=	typolight-translations-${VERS}
CATEGORIES=	www
MASTER_SITES=	http://www.typolight.org/download.html?file=tl_files/languages/ja/
DISTFILES=	${TL_DISTFILES}
EXTRACT_DIR=	${WRKSRC}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.typolight.org/download-translations.html
COMMENT=	Language files for TYPOlight CMS

#DEPENDS+=	typolight>=${TL_VERSION}:../../www/typolight
DEPENDS+=	typolight>=${TL_VERSION}:../../WORK/typolight

VERS=		20080915
USE_TOOLS=	pax
NO_BUILD=	yes
NO_CONFIGURE=	yes

.include "options.mk"

pre-install:
	cd ${WRKSRC}; ${FIND} . -name '*.orig' -print | ${XARGS} -- ${RM}

do-install:
	cd ${WRKSRC}; pax -rw . ${DESTDIR}${PREFIX}/${TL_WEBDIR}

#.include "../../www/typolight/Makefile.common"
.include "../../WORK/typolight/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
