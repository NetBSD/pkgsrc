# $NetBSD: Makefile,v 1.1 2020/09/11 13:27:43 leot Exp $

DISTNAME=	clipnotify-1.0.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=cdown/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/cdown/clipnotify/
COMMENT=	Notify on new X clipboard events
LICENSE=	public-domain

# Do not hardcode possible X11 {C,LD}FLAGS, they are passed by pkgsrc
MAKE_FLAGS+=	x11_bsd_flags=

INSTALLATION_DIRS=	bin share/doc/clipnotify

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clipnotify ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/clipnotify

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
