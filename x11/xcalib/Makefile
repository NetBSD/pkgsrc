# $NetBSD: Makefile,v 1.1.1.1 2011/10/30 19:56:56 jakllsch Exp $
#

DISTNAME=	xcalib-source-0.8
PKGNAME=	${DISTNAME:C/-source//}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcalib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xcalib.sourceforge.net/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME:C/-source//}

USE_LIBTOOL=		yes
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${CC} -c xcalib.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=link ${CC} \
		${LINKER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib \
		${LINKER_RPATH_FLAG}${BUILDLINK_PREFIX.libXxf86vm}/lib \
		-lm -lX11 -lXxf86vm \
		-o xcalib xcalib.lo

do-install:
	${SETENV} ${MAKE_ENV} ${LIBTOOL} --tag=CC --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/xcalib ${DESTDIR}${PREFIX}/bin/

.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
