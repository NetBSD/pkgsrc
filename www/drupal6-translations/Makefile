# $NetBSD: Makefile,v 1.1.1.1 2008/08/17 05:35:04 taca Exp $
#

DISTNAME=	drupal6-translations-${STAMP}
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/
DISTFILES=	ar-6.x-1.x-dev.tar.gz \
		zh-hans-6.x-1.0.tar.gz \
		zh-hant-6.x-1.1.tar.gz cs-6.x-1.8.tar.gz \
		da-6.x-1.x-dev.tar.gz nl-6.x-1.1.tar.gz \
		fi-6.x-1.0-rc.tar.gz \
		fr-6.x-1.x-dev.tar.gz de-6.x-1.x-dev.tar.gz \
		el-6.x-1.0-beta1.tar.gz gu-6.x-1.x-dev.tar.gz \
		he-6.x-1.0.tar.gz hu-6.x-1.0.tar.gz ja-6.x-1.2.tar.gz \
		lt-6.x-1.2.tar.gz nb-6.x-1.x-dev.tar.gz \
		nn-6.x-1.x-dev.tar.gz pt-br-6.x-1.0-rc1.tar.gz \
		pt-pt-6.x-1.x-dev.tar.gz ro-6.x-1.1.tar.gz \
		sk-6.x-1.0-beta5.tar.gz es-6.x-1.0.tar.gz \
		sv-6.x-1.x-dev.tar.gz th-6.x-1.x-dev.tar.gz \
		tr-6.x-1.x-dev.tar.gz
DIST_SUBDIR=	drupal6-${STAMP}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drupal.org/project/Translations
COMMENT=	Langate translation files for drupal 6.x

DEPENDS+=	drupal>=6.3:../../www/drupal6

STAMP=		20080816
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes
EXTRACT_DIR=	${WRKSRC}
WRKSRC=		${WRKDIR}/drupal

PKG_DESTDIR_SUPPORT=	user-destdir

# Translation files for Esperanto(eo) and Vietnam(vi) also exist,
# but contain wrong directory names.
LANG_SUPPORTED=	ar cs da de el es fi fr gu he hu ja lt nb nl nn \
		pt-br pt-pt ro sk sv th tr zh-hans zh-hant
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
