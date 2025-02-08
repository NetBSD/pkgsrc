# $NetBSD: Makefile,v 1.96 2025/02/08 04:00:54 taca Exp $

DISTNAME=	mediawiki-${VER}.${PVER}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://releases.wikimedia.org/mediawiki/${VER}/

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://www.mediawiki.org/
COMMENT=	Free software wiki package originally written for Wikipedia
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=${PHP_BASE_VERS}:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring

PHP_VERSION_ACCEPTED=	81 82 83

EGDIR=			share/examples/mediawiki
MEDIAWIKI=		${PREFIX}/share/mediawiki
INSTALLATION_DIRS=	${EGDIR} share/mediawiki

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

VER=			1.42
PVER=			3

BUILD_DEFS+=		APACHE_USER APACHE_GROUP

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

CONF_FILES=		${PREFIX}/${EGDIR}/mediawiki.conf \
			${PKG_SYSCONFDIR}/mediawiki.conf

NO_CONFIGURE=		YES
NO_BUILD=		YES

post-extract:
	${CP} ${FILESDIR}/mediawiki.conf ${WRKDIR}/mediawiki.conf

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL_DATA_DIR} \
	  ${DESTDIR}${MEDIAWIKI}/{} \; -exec ${CHOWN} \
	  ${APACHE_USER}:${APACHE_GROUP} ${DESTDIR}${MEDIAWIKI}/{} \;
	cd ${WRKSRC} && ${FIND} . \! -type d \! -name '.git*' \
	  -exec ${INSTALL_DATA} {} ${DESTDIR}${MEDIAWIKI}/{} \; \
	  -exec ${CHOWN} ${APACHE_USER}:${APACHE_GROUP} \
	  ${DESTDIR}${MEDIAWIKI}/{} \;
	${INSTALL_DATA} ${WRKDIR}/mediawiki.conf \
	  ${DESTDIR}${PREFIX}/${EGDIR}/mediawiki.conf

.include "../../lang/php/json.mk"
.include "../../mk/bsd.pkg.mk"
