# $NetBSD: Makefile,v 1.4 2020/01/18 23:35:44 rillig Exp $
#

DISTNAME=	nanoblogger-extra-3.4.2
CATEGORIES=	www
MASTER_SITES=	http://nanoblogger.sourceforge.net/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nanoblogger.sourceforge.net/
COMMENT=	Collection of various contributions and add-ons for nanoblogger
LICENSE=	gnu-gpl-v2

DEPENDS+=	nanoblogger-3.4.2{,nb*}:../../www/nanoblogger

NO_CONFIGURE=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/nanoblogger-3.4.2
USE_LANGUAGES=	# none

USE_TOOLS+=	pax

INSTDIR=		${PREFIX}/share/nanoblogger
INSTALLATION_DIRS=	${INSTDIR}

do-install:
	set -e; cd ${WRKSRC} && pax -rw default docs lang plugins \
		${DESTDIR}${INSTDIR}
.include "../../mk/bsd.pkg.mk"
