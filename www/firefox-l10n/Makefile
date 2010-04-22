# $NetBSD: Makefile,v 1.1.1.1 2010/04/22 16:57:53 tnn Exp $
#

FIREFOX_VER=	3.6.3
PKGNAME=	firefox-l10n-${FIREFOX_VER}
DISTNAME=	# empty
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/linux-i686/xpi/}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.mozilla.com/en-US/firefox/
COMMENT=	Language packs for www/firefox

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

FIREFOX_LOCALES=	af ar as be bg bn-BD bn-IN ca cs cy		\
			da de el en-GB eo es-AR es-CL es-ES es-MX et	\
			eu fa fi fr fy-NL ga-IE gl gu-IN he hi-IN	\
			hr hu id is it ja ka kk kn ko			\
			ku lt lv mk ml mr nb-NO nl nn-NO oc		\
			or pa-IN pl pt-BR pt-PT rm ro ru si sk		\
			sl sq sr sv-SE ta te th tr uk			\
			vi zh-CN zh-TW
# ta-LK is broken

EXTENSIONS_DIR=		${PREFIX}/lib/firefox/extensions
XPI_FILES=		${FIREFOX_LOCALES:=.xpi}

.include "../../devel/xulrunner/xpi.mk"
.include "../../mk/bsd.pkg.mk"
