# $NetBSD: Makefile,v 1.4 2011/12/17 13:46:29 obache Exp $
#

.include "../../www/phraseanet/Makefile.common"

MODNAME=		phrasea2
PECL_VERSION=		${VERS}
PECL_LEGACY_VERSION_SCHEME=	yes
PKG_DESTDIR_SUPPORT=	user-destdir
EXTRACT_ELEMENTS=	${DISTNAME}/bin/src/php_phrasea2
USE_LANGUAGES=		c c++

.include "../../lang/php/ext.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
