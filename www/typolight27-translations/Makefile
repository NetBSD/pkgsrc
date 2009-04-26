# $NetBSD: Makefile,v 1.1.1.1 2009/04/26 04:01:50 taca Exp $
#

DISTNAME=	typolight${TL_VER}-translations-${VERS}
CATEGORIES=	www
MASTER_SITES=	http://www.typolight.org/download.html?file=tl_files/languages/ja/
DISTFILES=	${TL_DISTFILES}
EXTRACT_DIR=	${WRKSRC}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.typolight.org/download-translations.html
COMMENT=	Language files for TYPOlight CMS

DEPENDS+=	typolight${TL_VER}>=${TL_PKGVER}:../../www/typolight${TL_VER}

# Use time stamp of latest translation.
VERS=		20090423
USE_TOOLS=	pax
NO_BUILD=	yes
NO_CONFIGURE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

pre-install:
	${FIND} ${WRKSRC:Q} -name "*.orig*" -exec ${RM} -f {} \;

do-install:
	cd ${WRKSRC}; pax -rw . ${DESTDIR}${PREFIX}/${TL_WEBDIR}

.include "../../www/typolight27/Makefile.version"
.include "../../www/typolight/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
