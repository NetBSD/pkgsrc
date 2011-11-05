# $NetBSD: Makefile,v 1.1.1.1 2011/11/05 15:49:53 ryoon Exp $
#

DISTNAME=	nanoblogger-3.4.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nanoblogger/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nanoblogger.sourceforge.net/
COMMENT=	Small weblog engine for the UNIX command line
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	tidy-[0-9]*:../../www/tidy

USE_LANGUAGES=	# none
USE_TOOLS+=	pax bash:run grep:run sed:run

NO_BUILD=	yes

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths+=		nb
SUBST_SED.fix-paths+=		-e 's,NB_BASE_DIR=`dirname $$0`,NB_BASE_DIR=${PREFIX}/share/nanoblogger,'

REPLACE_BASH=	nb

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nb ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/ && pax -rw -pp [a-z]* \
		${DESTDIR}${PREFIX}/share/nanoblogger

.include "../../mk/bsd.pkg.mk"
