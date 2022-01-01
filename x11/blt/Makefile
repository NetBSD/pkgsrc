# $NetBSD: Makefile,v 1.37 2022/01/01 15:21:14 wiz Exp $

DISTNAME=	BLT2.4z
PKGNAME=	blt-2.4z
PKGREVISION=	12
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blt/}

PATCHFILES=		blt2.4z-patch-2
PATCH_SITES=		${MASTER_SITES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://blt.sourceforge.net/
COMMENT=	Extension to Tcl/Tk

MAKE_JOBS_SAFE=	no

WRKSRC=			${WRKDIR}/blt2.4z
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ENV+=		X11BASE=${X11BASE}
CONFIGURE_ENV+=		LDF=${LDFLAGS:Q}
CFLAGS+=		-DUSE_INTERP_RESULT
MAKE_ENV+=		CP=${CP:Q}

CHECK_INTERPRETER_SKIP+=	lib/*/demos/*.tcl

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
