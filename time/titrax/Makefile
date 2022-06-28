# $NetBSD: Makefile,v 1.40 2022/06/28 11:36:59 wiz Exp $
#

DISTNAME=		titrax-1.98
PKGREVISION=		17
CATEGORIES=		x11 time
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=office/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.alvestrand.no/titrax/TimeTracker.html
COMMENT=		Little X11 tool to track project times
LICENSE=		titrax-license

RESTRICTED=		Do not sell for "real money".
# XXX Arguably NO_*_ON_CDROM is not necessary, because "real money" seems
# to exclude CDROM distribution charges.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_IMAKE=		YES
USE_TOOLS+=		perl:run

pre-configure:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.bak
	${SED}	-e "s|@LOCALBASE@|${PREFIX}|g"			\
		${WRKSRC}/Imakefile.bak > ${WRKSRC}/Imakefile

INSTALLATION_DIRS=	libexec/titrax

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
