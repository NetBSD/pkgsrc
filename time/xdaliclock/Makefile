# $NetBSD: Makefile,v 1.9 2009/07/07 19:49:51 joerg Exp $
#

DISTNAME=		xdaliclock-2.18
PKGREVISION=		1
CATEGORIES=		x11 time
MASTER_SITES=		http://www.jwz.org/xdaliclock/ \
			${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.jwz.org/xdaliclock/
COMMENT=		Animated digital clock

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/X11
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	install_prefix=${DESTDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
