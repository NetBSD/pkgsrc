# $NetBSD: Makefile,v 1.27.2.1 2009/12/20 09:41:39 tron Exp $
#

DISTNAME=	typolight${TL_VER}-translations-${VERS}
CATEGORIES=	www
MASTER_SITES=	# defined for each distfiles
DISTFILES=	${TL_DISTFILES}
EXTRACT_DIR=	${WRKSRC}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.typolight.org/download.html
COMMENT=	Language files for TYPOlight CMS
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	typolight${TL_VER}>=${TL_PKGVER}:../../www/typolight${TL_VER}

# Use time stamp of latest translation.
VERS=		20091009
USE_TOOLS=	pax
NO_BUILD=	yes
NO_CONFIGURE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

pre-install:
	${FIND} ${WRKSRC} -name "*.orig*" -exec ${RM} -f {} \;
	cd ${WRKSRC}; \
		${RM} -fr system/modules/development system/modules/pun_bridge

do-install:
	cd ${WRKSRC}; pax -rw . ${DESTDIR}${PREFIX}/${TL_WEBDIR}

.include "../../www/typolight27/Makefile.version"
.include "../../www/typolight/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
