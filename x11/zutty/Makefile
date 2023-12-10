# $NetBSD: Makefile,v 1.1 2023/12/10 11:46:08 wiz Exp $

DISTNAME=	zutty-0.14
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=tomscii/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tomscii.sig7.se/zutty/
COMMENT=	High-end terminal for low-end systems
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config
WAF_HAS_MANDIR=	no

INSTALLATION_DIRS+=	share/doc/zutty

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.org ${DESTDIR}${PREFIX}/share/doc/zutty

.include "../../devel/waf/waf.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
