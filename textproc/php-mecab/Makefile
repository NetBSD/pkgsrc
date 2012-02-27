# $NetBSD: Makefile,v 1.4 2012/02/27 11:25:39 obache Exp $
#

MODNAME=	mecab
PECL_VERSION=	0.4.1
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES=	textproc japanese
MASTER_SITES=	http://pecl.opendogs.org/get/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/rsky/php-mecab
#		http://d.hatena.ne.jp/rsky/
COMMENT=	PHP extension for MeCab Morphological Analyzer
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=			share/examples/php/mecab
INSTALLATION_DIRS+=	${EGDIR}
PLIST_SRC+=		${.CURDIR}/PLIST.extras

post-install:
	cd ${WRKSRC}/examples && \
	${INSTALL_DATA} *.php ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../textproc/mecab-base09/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
