# $NetBSD: Makefile,v 1.15 2020/03/22 20:33:29 tnn Exp $
#

.include "../../www/phraseanet/Makefile.common"

MODNAME=			phrasea2
PKGREVISION=			2
PECL_VERSION=			${VERS}
PECL_LEGACY_VERSION_SCHEME=	yes
EXTRACT_ELEMENTS=		${DISTNAME}/bin/src/php_phrasea2
EXTRACT_SUFX=			.tar.gz
USE_LANGUAGES=			c c++

PHP_VERSIONS_ACCEPTED=	56

.include "../../lang/php/ext.mk"

# php/ext.mk trashes these, preventing the package from building,
# so set them back again afterwards. grr
DISTNAME=	phraseanet-v${VERS}-linux
DIST_SUBDIR=	#empty

# The package's config.mk sets CC=g++, which is a bit unorthodox and
# confuses libtool, which can't deduce the tagged configuration if
# pkgsrc's idea of CXX is something other than g++.
MAKE_FLAGS+=	CC=${CXX}

# This seems to now be needed though it wasn't before...
WRKSRC=	${WRKDIR}/${DISTNAME}/bin/src/php_phrasea2

.include "../../mk/mysql.buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
