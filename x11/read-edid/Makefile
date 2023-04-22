# $NetBSD: Makefile,v 1.1 2023/04/22 00:58:05 manu Exp $

DISTNAME=	read-edid-3.0.2
CATEGORIES=	x11
MASTER_SITES=	http://www.polypux.org/projects/read-edid/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.polypux.org/projects/read-edid/
COMMENT=	Read EDID from monitor
LICENSE=	2-clause-bsd

USE_LANGUAGES+=		c c++
USE_CMAKE=		yes
CMAKE_ARGS+=		-DCLASSICBUILD=OFF
CMAKE_ARGS+=		-DCMAKE_INSTALL_MANDIR=${PREFIX}${PKGMANDIR}
CONFIGURE_ENV+=		X86_LIBRARY=/usr/lib/libx86_64.so

.include "../../mk/bsd.pkg.mk"
