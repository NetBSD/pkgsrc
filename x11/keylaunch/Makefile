# $NetBSD: Makefile,v 1.20 2017/08/01 14:59:08 wiz Exp $
#

DISTNAME=	keylaunch_1.3.9
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	x11
MASTER_SITES=	http://www.oroborus.org/debian/dists/sid/main/source/x11/
MASTER_SITES+=	${MASTER_SITE_DEBIAN:=pool/main/k/keylaunch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.oroborus.org/?node=Download
COMMENT=	X utility for binding commands to a hot key
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

INSTALLATION_DIRS+=	bin share/examples/keylaunch

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keylaunch ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/example_rc \
		${DESTDIR}${PREFIX}/share/examples/keylaunch/keylaunch.rc

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
