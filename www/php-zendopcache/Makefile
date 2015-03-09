# $NetBSD: Makefile,v 1.1 2015/03/09 13:33:18 imil Exp $

MODNAME=	zendopcache
PKGMODNAME=	opcache
CATEGORIES+=	www
PECL_VERSION=	7.0.4
PECL_LEGACY_VERSION_SCHEME=	yes

HOMEPAGE=	https://github.com/zend-dev/ZendOptimizerPlus
MAINTAINER=	imil@NetBSD.org
COMMENT=	Zend opcode cache and optimizer for PHP
LICENSE=	php

SUPERSEDES=	${PHP_PKG_PREFIX}-zendoptimizerplus-[0-9]*
PREV_PKGPATH=	www/zendoptimizerplus

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
