# $NetBSD: Makefile,v 1.1.1.1 2011/10/04 08:01:18 manu Exp $
#

.include "../../www/phraseanet/Makefile.common"

MODNAME=		phrasea2
PKGNAME=		${PHP_PKG_PREFIX}-${MODNAME}-${PHP_BASE_VERS}.${VERS}
PKG_DESTDIR_SUPPORT=	user-destdir
EXTRACT_ELEMENTS=	${DISTNAME}/bin/src/php_phrasea2
USE_LANGUAGES=		c c++

.include "../../lang/php/ext.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
