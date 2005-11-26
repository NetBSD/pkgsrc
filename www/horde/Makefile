# $NetBSD: Makefile,v 1.39.2.1 2005/11/26 15:08:19 salo Exp $

DISTNAME=	horde-2.2.9
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.horde.org/pub/horde/tarballs/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.horde.org/
COMMENT=	PHP application framework

DEPENDS+=	php-gettext>=4.3.3:../../devel/php-gettext
DEPENDS+=	pear-Log-[0-9]*:../../sysutils/pear-Log
DEPENDS+=	pear-DB-[0-9]*:../../databases/pear-DB

CONFLICTS+=	horde-3.*

DOCDIR=		${PREFIX}/share/doc/horde
EGDIR=		${PREFIX}/share/examples/horde
HORDEDIR=	${PREFIX}/share/horde

MESSAGE_SUBST+=	HORDEDIR=${HORDEDIR}

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd

USE_PKGINSTALL=	YES
CONF_FILES=	${EGDIR}/horde.conf ${PKG_SYSCONFDIR}/horde.conf
CONF_FILES+=	${HORDEDIR}/config/horde.php.dist ${HORDEDIR}/config/horde.php
CONF_FILES+=	${HORDEDIR}/config/html.php.dist ${HORDEDIR}/config/html.php
CONF_FILES+=	${HORDEDIR}/config/lang.php.dist ${HORDEDIR}/config/lang.php
CONF_FILES+=	${HORDEDIR}/config/mime_drivers.php.dist ${HORDEDIR}/config/mime_drivers.php
CONF_FILES+=	${HORDEDIR}/config/mime_mapping.php.dist ${HORDEDIR}/config/mime_mapping.php
CONF_FILES+=	${HORDEDIR}/config/motd.php.dist ${HORDEDIR}/config/motd.php
CONF_FILES+=	${HORDEDIR}/config/prefs.php.dist ${HORDEDIR}/config/prefs.php
CONF_FILES+=	${HORDEDIR}/config/registry.php.dist ${HORDEDIR}/config/registry.php

post-patch:
	cd ${WRKSRC}/scripts;						\
	for FILE in mime_mapping/convert.pl; do		\
		${MV} -f $${FILE} $${FILE}.orig;			\
		${SED}	-e "s|/usr/bin/perl|${PERL5}|g"			\
			$${FILE}.orig > $${FILE};			\
	done

do-build:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;
	${FIND} ${WRKSRC} -name .htaccess -exec ${RM} -f {} \;
	${FIND} ${WRKSRC}/scripts -name "*.pl" -exec ${CHMOD} +x {} \;
	${FIND} ${WRKSRC}/scripts -name "*.sh" -exec ${CHMOD} +x {} \;

pre-install:
	${SED}	-e "s|@HORDEDIR@|${HORDEDIR}|g"				\
		${FILESDIR}/horde.conf.dist > ${WRKDIR}/horde.conf.dist

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${HORDEDIR}
	cd ${WRKDIR}; ${INSTALL_DATA} horde.conf.dist ${EGDIR}/horde.conf
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING README docs/* ${DOCDIR}
	cd ${WRKSRC}; ${CP} -R graphics lib locale po scripts templates util ${HORDEDIR}
	${INSTALL_DATA_DIR} ${HORDEDIR}/config
	cd ${WRKSRC}/config; ${INSTALL_DATA} * ${HORDEDIR}/config
	cd ${WRKSRC}; ${INSTALL_DATA} *.php ${HORDEDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${HORDEDIR}
	${FIND} ${HORDEDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${HORDEDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.pkg.mk"
