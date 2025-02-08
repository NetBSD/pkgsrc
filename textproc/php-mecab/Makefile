# $NetBSD: Makefile,v 1.15 2025/02/08 03:55:19 taca Exp $

PECL_DISTNAME=	${MODNAME}-${PECL_VERSION}
MODNAME=	mecab
PECL_VERSION=	0.6.0
PKGREVISION=	2
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES=	textproc japanese
MASTER_SITES=	http://pecl.opendogs.org/get/
#EXTRACT_SUFX=	.tar.gz

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/rsky/php-mecab
COMMENT=	PHP extension for MeCab Morphological Analyzer
LICENSE=	mit

INSTALLATION_DIRS+=	${PHP_EGDIR}/mecab
PLIST_SRC+=		${.CURDIR}/PLIST.extras

PHP_VERSIONS_ACCEPTED=	56 74

post-install:
	cd ${WRKSRC}/examples && \
	${INSTALL_DATA} *.php ${DESTDIR}${PREFIX}/${PHP_EGDIR}/mecab
	${INSTALL_DATA} ${WRKSRC}/*.ini ${DESTDIR}${PREFIX}/${PHP_EGDIR}/mecab

.include "../../textproc/mecab-base/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
