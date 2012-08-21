# $NetBSD: Makefile,v 1.66 2012/08/21 21:32:34 marino Exp $

DISTNAME=	tk${TK_VERSION}-src
PKGNAME=	tk-${TK_VERSION}
CATEGORIES=	x11 lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Graphical toolkit for TCL
LICENSE=	2-clause-bsd

.include "../../x11/tk/Makefile.version"

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/tk${TK_VERSION}

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ENV+=		LIB_RUNTIME_DIR=${PREFIX}/lib
PTHREAD_OPTS+=		require

TEST_TARGET=		test

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

SUBST_CLASSES+=		tk-config
SUBST_STAGE.tk-config=	post-build
SUBST_FILES.tk-config=	unix/tkConfig.sh
SUBST_SED.tk-config+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tk-config+=	-e "s|${WRKSRC}|${PREFIX}/include/tk|"

PLIST_SUBST+=		SONUM=${TK_SONUM}
PLIST_SUBST+=		BASEVER=${TK_BASEVER}


#post-install:
#	ln -s wish${TK_BASEVER} ${DESTDIRPREFIX:Q}/bin/wish

.include "../../mk/bsd.pkg.mk"
