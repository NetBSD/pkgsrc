# $NetBSD: Makefile,v 1.12 2019/06/21 16:39:34 ryoon Exp $
#

FIREFOX_VER=	60.7.2esr
PKGNAME=	firefox60-l10n-${FIREFOX_VER:S/esr//}
DISTNAME=	# empty
CATEGORIES=	www
#MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=firefox/releases/${FIREFOX_VER}/linux-i686/xpi/}
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/linux-i686/xpi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mozilla.com/en-US/firefox/
COMMENT=	Language packs for www/firefox60 (version ${PKGVERSION_NOREV:C/\..*//})

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

INSTALLATION_DIRS=	lib/firefox60/browser/extensions

FIREFOX_LOCALES=ach af an ar as ast az be bg bn-BD bn-IN br bs ca cs	\
		cy da de dsb el en-GB en-ZA eo es-AR es-CL es-ES 	\
		es-MX et eu fa ff fi fr fy-NL ga-IE gd gl gn gu-IN	\
		he hi-IN hr hsb hu hy-AM id is it ja ka kab kk km kn ko	\
		lij lt lv mai mk ml mr ms my nb-NO ne-NP nl nn-NO oc or	\
		pa-IN pl en-US	\
		pt-BR pt-PT rm ro ru si sk sl son sq sr sv-SE ta te th	\
		tr uk uz vi xh zh-CN zh-TW

EXTENSIONS_DIR=		${PREFIX}/lib/firefox60/browser/extensions
XPI_FILES=		${FIREFOX_LOCALES:=.xpi}

do-install:
.for f in ${FIREFOX_LOCALES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f}.xpi \
	${DESTDIR}${EXTENSIONS_DIR}/langpack-${f}@firefox.mozilla.org.xpi
.endfor

.include "../../mk/bsd.pkg.mk"
