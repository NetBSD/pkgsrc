# $NetBSD: Makefile,v 1.3 2018/07/20 03:03:57 wen Exp $

DISTNAME=	Joomla_3.8.10-Stable-Full_Package
PKGNAME=	joomla-3.8.10
CATEGORIES=	www
MASTER_SITES=	https://downloads.joomla.org/cms/joomla3/3-8-10/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://www.joomla.org/
COMMENT=	Dynamic web content management system (CMS)
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.6.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.6.0:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.6.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=5.6.0:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.6.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.6.0:../../archivers/php-zlib

PKG_DESTDIR_SUPPORT=	destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=		www
APACHE_GROUP?=		www
BUILD_DEFS+=		APACHE_USER APACHE_GROUP

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/joomla
JOOMLADIR=		${PREFIX}/share/joomla

CONF_FILES=		${EGDIR}/joomla.conf ${PKG_SYSCONFDIR}/joomla.conf

NO_CONFIGURE=		yes
NO_BUILD=		yes

# distfile does not extract to a subdirectory
# extract using bzip2 decompression to the WRKSRC subdirectory
EXTRACT_OPTS+=		-c bzip -d ${WRKSRC}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing pathnames in configuration file.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	../joomla.conf
SUBST_SED.paths=	-e "s,@JOOMLADIR@,${JOOMLADIR},g"

post-extract:
	${CP} ${FILESDIR}/joomla.conf ${WRKDIR}/joomla.conf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${JOOMLADIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	cd ${WRKSRC} && ${FIND} . -type d \
	  -exec ${INSTALL_DATA_DIR} ${DESTDIR}${JOOMLADIR}/{} \; \
	  -exec ${CHOWN} ${APACHE_USER}:${APACHE_GROUP} \
	    ${DESTDIR}${JOOMLADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . \! -type d \
	  -exec ${INSTALL_DATA} {} ${DESTDIR}${JOOMLADIR}/{} \; \
	  -exec ${CHOWN} ${APACHE_USER}:${APACHE_GROUP} \
	    ${DESTDIR}${JOOMLADIR}/{} \;
	${INSTALL_DATA} ${WRKDIR}/joomla.conf ${DESTDIR}${EGDIR}/joomla.conf

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
