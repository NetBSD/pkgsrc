# $NetBSD: Makefile,v 1.11 2012/10/08 13:04:31 asau Exp $
#

DISTNAME=		xdaliclock-2.30
CATEGORIES=		x11 time
MASTER_SITES=		http://www.jwz.org/xdaliclock/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.jwz.org/xdaliclock/
COMMENT=		Animated digital clock
LICENSE=		mit

WRKSRC=			${WRKDIR}/${DISTNAME}/X11
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	install_prefix=${DESTDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
