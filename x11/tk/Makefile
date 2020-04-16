# $NetBSD: Makefile,v 1.87 2020/04/16 17:07:07 adam Exp $

DISTNAME=	tk${TK_VERSION}-src
PKGNAME=	tk-${TK_VERSION}
CATEGORIES=	x11 lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tcl.tk/
COMMENT=	Graphical toolkit for TCL
LICENSE=	2-clause-bsd

.include "../../x11/tk/Makefile.version"

WRKSRC=			${WRKDIR}/tk${TK_VERSION}

USE_GCC_RUNTIME=	yes

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib${LIBABISUFFIX:Q}
CONFIGURE_ENV+=		LIB_RUNTIME_DIR=${PREFIX}/lib
PTHREAD_OPTS+=		require

PKGCONFIG_OVERRIDE+=	unix/tk.pc.in

TEST_TARGET=		test

.if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

.include "options.mk"

SUBST_CLASSES+=		tk-config
SUBST_STAGE.tk-config=	post-build
SUBST_FILES.tk-config=	unix/tkConfig.sh
SUBST_SED.tk-config+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tk-config+=	-e "s|${WRKSRC}|${PREFIX}/include/tk|"

PLIST_SUBST+=		SONUM=${TK_SONUM}
PLIST_SUBST+=		BASEVER=${TK_BASEVER}

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
