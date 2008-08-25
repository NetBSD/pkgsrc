# $NetBSD: Makefile,v 1.3 2008/08/25 12:50:52 taca Exp $
#

DISTNAME=	drupal6-translations-20080826
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/
DISTFILES=	zh-hans-6.x-1.0.tar.gz zh-hant-6.x-1.1.tar.gz \
		cs-6.x-1.8.tar.gz nl-6.x-1.1.tar.gz fi-6.x-1.0-rc.tar.gz \
		de-6.x-1.0-rc1.tar.gz el-6.x-1.0-beta1.tar.gz \
		he-6.x-1.0.tar.gz hu-6.x-1.0.tar.gz ja-6.x-1.2.tar.gz \
		lt-6.x-1.2.tar.gz pt-br-6.x-1.0-rc1.tar.gz ro-6.x-1.1.tar.gz \
		sk-6.x-1.0-beta5.tar.gz es-6.x-1.0.tar.gz
DIST_SUBDIR=	drupal6-${STAMP}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drupal.org/project/Translations
COMMENT=	Langate translation files for drupal 6.x

DEPENDS+=	drupal>=6.3:../../www/drupal6

#
# update STAMP when any distfile's content changed without its filename.
STAMP=		20080816
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes
EXTRACT_DIR=	${WRKSRC}
WRKSRC=		${WRKDIR}/drupal

PKG_DESTDIR_SUPPORT=	user-destdir

# Broken directory structure: eo vi
# development version only: ar da fr gu nb nn pt-pt sv th tr
LANG_SUPPORTED=	cs de el es fi he hu ja lt nl nn \
		pt-br ro sk sv th tr zh-hans zh-hant
PLIST_SUBST+=	DRUPAL_BASE=${DRUPAL_BASE:Q}

.for l in ${LANG_SUPPORTED}
PLIST_SRC+=	PLIST.${l}
.endfor
PLIST_SRC+=	PLIST.common_end

.include "../../mk/bsd.prefs.mk"

DRUPAL_BASE?=	share/drupal

pre-install:
	cd ${WRKSRC}; ${CHMOD} ${NONBINMODE} *.txt

do-install:
	cd ${WRKSRC}; pax -rw . ${DESTDIR}${PREFIX}/${DRUPAL_BASE}

.include "../../mk/bsd.pkg.mk"
