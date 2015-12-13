# $NetBSD: Makefile,v 1.10 2015/12/13 17:20:21 taca Exp $
#

PECL_DISTNAME=	${MODNAME}-${PECL_VERSION}
MODNAME=	mecab
PECL_VERSION=	0.6.0
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES=	textproc japanese
MASTER_SITES=   http://pecl.opendogs.org/get/
#EXTRACT_SUFX=	.tar.gz

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/rsky/php-mecab
COMMENT=	PHP extension for MeCab Morphological Analyzer
LICENSE=	mit

EGDIR=		share/examples/php/mecab
INSTALLATION_DIRS+=	${EGDIR}
PLIST_SRC+=		${.CURDIR}/PLIST.extras

post-install:
	cd ${WRKSRC}/examples && \
	${INSTALL_DATA} *.php ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../textproc/mecab-base/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
