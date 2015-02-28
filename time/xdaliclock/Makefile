# $NetBSD: Makefile,v 1.13 2015/02/28 23:47:03 joerg Exp $
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

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/config.sub

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	install_prefix=${DESTDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
