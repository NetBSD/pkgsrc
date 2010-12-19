# $NetBSD: Makefile,v 1.1.1.1 2010/12/19 02:13:50 taca Exp $
#

MODNAME=	mecab
PECL_VERSION=	0.4.1
CATEGORIES=	textproc japanese
MASTER_SITES=	http://pecl.opendogs.org/get/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://page2.xrea.jp/#php_mecab
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

.include "../../textproc/mecab-base/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
