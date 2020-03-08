# $NetBSD: Makefile,v 1.9 2020/03/08 16:51:53 wiz Exp $
#

DISTNAME=	xicc-0.1
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://www.burtonini.com/computing/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.burtonini.com/computing/xicc
COMMENT=	Load ICC profile into X server
LICENSE=	generic-nonlicense

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${CC} \
		`pkg-config --cflags x11 glib-2.0` -c xicc.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=link ${CC} \
		`pkg-config --libs x11 glib-2.0` -o xicc xicc.lo

do-install:
	${LIBTOOL} --tag=CC --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/xicc ${DESTDIR}${PREFIX}/bin/

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
