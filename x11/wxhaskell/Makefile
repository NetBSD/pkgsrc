# $NetBSD: Makefile,v 1.51 2014/05/05 00:48:34 ryoon Exp $

DISTNAME=	wxhaskell-src-0.9.4
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	33
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxhaskell/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://haskell.org/haskellwiki/WxHaskell
COMMENT=	Haskell wxGTK bindings

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

MAKE_FILE=		makefile
MAKE_FLAGS+=		X11BASE=${X11BASE:Q}

# I don't know where that number comes from, but it changes sometimes.
PLIST_SUBST+=		GTKVERSION=2.6.3
CHECK_FILES_SKIP+=	lib/ghc-6.4.1/package.conf.old

post-extract:
	${SED} < ${FILESDIR}/fixup.sh > ${WRKSRC}/fixup.sh \
		-e s,@WRKSRC@,${WRKSRC:Q},g

pre-configure:
	cd ${WRKSRC} && ./configure --prefix=${PREFIX} --with-opengl

INSTALL_TARGET=	install-files

.include "../../lang/ghc/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/wxGTK26/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
