# $NetBSD: Makefile,v 1.7 2025/08/13 06:53:30 wiz Exp $

DISTNAME=	xsel-1.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=kfish/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vergenet.net/~conrad/software/xsel/
COMMENT=	Manipulate the X selection
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoconf automake pkg-config
USE_LIBTOOL=	yes

BUILDLINK_TRANSFORM+=	rm:-Werror

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xsel.1x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xsel.1

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
