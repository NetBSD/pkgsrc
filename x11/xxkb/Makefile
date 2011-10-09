# $NetBSD: Makefile,v 1.7 2011/10/09 10:02:44 cheusov Exp $

DISTNAME=	xxkb-1.11-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xxkb/}

MAINTAINER=	cheusov@NetBSD.org
# Unfortunately home page is currently written in Russian language
# only.  See http://pascal.tsu.ru/en/ for English translation updates.
HOMEPAGE=	http://pascal.tsu.ru/other/xxkb/
COMMENT=	XXKB - switches and indicates a current keyboard layout
LICENSE=	artistic

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		xmkmf
USE_IMAKE=		yes
DOC_FILES=		LICENSE README.koi8 README
DOC_DIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	${DOC_DIR}

MAKE_FLAGS+=		MANPATH=${PREFIX}/${PKGMANDIR}

WRKSRC=			${WRKDIR}/xxkb

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${DOC_DIR}
.endfor

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
