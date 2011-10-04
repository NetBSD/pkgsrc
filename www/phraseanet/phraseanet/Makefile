# $NetBSD: Makefile,v 1.1.1.1 2011/10/04 08:03:45 manu Exp $
#

.include "../../www/phraseanet/Makefile.common"
PKGNAME=        phraseanet-${VERS}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

DEPENDS+=	${PHP_PKG_PREFIX}-phrasea2:../../www/php-phrasea2
DEPENDS+=	${PHP_PKG_PREFIX}-apc:../../www/php-apc
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-gettext:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-dom:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-exif:../../graphics/php-exif
DEPENDS+=	${PHP_PKG_PREFIX}-fileinfo:../../sysutils/php-fileinfo
DEPENDS+=	${PHP_PKG_PREFIX}-ftp:../../net/php-ftp
DEPENDS+=	${PHP_PKG_PREFIX}-curl:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-gd:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-json:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-iconv:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mysql:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-phrasea2:../../www/php-phrasea2
DEPENDS+=	${PHP_PKG_PREFIX}-sockets:../../net/php-sockets
DEPENDS+=	${PHP_PKG_PREFIX}-xsl:../../textproc/php-xsl
DEPENDS+=	${PHP_PKG_PREFIX}-zip:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-memcache:../../devel/php-memcache
DEPENDS+=	phraseanet-indexer-${VERS}:../../www/phraseanet-indexer
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=5.2:../../www/ap-php
DEPENDS+=	ImageMagick:../../graphics/ImageMagick
DEPENDS+=	p5-Image-ExifTool:../../graphics/p5-Image-ExifTool

.include "../../mk/bsd.prefs.mk"

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
	# nothing

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


.include "../../mk/apache.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
