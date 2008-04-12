# $NetBSD: Makefile,v 1.50 2008/04/12 22:43:13 jlam Exp $

DISTNAME=	amaya-fullsrc-9.2.1
PKGNAME=	${DISTNAME:S/-fullsrc//}
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/Amaya/Distribution/ \
		ftp://ftp.w3.org/pub/amaya/ \
		ftp://mirror.aarnet.edu.au/pub/amaya/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.w3.org/Amaya/
COMMENT=	Web browser/editor from the World Wide Web Consortium (W3C)

EXTRACT_ELEMENTS=	Amaya libwww
WRKSRC=			${WRKDIR}/Amaya/work

USE_DIRS+=		xdg-1.1
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--without-graphic-libs	# Use pkgsrc libraries
CFLAGS+=		-Dunix
# link correctly with pkgsrc zlib
LIBS+=			${COMPILER_RPATH_FLAG}${LOCALBASE}/lib

FONTS_DIRS.ttf+=	${PREFIX}/share/Amaya/fonts
REQD_DIRS+=		${PREFIX}/share/Amaya ${PREFIX}/share/Amaya/fonts

.include "../../mk/bsd.prefs.mk"

# GNOME/KDE integration (only for Linux)
PLIST_VARS+=	desktop
.if ${OPSYS} == "Linux"
PLIST.desktop=	yes
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-configure:
	${CP} ${WRKSRC}/Options.orig ${WRKSRC}/Options
	${TOUCH} ${WRKSRC}/Makefile

.include "../../graphics/imlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
