# $NetBSD: Makefile,v 1.4 2014/02/08 12:59:31 wiedi Exp $
#

DISTNAME=	xcalib-source-0.8
PKGREVISION=	1
PKGNAME=	${DISTNAME:C/-source//}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcalib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xcalib.sourceforge.net/
COMMENT=	Loads VCGT tag of monitor ICC profile into X server LUT
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME:C/-source//}

USE_LIBTOOL=		yes
INSTALLATION_DIRS=	bin

CFLAGS.SunOS+=		-Du_int16_t=uint16_t

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${CC} ${CFLAGS} -c xcalib.c
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
