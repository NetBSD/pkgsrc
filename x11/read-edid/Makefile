# $NetBSD: Makefile,v 1.2 2024/08/25 06:19:20 wiz Exp $

DISTNAME=	read-edid-3.0.2
CATEGORIES=	x11
MASTER_SITES=	http://www.polypux.org/projects/read-edid/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.polypux.org/projects/read-edid/
COMMENT=	Read EDID from monitor
LICENSE=	2-clause-bsd

USE_LANGUAGES+=		c c++
USE_CMAKE=		yes
CMAKE_CONFIGURE_ARGS+=		-DCLASSICBUILD=OFF
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_MANDIR=${PREFIX}${PKGMANDIR}
CONFIGURE_ENV+=		X86_LIBRARY=/usr/lib/libx86_64.so

.include "../../mk/bsd.pkg.mk"
