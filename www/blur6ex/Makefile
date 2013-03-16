# $NetBSD: Makefile,v 1.17 2013/03/16 07:21:23 obache Exp $
#

DISTNAME=	blur6ex-0.1.198
PKGREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://www.blursoft.com/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.blursoft.com/
COMMENT=	Weblog and content framework

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.0.0:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTTPD_ROOT?=	share/httpd/htdocs
PLIST_SUBST+=	HTTPD_ROOT=${HTTPD_ROOT:Q}

BUILD_DEFS+=	HTTPD_ROOT

EGDIR=		share/examples/${PKGBASE}
PEGDIR=		${PREFIX}/${EGDIR}

INSTALLATION_DIRS=	${HTTPD_ROOT}/blog share/doc/${PKGBASE} \
			share/examples/${PKGBASE}

PKG_SYSCONFDIR.blur6exdb=	${PREFIX}/${HTTPD_ROOT}/blog/engine/core
PKG_SYSCONFDIR.blur6ex=		${PREFIX}/${HTTPD_ROOT}/blog

MESSAGE_SUBST+=	PKG_SYSCONFDIR.blur6exdb=${PKG_SYSCONFDIR.blur6exdb}
MESSAGE_SUBST+=	PKG_SYSCONFDIR.blur6ex=${PKG_SYSCONFDIR.blur6ex}

CONF_FILES=	${PEGDIR}/db.php ${PKG_SYSCONFDIR.blur6exdb}/db.php
CONF_FILES+=	${PEGDIR}/index.php ${PKG_SYSCONFDIR.blur6ex}/index.php

pre-install:
	${INSTALL_DATA} ${WRKSRC}/engine/core/db.php ${DESTDIR}${PEGDIR}
	${INSTALL_DATA} ${WRKSRC}/index.php ${DESTDIR}${PEGDIR}

do-install:
	${INSTALL_DATA}						\
		${WRKSRC}/install/INSTALL.txt			\
		${WRKSRC}/install/blur6ex_tables.sql		\
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	cd ${WRKSRC} && pax -rwppm '-s|.*/install.*$$||'	\
		'-s|./index.php$$||'				\
		'-s|./engine/core/db.php$$||' .			\
		${DESTDIR}${PREFIX}/${HTTPD_ROOT}/blog

.include "../../mk/apache.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
