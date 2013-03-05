# $NetBSD: Makefile,v 1.1 2013/03/05 22:18:37 imil Exp $

MODNAME=	zendoptimizerplus
PKGMODNAME=	ZendOptimizerPlus
CATEGORIES+=	www
PECL_VERSION=	7.0.0
PECL_LEGACY_VERSION_SCHEME=	yes

HOMEPAGE=	https://github.com/zend-dev/ZendOptimizerPlus
MAINTAINER=	imil@NetBSD.org
COMMENT=	Zend opcode cache and optimizer for PHP
LICENSE=	php

PLIST_SRC+=		${.CURDIR}/PLIST.extras
PLIST_SUBST+=		PKGBASE=${PKGBASE:Q}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR}

.include "../../lang/php/ext.mk"
# this is not an usual extension, override MESSAGE.module
MESSAGE_SRC=           ${.CURDIR}/MESSAGE

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
