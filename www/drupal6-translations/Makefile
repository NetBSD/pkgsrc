# $NetBSD: Makefile,v 1.13 2010/05/26 17:18:56 taca Exp $
#

DISTNAME=	drupal6-translations-20100527
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/
DISTFILES=	${DL_DISTFILES}
DIST_SUBDIR=	drupal6-${STAMP}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drupal.org/project/Translations
COMMENT=	Langate translation files for drupal 6.x
LICENSE=	gnu-gpl-v2

#DEPENDS+=	drupal>=6.3:../../www/drupal6

#
# update STAMP when any distfile's content changed without its filename.
STAMP=		20080816
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes
EXTRACT_DIR=	${WRKSRC}
WRKSRC=		${WRKDIR}/drupal

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SUBST+=	DRUPAL_BASE=${DRUPAL_BASE:Q}

.include "options.mk"

DRUPAL_BASE?=	share/drupal

pre-install:
	cd ${WRKSRC}; ${CHMOD} ${NONBINMODE} *.txt
	cd ${WRKSRC}; ${RM} -fr drupal google_groups

do-install:
	cd ${WRKSRC}; pax -rw . ${DESTDIR}${PREFIX}/${DRUPAL_BASE}

.include "../../mk/bsd.pkg.mk"
