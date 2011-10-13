# $NetBSD: Makefile,v 1.2 2011/10/13 12:24:33 dholland Exp $
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

# php/ext.mk changes this, set it back (XXX)
DISTINFO_FILE=${.CURDIR}/distinfo

.include "../../mk/bsd.pkg.mk"
