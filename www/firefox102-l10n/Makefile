# $NetBSD: Makefile,v 1.16 2023/11/23 14:23:56 ryoon Exp $

FIREFOX_VER=	102.15.1esr
PKGNAME=	firefox102-l10n-${FIREFOX_VER:S/esr//}
DISTNAME=	# empty
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/linux-i686/xpi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mozilla.com/en-US/firefox/
COMMENT=	Language packs for www/firefox (version ${PKGVERSION_NOREV:C/\..*//})

DEPENDS+=	firefox102>=${PKGVERSION_NOREV}:../../www/firefox102

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

INSTALLATION_DIRS=	lib/${PKGBASE:S/-l10n//g}/browser/extensions

FIREFOX_LOCALES=	ach af an ar ast az be bg bn br bs ca cak	\
			cs cy da de dsb el en-CA en-GB en-US eo es-AR	\
			es-CL es-ES 	\
			es-MX et eu fa ff fi fr fy-NL ga-IE gd gl gn gu-IN	\
			he hi-IN hr hsb hu hy-AM ia id is it ja ka kab kk km kn	\
			ko	\
			lij lt lv mk mr ms my nb-NO ne-NP nl nn-NO oc \
			pa-IN pl	\
			pt-BR pt-PT rm ro ru si sk sl son sq sr sv-SE ta te th	\
			tr uk uz vi xh zh-CN zh-TW

EXTENSIONS_DIR=		${PREFIX}/lib/${PKGBASE:S/-l10n//g}/browser/extensions
XPI_FILES=		${FIREFOX_LOCALES:=.xpi}

do-install:
.for f in ${FIREFOX_LOCALES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f}.xpi \
	${DESTDIR}${EXTENSIONS_DIR}/langpack-${f}@firefox.mozilla.org.xpi
.endfor

.include "../../mk/bsd.pkg.mk"
