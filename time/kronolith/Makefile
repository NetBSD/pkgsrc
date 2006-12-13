# $NetBSD: Makefile,v 1.7.2.1 2006/12/13 08:48:39 ghen Exp $

DISTNAME=	kronolith-h3-${KRONOLITHVER}
PKGNAME=	kronolith-${KRONOLITHVER}
CATEGORIES=	www time
MASTER_SITES=	http://ftp.horde.org/pub/kronolith/ \
		ftp://ftp.horde.org/pub/kronolith/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.horde.org/kronolith/
COMMENT=	Horde calendar application

DEPENDS+=	horde>=3.0.0:../../www/horde
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Date-[0-9]*:../../time/pear-Date

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/kronolith
EGDIR=		${PREFIX}/share/examples/kronolith
HORDEDIR=	${PREFIX}/share/horde
KRONOLITHDIR=	${HORDEDIR}/kronolith
KRONOLITHVER=	2.1.4
PAXDIRS=	js lib locale po scripts templates themes

MESSAGE_SUBST+=	KRONOLITHDIR=${KRONOLITHDIR:Q}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

PKG_SYSCONFSUBDIR?=	httpd
USE_PKGINSTALL=		YES

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	kronolith.conf.dist
SUBST_SED.files=	-e "s|@KRONOLITHDIR@|${KRONOLITHDIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

CONF_FILES=		${EGDIR}/kronolith.conf ${PKG_SYSCONFDIR}/kronolith.conf
CONF_FILES_PERMS+=	${KRONOLITHDIR}/config/conf.xml.dist \
			${KRONOLITHDIR}/config/conf.xml \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${KRONOLITHDIR}/config/keywords.php.dist \
			${KRONOLITHDIR}/config/keywords.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${KRONOLITHDIR}/config/menu.php.dist \
			${KRONOLITHDIR}/config/menu.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${KRONOLITHDIR}/config/prefs.php.dist \
			${KRONOLITHDIR}/config/prefs.php \
			${APACHE_USER} ${ROOT_GROUP} 0440

do-build:
	${CP} ${FILESDIR}/kronolith.conf.dist ${WRKSRC}/kronolith.conf.dist
	${CP} ${WRKSRC}/config/conf.xml ${WRKSRC}/config/conf.xml.dist
	${FIND} ${WRKSRC} -name .htaccess -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${KRONOLITHDIR}
	${INSTALL_DATA_DIR} ${KRONOLITHDIR}/config
	${INSTALL_DATA} ${WRKSRC}/kronolith.conf.dist ${EGDIR}/kronolith.conf
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/RELEASE_NOTES ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/UPGRADING ${DOCDIR}

.	for d in ${PAXDIRS}
		${INSTALL_DATA_DIR} ${KRONOLITHDIR}/${d}
.	endfor

.	for d in ${PAXDIRS}
		cd ${WRKSRC}/${d} && ${PAX} -rwpma . ${KRONOLITHDIR}/${d}
.	endfor

	${INSTALL_DATA} ${WRKSRC}/config/*.dist ${KRONOLITHDIR}/config
	${INSTALL_DATA} ${WRKSRC}/*.php ${KRONOLITHDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${KRONOLITHDIR}
	${FIND} ${KRONOLITHDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${KRONOLITHDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${CHOWN} ${APACHE_USER}:${SHAREGRP} ${KRONOLITHDIR}/config
	${CHMOD} 0750 ${KRONOLITHDIR}/config

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
