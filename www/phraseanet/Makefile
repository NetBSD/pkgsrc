# $NetBSD: Makefile,v 1.25 2025/02/08 04:08:58 taca Exp $

.include "../../www/phraseanet/Makefile.common"
PKGNAME=	phraseanet-${VERS}
PKGREVISION=	8

USE_TOOLS+=	pax

PHP_VERSIONS_ACCEPTED=	56

DEPENDS+=	${PHP_PKG_PREFIX}-phrasea2-[0-9]*:../../www/php-phrasea2
DEPENDS+=	${PHP_PKG_PREFIX}-opcache>=${PHP_BASE_VERS}:../../devel/php-opcache
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=${PHP_BASE_VERS}:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-exif>=${PHP_BASE_VERS}:../../graphics/php-exif
DEPENDS+=	${PHP_PKG_PREFIX}-ftp>=${PHP_BASE_VERS}:../../net/php-ftp
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=${PHP_BASE_VERS}:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-json>=${PHP_BASE_VERS}:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=${PHP_BASE_VERS}:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-sockets>=${PHP_BASE_VERS}:../../net/php-sockets
DEPENDS+=	${PHP_PKG_PREFIX}-xsl>=${PHP_BASE_VERS}:../../textproc/php-xsl
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=${PHP_BASE_VERS}:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=${PHP_BASE_VERS}:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-memcache>=2.2.7<3:../../devel/php-memcache2
DEPENDS+=	phraseanet-indexer-${VERS}{,nb*}:../../www/phraseanet-indexer
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=5.2:../../www/ap-php
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool

.include "../../mk/bsd.prefs.mk"

PHRASEANETDIR?=		${PREFIX}/share/phraseanet
APACHE_USER?=		www
APACHE_GROUP?=		www
APACHE_DIRS_PERMS=	${APACHE_USER} ${APACHE_GROUP} 0755

INSTALLATION_DIRS+=	share/examples/phraseanet ${PHRASEANETDIR}
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

REPLACE_PHP+=	bin/console

do-build:

pre-install:
	${FIND} ${WRKSRC} -name "*.orig*" -exec ${RM} -f {} \;
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
