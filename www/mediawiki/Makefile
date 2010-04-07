# $NetBSD: Makefile,v 1.11 2010/04/07 05:40:11 martti Exp $

DISTNAME=	mediawiki-${VER}.${PVER}
CATEGORIES=	www
MASTER_SITES=	http://download.wikimedia.org/mediawiki/${VER}/

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.mediawiki.org/
COMMENT=	Free software wiki package originally written for Wikipedia
LICENSE=	gnu-gpl-v2

EGDIR=			share/examples/mediawiki
MEDIAWIKI=		${PREFIX}/share/mediawiki

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	${EGDIR} share/mediawiki

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

PKG_INSTALLATION_TYPES=	overwrite pkgviews
VER=			1.15
PVER=			3

APACHE_USER?=		www
APACHE_GROUP?=		www
BUILD_DEFS+=		APACHE_USER APACHE_GROUP

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

CONF_FILES=		${PREFIX}/${EGDIR}/mediawiki.conf \
			${PKG_SYSCONFDIR}/mediawiki.conf

NO_CONFIGURE=		YES
NO_BUILD=		YES

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing pathnames in configuration file.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	../mediawiki.conf
SUBST_SED.paths=	-e "s,@MEDIAWIKI@,${MEDIAWIKI},g"

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-patch
SUBST_MESSAGE.perl=	Fixing path to perl
SUBST_FILES.perl+=	maintenance/postgres/compare_schemas.pl
SUBST_FILES.perl+=	maintenance/postgres/mediawiki_mysql2postgres.pl
SUBST_SED.perl=		-e "s|/usr/bin/perl|${PERL5}|"

post-extract:
	${CP} ${FILESDIR}/mediawiki.conf ${WRKDIR}/mediawiki.conf

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL_DATA_DIR} \
	  ${DESTDIR}${MEDIAWIKI}/{} \; -exec ${CHOWN} \
	  ${APACHE_USER}:${APACHE_GROUP} ${DESTDIR}${MEDIAWIKI}/{} \;
	cd ${WRKSRC} && ${FIND} . \! -type d -exec ${INSTALL_DATA} {} \
	  ${DESTDIR}${MEDIAWIKI}/{} \; -exec ${CHOWN} \
	  ${APACHE_USER}:${APACHE_GROUP} ${DESTDIR}${MEDIAWIKI}/{} \;
	${INSTALL_DATA} ${WRKDIR}/mediawiki.conf \
	  ${DESTDIR}${PREFIX}/${EGDIR}/mediawiki.conf

.include "../../lang/php/phpversion.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
