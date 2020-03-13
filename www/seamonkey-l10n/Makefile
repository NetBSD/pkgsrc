# $NetBSD: Makefile,v 1.48 2020/03/13 15:50:07 nia Exp $
#

SM_VER=		2.49.5
PKGNAME=	seamonkey-l10n-${SM_VER:S/b/beta/}
DISTNAME=	# empty
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=seamonkey/releases/${SM_VER}/langpacks/linux-i686/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.seamonkey-project.org/
COMMENT=	Language packs for www/seamonkey

DEPENDS+=	seamonkey>=${PKGVERSION_NOREV}:../../www/seamonkey

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

SM_LOCALES=		cs de en-GB en-US es-AR es-ES fr	\
			it ja lt nl pl pt-PT ru sk		\
			sv-SE zh-CN zh-TW

EXTENSIONS_DIR=		${PREFIX}/lib/seamonkey/extensions
XPI_FILES=		${SM_LOCALES:C/.*/seamonkey-${SM_VER}.&.langpack.xpi/}

.include "../../www/firefox52/xpi.mk"
.include "../../mk/bsd.pkg.mk"
