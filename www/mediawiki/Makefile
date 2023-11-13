# $NetBSD: Makefile,v 1.91 2023/11/13 16:34:03 taca Exp $

DISTNAME=	mediawiki-${VER}.${PVER}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://releases.wikimedia.org/mediawiki/${VER}/

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://www.mediawiki.org/
COMMENT=	Free software wiki package originally written for Wikipedia
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=7.3.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=7.3.0:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=7.3.0:../../converters/php-mbstring

EGDIR=			share/examples/mediawiki
MEDIAWIKI=		${PREFIX}/share/mediawiki
INSTALLATION_DIRS=	${EGDIR} share/mediawiki

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

VER=			1.39
PVER=			1

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
