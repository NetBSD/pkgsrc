# $NetBSD: Makefile,v 1.12 2014/12/04 04:55:13 mef Exp $
#

DISTNAME=		xdaliclock-2.41
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
