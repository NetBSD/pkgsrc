# $NetBSD: Makefile,v 1.26 2016/03/25 21:02:26 joerg Exp $
#

DISTNAME=	Tix${TIX_VERSION}-src
TIX_VERSION=	8.4.3
PKGNAME=	tk-Tix-${TIX_VERSION}
PKGREVISION=	5
CATEGORIES=	x11 tcl tk
MASTER_SITES=	http://downloads.sourceforge.net/project/tix/tix/8.4.3/

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://tix.sourceforge.net/
COMMENT=	Powerful widget library for Tcl/Tk
LICENSE=	2-clause-bsd

MAKE_JOBS_SAFE=		no
WRKSRC=			${WRKDIR}/Tix8.4.3
GNU_CONFIGURE=		yes

.include "options.mk"

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ARGS+=	--disable-stubs
CONFIGURE_ARGS+=	--x-includes=${X11BASE:Q}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE:Q}/lib${LIBABISUFFIX:Q}
MAKE_ENV+=		TCL_DIR=${BUILDLINK_PREFIX.tcl}
MAKE_ENV+=		TK_DIR=${BUILDLINK_PREFIX.tk}
MAKE_ENV+=		LIBS=${X11_LDFLAGS:Q}
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}
TEST_TARGET=		test
INSTALLATION_DIRS+=	${PKGMANDIR}/mann
INSTALLATION_DIRS+=	lib/Tix${TIX_VERSION}/docs
USE_TOOLS+=		tar autoconf

CPPFLAGS+=	-DUSE_INTERP_RESULT

pre-configure:
	cd ${WRKSRC} && aclocal && autoconf

post-install:
	for f in ${WRKSRC}/man/*.n; do \
		${INSTALL_DATA} -m 444 $$f \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/mann; \
	done
	(cd ${WRKSRC}/docs; tar cf - . ) | \
		(cd ${DESTDIR}${PREFIX}/lib/Tix${TIX_VERSION}/docs; tar xfpB -)

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
