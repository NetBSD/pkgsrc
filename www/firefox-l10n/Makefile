# $NetBSD: Makefile,v 1.45 2014/05/13 11:07:13 ryoon Exp $
#

FIREFOX_VER=	29.0.1
PKGNAME=	firefox-l10n-${FIREFOX_VER:S/esr//}
DISTNAME=	# empty
CATEGORIES=	www
#MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=firefox/releases/${FIREFOX_VER}/linux-i686/xpi/}
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/linux-i686/xpi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.com/en-US/firefox/
COMMENT=	Language packs for www/firefox (version 26.x)

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

FIREFOX_LOCALES=af ar as ast be bg bn-BD bn-IN br bs ca cs csb cy da	\
		de el en-GB en-US en-ZA eo es-AR es-CL es-ES es-MX et	\
		eu fa fi fr fy-NL ga-IE gd gl gu-IN he hi-IN hr hu	\
		hy-AM id is it ja kk kn ko ku lt lv mai mk ml mr	\
		nb-NO nl nn-NO or pa-IN pl pt-BR pt-PT rm ro ru	\
		si sk sl son sq sr sv-SE ta te th tr uk vi	\
		zh-CN zh-TW zu

EXTENSIONS_DIR=		${PREFIX}/lib/firefox/browser/extensions
XPI_FILES=		${FIREFOX_LOCALES:=.xpi}

.include "../../www/firefox/xpi.mk"
.include "../../mk/bsd.pkg.mk"
