# $NetBSD: Makefile,v 1.9 2013/03/16 07:21:25 obache Exp $
#

.include "../../www/phraseanet/Makefile.common"
PKGNAME=        phraseanet-${VERS}
PKGREVISION=	2

USE_TOOLS+=	pax

DEPENDS+=	${PHP_PKG_PREFIX}-phrasea2-[0-9]*:../../www/php-phrasea2
DEPENDS+=	${PHP_PKG_PREFIX}-apc-[0-9]*:../../www/php-apc
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring-[0-9]*:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-gettext-[0-9]*:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-exif-[0-9]*:../../graphics/php-exif
DEPENDS+=	${PHP_PKG_PREFIX}-ftp-[0-9]*:../../net/php-ftp
DEPENDS+=	${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-sockets-[0-9]*:../../net/php-sockets
DEPENDS+=	${PHP_PKG_PREFIX}-xsl-[0-9]*:../../textproc/php-xsl
DEPENDS+=	${PHP_PKG_PREFIX}-zip-[0-9]*:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib-[0-9]*:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-memcache-[0-9]*:../../devel/php-memcache
DEPENDS+=	phraseanet-indexer-${VERS}{,nb*}:../../www/phraseanet-indexer
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=5.2:../../www/ap-php
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool


PHRASEANETDIR?=		${PREFIX}/share/phraseanet
APACHE_USER?=		www
APACHE_GROUP?=		www
APACHE_DIRS_PERMS=	${APACHE_USER} ${APACHE_GROUP} 0755

INSTALLATION_DIRS+=	share/examples/phraseanet
CONF_FILES=	${DESTDIR}${PREFIX}/share/examples/phraseanet/phrasea.conf \
		${PKG_SYSCONFDIR}/phrasea.conf

MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/config ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/config/stamp ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/config/status ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/config/minilogos ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/config/templates ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/config/topics ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/config/wm ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/logs ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/www/custom ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/www/skins ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/tmp ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/tmp/locks ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/tmp/cache_twig ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/tmp/cache_minify ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/tmp/lazaret ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/tmp/desc_tmp ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/tmp/download ${APACHE_DIRS_PERMS}
MAKE_DIRS_PERMS+= ${PHRASEANETDIR}/tmp/batches ${APACHE_DIRS_PERMS}

do-build:

pre-install:
	${FIND} ${WRKSRC:Q} -name "*.orig*" -exec ${RM} -f {} \;
	${RM} -rf ${WRKSRC}/bin/src

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PHRASEANETDIR}

.for locale in ar_SA de_DE en_GB fr_FR
	${LN} -s ${DESTDIR}${PHRASEANETDIR}/locale/${locale} 		\
		    ${DESTDIR}${PHRASEANETDIR}/locale/${locale}.UTF8
.endfor
	${SED} -e "s|@PHRASEANETDIR@|${PHRASEANETDIR}|g" 		\
	       -e "s|@VARBASE@|${VARBASE}|g" ${FILESDIR}/phrasea.conf >	\
		${DESTDIR}${PREFIX}/share/examples/phraseanet/phrasea.conf

.include "../../lang/php/phpversion.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
