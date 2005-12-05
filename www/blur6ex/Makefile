# $NetBSD: Makefile,v 1.3 2005/12/05 20:51:11 rillig Exp $
#

DISTNAME=	blur6ex-0.1.198
CATEGORIES=	www
MASTER_SITES=	http://www.blursoft.com/releases/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.blursoft.com/
COMMENT=	Weblog and content framework

DEPENDS+=	ap{,2}-php>=4.0.0:../../www/ap-php
DEPENDS+=	php-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=	mysql{,4}-server>=4.0:../../databases/mysql4-server

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_PKGINSTALL=	yes

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
	${INSTALL_DATA} ${WRKSRC}/engine/core/db.php ${PEGDIR}
	${INSTALL_DATA} ${WRKSRC}/index.php ${PEGDIR}

do-install:
	${INSTALL_DATA}						\
		${WRKSRC}/install/INSTALL.txt			\
		${WRKSRC}/install/blur6ex_tables.sql		\
		${PREFIX}/share/doc/${PKGBASE}
	cd ${WRKSRC} && ${PAX} -rwppm '-s|.*/install.*$$||'	\
		'-s|./index.php$$||'				\
		'-s|./engine/core/db.php$$||' .			\
		${PREFIX}/${HTTPD_ROOT}/blog

.include "../../mk/bsd.pkg.mk"
