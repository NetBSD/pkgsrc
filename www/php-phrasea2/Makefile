# $NetBSD: Makefile,v 1.5 2011/12/18 21:09:27 dholland Exp $
#

.include "../../www/phraseanet/Makefile.common"

MODNAME=		phrasea2
PECL_VERSION=		${VERS}
PECL_LEGACY_VERSION_SCHEME=	yes
PKG_DESTDIR_SUPPORT=	user-destdir
EXTRACT_ELEMENTS=	${DISTNAME}/bin/src/php_phrasea2
USE_LANGUAGES=		c c++

.include "../../lang/php/ext.mk"

# php/ext.mk trashes these, preventing the package from building,
# so set them back again afterwards. grr
DISTNAME=	phraseanet-v3.1.4-linux
DISTINFO_FILE=	${.CURDIR}/distinfo

# This seems to now be needed though it wasn't before...
WRKSRC=${WRKDIR}/${DISTNAME}/bin/src/php_phrasea2

.include "../../mk/mysql.buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
