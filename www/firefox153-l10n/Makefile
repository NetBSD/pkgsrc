# $NetBSD: Makefile,v 1.1 2026/08/27 01:28:40 gutteridge Exp $

FIREFOX_VER=	153.1.0esr
PKGNAME=	firefox153-l10n-${FIREFOX_VER:S/b/beta/:S/esr//}
DISTNAME=	# empty
CATEGORIES=	www
#MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=firefox/releases/${FIREFOX_VER}/linux-x86_64/xpi/}
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/linux-x86_64/xpi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mozilla.com/en-US/firefox/
COMMENT=	Language packs for www/firefox153
LICENSE=	mpl-2.0 # as of 153

DEPENDS+=	firefox153>=${PKGVERSION_NOREV}:../../www/firefox153

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${FIREFOX_LOCALES:=.xpi}

NO_BUILD=	yes

INSTALLATION_DIRS=	lib/firefox153/distribution/extensions

FIREFOX_LOCALES= \
	ach af an ar ast az be bg bn br bs ca-valencia ca cak cs cy	\
	da de dsb	\
	el en-CA en-GB en-US eo es-AR es-CL es-ES es-MX et eu		\
	fa ff fi fr fur fy-NL ga-IE gd gl gn gu-IN			\
	he hi-IN hr hsb hu hy-AM ia id is it ja ka kab kk km kn	ko	\
	lij lt lv mk mr ms my nb-NO ne-NP nl nn-NO oc			\
	pa-IN pl pt-BR pt-PT rm ro ru sat sc sco si sk skr sl son sq sr	\
	sv-SE szl ta te tg th tl tr trs uk ur uz vi xh zh-CN zh-TW

EXTENSIONS_DIR=		${PREFIX}/lib/firefox153/distribution/extensions

do-install:
.for locale in ${FIREFOX_LOCALES}
	${INSTALL_DATA} ${WRKSRC}/${locale}.xpi \
	${DESTDIR}${EXTENSIONS_DIR}/langpack-${locale}@firefox.mozilla.org.xpi
.endfor

.if make(list-licenses)
.include "list-licenses.mk"
.endif

.include "../../mk/bsd.pkg.mk"
