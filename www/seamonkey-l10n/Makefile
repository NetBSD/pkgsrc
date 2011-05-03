# $NetBSD: Makefile,v 1.3 2011/05/03 12:15:18 tnn Exp $
#

SM_VER=		2.0.14
PKGNAME=	seamonkey-l10n-${SM_VER}
DISTNAME=	# empty
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=seamonkey/releases/${SM_VER}/langpack/}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.seamonkey-project.org/
COMMENT=	Language packs for www/seamonkey

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

SM_LOCALES=		be ca cs de es-AR es-ES fr gl hu it		\
			ja ka lt nb-NO nl pl pt-PT ru sk sv-SE		\
			tr

EXTENSIONS_DIR=		${PREFIX}/lib/seamonkey/extensions
XPI_FILES=		${SM_LOCALES:C/.*/seamonkey-${SM_VER}.&.langpack.xpi/}

.include "../../devel/xulrunner/xpi.mk"
.include "../../mk/bsd.pkg.mk"
