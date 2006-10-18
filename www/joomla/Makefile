# $NetBSD: Makefile,v 1.1.1.1 2006/10/18 17:48:31 ben Exp $
#

DISTNAME=	${PKGNAME:S/-/_/}-Stable-Full_Package
PKGNAME=	joomla-1.0.11
CATEGORIES=	www
MASTER_SITES=	http://forge.joomla.org/sf/frs/do/downloadFile/projects.joomla/frs.joomla_1_0.1_0_11/frs6656?dl=1/

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://www.joomla.org/
COMMENT=	Dynamic web content management system (CMS)

DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.2.0:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=4.2.0:../../archivers/php-zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MESSAGE_SUBST+=	PKGNAME_NOREV=${PKGNAME_NOREV:Q} \
		JOOMLA_CONFFILE=${JOOMLA_CONFFILE:Q}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

APACHE_USER?=	www
APACHE_GROUP?=	www
BUILD_DEFS+=	APACHE_USER APACHE_GROUP

EGDIR=			${PREFIX}/share/examples/joomla
JOOMLA_CONFDIR=		${PKG_SYSCONFDIR}/joomla
JOOMLA_CONFFILE=	${JOOMLA_CONFDIR}/joomla.conf
JOOMLA_DIR=		${PREFIX}/share/joomla

MAKE_DIRS=		${JOOMLA_CONFDIR}
CONF_FILES=		${EGDIR}/joomla.conf ${JOOMLA_CONFDIR}/joomla.conf
SPECIAL_PERMS=		${JOOMLA_CONFDIR}/joomla.conf ${APACHE_USER} \
			${APACHE_GROUP} 0644

NO_CONFIGURE=	yes
NO_BUILD=	yes

# distfile has .gz extension but bzip2 compression
# distfile does not extract to a subdirectory
# extract using bzip2 decompression to the WRKSRC subdirectory
EXTRACT_OPTS+=		-c bzip -d ${WRKSRC}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing pathnames in configuration file.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	../joomla.conf
SUBST_SED.paths=	-e "s,@JOOMLA_DIR@,${JOOMLA_DIR},g"

post-extract:
	${CP} ${FILESDIR}/joomla.conf ${WRKDIR}/joomla.conf

do-install:
	${INSTALL_DATA_DIR} ${JOOMLA_DIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL_DATA_DIR} \
	    ${JOOMLA_DIR}/{} \; -exec ${CHOWN} ${APACHE_USER}:${APACHE_GROUP} \
	    ${JOOMLA_DIR}/{} \;
	cd ${WRKSRC} && ${FIND} . \! -type d -exec ${INSTALL_DATA} {} \
	    ${JOOMLA_DIR}/{} \; -exec ${CHOWN} ${APACHE_USER}:${APACHE_GROUP} \
	    ${JOOMLA_DIR}/{} \;
	${INSTALL_DATA} ${WRKDIR}/joomla.conf ${EGDIR}/joomla.conf

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
