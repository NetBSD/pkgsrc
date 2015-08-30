# $NetBSD: Makefile,v 1.2 2015/08/30 15:06:56 taca Exp $

MODNAME=	zendopcache
PKGMODNAME=	opcache
CATEGORIES+=	www
PECL_VERSION=	7.0.5
PECL_LEGACY_VERSION_SCHEME=	yes

HOMEPAGE=	https://github.com/zend-dev/ZendOptimizerPlus
MAINTAINER=	imil@NetBSD.org
COMMENT=	Zend opcode cache and optimizer for PHP
LICENSE=	php

SUPERSEDES=	${PHP_PKG_PREFIX}-zendoptimizerplus-[0-9]*
PREV_PKGPATH=	www/zendoptimizerplus
PHP_VERSIONS_ACCEPTED=	54 55

REPLACE_BASH=	configure # cheaper than patching configure
USE_TOOLS+=	bash

PLIST_SRC+=		${.CURDIR}/PLIST.extras
PLIST_SUBST+=		PKGBASE=${PKGBASE:Q}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR}

.include "../../lang/php/ext.mk"

# this is not an usual extension, override MESSAGE.module
MESSAGE_SRC=		${.CURDIR}/MESSAGE

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
