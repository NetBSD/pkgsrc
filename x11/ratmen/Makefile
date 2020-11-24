# $NetBSD: Makefile,v 1.6 2020/11/24 17:33:29 nia Exp $

DISTNAME=	ratmen-2.2.3
CATEGORIES=	x11 wm
MASTER_SITES=	https://www.update.uu.se/~zrajm/programs/ratmen/

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	https://www.update.uu.se/~zrajm/programs/
COMMENT=	Allows you to create X menus from the shell
LICENSE=	9menu-license

USE_TOOLS+=	gmake pod2man

MAKE_FLAGS+=	PREFIX="${DESTDIR}${PREFIX}"
MAKE_FLAGS+=	MANDIR="${DESTDIR}${PREFIX}/${PKGMANDIR}"
MAKE_FLAGS+=	CC=${CC}
MAKE_FLAGS+=	OPTIMIZE=
MAKE_FLAGS+=	CFLAGS="${CFLAGS} ${LDFLAGS}"

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
