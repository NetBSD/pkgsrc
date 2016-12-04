# $NetBSD: Makefile,v 1.11.2.1 2016/12/04 15:21:07 bsiegert Exp $
#

PECL_DISTNAME=	${MODNAME}-${PECL_VERSION}
MODNAME=	mecab
PECL_VERSION=	0.6.0
PECL_LEGACY_VERSION_SCHEME=	yes
PKGREVISION=	1
CATEGORIES=	textproc japanese
MASTER_SITES=   http://pecl.opendogs.org/get/
#EXTRACT_SUFX=	.tar.gz

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/rsky/php-mecab
COMMENT=	PHP extension for MeCab Morphological Analyzer
LICENSE=	mit

INSTALLATION_DIRS+=	${EGDIR}/mecab
PLIST_SRC+=		${.CURDIR}/PLIST.extras

post-install:
	cd ${WRKSRC}/examples && \
	${INSTALL_DATA} *.php ${DESTDIR}${EGDIR}/mecab
	${INSTALL_DATA} ${WRKSRC}/*.ini ${DESTDIR}${EGDIR}

.include "../../textproc/mecab-base/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
