# $NetBSD: Makefile,v 1.50 2020/05/21 20:11:12 ryoon Exp $
#

SM_VER=		2.53.2
PKGNAME=	seamonkey-l10n-${SM_VER:S/b/beta/}
DISTNAME=	# empty
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=seamonkey/releases/${SM_VER}/langpack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.seamonkey-project.org/
COMMENT=	Language packs for www/seamonkey

DEPENDS+=	seamonkey>=${PKGVERSION_NOREV}:../../www/seamonkey

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${SM_LOCALES:C/.*/seamonkey-${SM_VER}.&.langpack.xpi/}

NO_BUILD=	yes

SM_LOCALES=		cs de en-GB en-US es-AR es-ES fi fr	\
			hu it ja ka nb-NO nl pl pt-BR pt-PT ru	\
			sk sv-SE zh-CN zh-TW

EXTENSIONS_DIR=		${PREFIX}/lib/seamonkey/extensions

INSTALLATION_DIRS=	lib/seamonkey/extensions

do-install:
.for f in ${SM_LOCALES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f:C/.*/seamonkey-${SM_VER}.&.langpack.xpi/} \
		${DESTDIR}${EXTENSIONS_DIR}/langpack-${f}@seamonkey.mozilla.org.xpi
.endfor

.include "../../mk/bsd.pkg.mk"
