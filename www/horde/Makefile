# $NetBSD: Makefile,v 1.16 2001/11/25 18:59:49 jlam Exp $

DISTNAME=	horde-1.2.7
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.horde.org/pub/horde/tarballs/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.horde.org/
COMMENT=	PHP application framework

DEPENDS+=	php>3.0.17:../../www/php4
DEPENDS+=	php-pcre>3.0.17:../../devel/php4-pcre

DOCDIR=		${PREFIX}/share/doc/horde
EGDIR=		${PREFIX}/share/examples/horde
HORDEDIR=	${PREFIX}/share/horde
PHPLIBDIR=	${PREFIX}/share/horde/phplib

MESSAGE_SUBST+=	HORDEDIR=${HORDEDIR}
MESSAGE_SUBST+=	PHPLIBDIR=${PHPLIBDIR}

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd

CONF_FILES=	${EGDIR}/horde.conf ${PKG_SYSCONFDIR}/horde.conf
CONF_FILES+=	${PHPLIBDIR}/local.inc.dist ${PHPLIBDIR}/local.inc
CONF_FILES+=	${PHPLIBDIR}/prepend.php3.dist ${PHPLIBDIR}/prepend.php3
CONF_FILES+=	${HORDEDIR}/config/horde.php3.dist ${HORDEDIR}/config/horde.php3
SUPPORT_FILES=	${HORDEDIR}/config/MOTD.html.dist ${HORDEDIR}/config/MOTD.html
SUPPORT_FILES+=	${HORDEDIR}/config/header.txt.dist ${HORDEDIR}/config/header.txt
SUPPORT_FILES+=	${HORDEDIR}/config/html.php3.dist ${HORDEDIR}/config/html.php3
SUPPORT_FILES+=	${HORDEDIR}/config/lang.php3.dist ${HORDEDIR}/config/lang.php3
SUPPORT_FILES+=	${HORDEDIR}/config/menu.txt.dist ${HORDEDIR}/config/menu.txt
SUPPORT_FILES+=	${HORDEDIR}/config/mime.php3.dist ${HORDEDIR}/config/mime.php3

post-extract:
	cd ${WRKSRC}/phplib;						\
	for file in local.inc prepend.php3; do				\
		${MV} $${file} $${file}.dist;				\
	done
	cd ${WRKSRC}/config;						\
	for file in							\
		MOTD.html header.txt html.php3 lang.php3 menu.txt	\
		mime.php3;						\
	do								\
		${MV} $${file} $${file}.dist;				\
	done

post-patch:
	cd ${WRKSRC}/scripts;						\
	for file in add_horde_string.pl add_lang_string.pl; do		\
		${MV} -f $${file} $${file}.orig;			\
		${SED}	-e "s|/usr/bin/perl|${PERL5}|g"			\
			$${file}.orig > $${file};			\
	done
	cd ${WRKSRC}/scripts/database;					\
	for file in pgsql_cuser.sh; do					\
		${MV} -f $${file} $${file}.orig;			\
		${SED}	-e "s|/usr/bin/psql|${LOCALBASE}/bin/psql|g"	\
			$${file}.orig > $${file};			\
	done

do-build:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;
	${FIND} ${WRKSRC} -name "*.pl" -exec ${CHMOD} +x {} \;
	${FIND} ${WRKSRC} -name "*.sh" -exec ${CHMOD} +x {} \;

pre-install:
	${SED}	-e "s|@HORDEDIR@|${HORDEDIR}|g"				\
		-e "s|@PHPLIBDIR@|${PHPLIBDIR}|g"			\
		${FILESDIR}/horde.conf.dist > ${WRKDIR}/horde.conf.dist
	${SED}	-e "s|@HORDEDIR@|${HORDEDIR}|g"				\
		${FILESDIR}/horde_setup.sh > ${WRKDIR}/horde_setup.sh
	${SED}	-e "s|@HORDEDIR@|${HORDEDIR}|g"				\
		${FILESDIR}/horde_secure.sh > ${WRKDIR}/horde_secure.sh
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/horde_setup.sh ${PREFIX}/sbin/horde_setup
	${INSTALL_SCRIPT} ${WRKDIR}/horde_secure.sh ${PREFIX}/sbin/horde_secure
	${INSTALL_DATA_DIR} ${DOCDIR} ${EGDIR} ${HORDEDIR} ${PHPLIBDIR}
	cd ${WRKDIR}; ${INSTALL_DATA} horde.conf.dist ${EGDIR}/horde.conf
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING README docs/* ${DOCDIR}
	cd ${WRKSRC}/phplib; ${INSTALL_DATA} * ${PHPLIBDIR}
	cd ${WRKSRC}; ${CP} -R graphics lib locale scripts templates ${HORDEDIR}
	${INSTALL_DATA_DIR} ${HORDEDIR}/config
	cd ${WRKSRC}/config; ${INSTALL_DATA} * ${HORDEDIR}/config
	cd ${WRKSRC}; ${INSTALL_DATA} *.php3 ${HORDEDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${HORDEDIR}
	${CHMOD} -R a-w ${HORDEDIR}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
