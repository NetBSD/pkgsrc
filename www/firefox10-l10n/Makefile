# $NetBSD: Makefile,v 1.12 2013/12/30 00:24:07 dholland Exp $
#

FIREFOX_VER=	10.0.12
PKGNAME=	firefox10-l10n-${FIREFOX_VER}
DISTNAME=	# empty
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA_ESR:=firefox/releases/${FIREFOX_VER}esr/linux-i686/xpi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/en-US/firefox/organizations/
COMMENT=	Language packs for www/firefox10 (version 10.x)

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

FIREFOX_LOCALES=af ak ar as ast be bg bn-BD bn-IN br bs ca cs csb cy da	\
		de el en-GB en-US en-ZA eo es-AR es-CL es-ES es-MX et	\
		eu fa fi fr fy-NL ga-IE gd gl gu-IN he hi-IN hr hu	\
		hy-AM id is it ja kk kn ko ku lg lt lv mai mk ml mr	\
		nb-NO nl nn-NO nso or pa-IN pl pt-BR pt-PT rm ro ru	\
		si sk sl son sq sr sv-SE ta-LK ta te th tr uk vi	\
		zh-CN zh-TW zu

EXTENSIONS_DIR=		${PREFIX}/lib/firefox10/extensions
XPI_FILES=		${FIREFOX_LOCALES:=.xpi}

.include "../../devel/xulrunner10/xpi.mk"
.include "../../mk/bsd.pkg.mk"
