# $NetBSD: Makefile,v 1.2 2024/02/01 10:29:00 wiz Exp $

DISTNAME=	7e481c04507e9b5cacfe67fe2b96bdb449b08726
PKGNAME=	zutty-0.15
CATEGORIES=	x11
MASTER_SITES=	https://git.hq.sig7.se/zutty.git/snapshot/
DIST_SUBDIR=	zutty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tomscii.sig7.se/zutty/
COMMENT=	High-end terminal for low-end systems
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config
WAF_HAS_MANDIR=	no

INSTALLATION_DIRS+=	share/doc/zutty

WRKSRC=		${WRKDIR}/zutty-${DISTNAME:C/(.......).*/\1/}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.org ${DESTDIR}${PREFIX}/share/doc/zutty

.include "../../devel/waf/waf.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
