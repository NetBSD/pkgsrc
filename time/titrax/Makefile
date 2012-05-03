# $NetBSD: Makefile,v 1.25 2012/05/03 09:55:31 obache Exp $
#

DISTNAME=		titrax-1.98
PKGREVISION=		6
CATEGORIES=		x11 time
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=office/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.alvestrand.no/titrax/TimeTracker.html
COMMENT=		Little X11 tool to track project times
LICENSE=		titrax-license

PKG_DESTDIR_SUPPORT=	user-destdir

RESTRICTED=		Do not sell for "real money".
# XXX Arguably NO_*_ON_CDROM is not necessary, because "real money" seems
# to exclude CDROM distribution charges.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_IMAKE=		YES
USE_TOOLS+=		perl:run

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.bak
	${SED}	-e "s|@LOCALBASE@|${LOCALBASE}|g"			\
		-e "s|@X11BASE@|${X11PREFIX}|g"				\
		${WRKSRC}/Imakefile.bak > ${WRKSRC}/Imakefile

INSTALLATION_DIRS=	libexec/titrax

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
