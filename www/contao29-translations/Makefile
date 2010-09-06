# $NetBSD: Makefile,v 1.7 2010/09/06 15:09:13 taca Exp $
#

DISTNAME=	contao${CT_VER}-translations-${VERS}
CATEGORIES=	www
MASTER_SITES=	# defined for each distfiles
DISTFILES=	${CT_DISTFILES}
EXTRACT_DIR=	${WRKSRC}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.contao.org/download.html
COMMENT=	Language files for Contao CMS
LICENSE=	gnu-lgpl-v3

DEPENDS+=	contao${CT_VER}>=${CT_PKGVER}:../../www/contao${CT_VER}

# Use time stamp of latest translation.
VERS=		20100905
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
	cd ${WRKSRC}; pax -rw . ${DESTDIR}${PREFIX}/${CT_WEBDIR}

.include "../../www/contao29/Makefile.version"
.include "../../www/contao/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
