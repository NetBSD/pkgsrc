# $NetBSD: Makefile,v 1.7 2012/03/11 11:50:21 obache Exp $
#

PECL_DISTNAME=	php-${MODNAME}-${PECL_VERSION}
MODNAME=	mecab
PECL_VERSION=	0.5.0
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES=	textproc japanese
MASTER_SITES=	http://cloud.github.com/downloads/rsky/php-mecab/
EXTRACT_SUFX=	.tgz

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/rsky/php-mecab
COMMENT=	PHP extension for MeCab Morphological Analyzer
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=			share/examples/php/mecab
INSTALLATION_DIRS+=	${EGDIR}
PLIST_SRC+=		${.CURDIR}/PLIST.extras

post-install:
	cd ${WRKSRC}/examples && \
	${INSTALL_DATA} *.php ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../textproc/mecab-base/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
