# $NetBSD: Makefile,v 1.14 2010/03/21 14:43:32 taca Exp $
#

DISTNAME=	typolight${TL_VER}-translations-${VERS}
CATEGORIES=	www
MASTER_SITES=	# defined for each distfiles
DISTFILES=	${TL_DISTFILES}
EXTRACT_DIR=	${WRKSRC}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.typolight.org/download.html
COMMENT=	Language files for TYPOlight CMS
LICENSE=	gnu-lgpl-v3

DEPENDS+=	typolight${TL_VER}>=${TL_PKGVER}:../../www/typolight${TL_VER}

# Use time stamp of latest translation.
VERS=		20100318
USE_TOOLS=	pax
NO_BUILD=	yes
NO_CONFIGURE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

SEPARATED_MODULES=	development dfGallery glossary memberlist pun_bridge

.include "options.mk"

pre-install:
	${FIND} ${WRKSRC}/system/modules \
		\( -name "*.orig*" -o -name tl_flash.php \) -exec ${RM} -f {} \;
.for d in ${SEPARATED_MODULES}
	${RM} -fr ${WRKSRC}/system/modules/${d}
.endfor
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

do-install:
	cd ${WRKSRC}; pax -rw . ${DESTDIR}${PREFIX}/${TL_WEBDIR}

.include "../../www/typolight28/Makefile.version"
.include "../../www/typolight/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
