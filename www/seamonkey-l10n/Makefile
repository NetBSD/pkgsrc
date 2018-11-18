# $NetBSD: Makefile,v 1.45 2018/11/18 07:16:48 ryoon Exp $
#

SM_VER=		2.49.4
PKGNAME=	seamonkey-l10n-${SM_VER:S/b/beta/}
DISTNAME=	# empty
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=seamonkey/releases/${SM_VER}/langpack/}
#MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=seamonkey/releases/${SM_VER}/langpack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.seamonkey-project.org/
COMMENT=	Language packs for www/seamonkey

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
