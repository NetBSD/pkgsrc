# $NetBSD: Makefile,v 1.1.1.1 2007/05/30 14:01:47 obache Exp $

DISTNAME=	xxkb-1.11-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xxkb/} \
		http://pascal.tsu.ru/other/xxkb/

MAINTAINER=	cheusov@tut.by
# Unfortunately home page is currently written in Russian language
# only.  See http://pascal.tsu.ru/en/ for English translation updates.
HOMEPAGE=	http://pascal.tsu.ru/other/xxkb/
COMMENT=	XXKB - switches and indicates a current keyboard layout

USE_TOOLS+=		xmkmf
USE_IMAKE=		yes
DOC_FILES=		LICENSE README.koi8 README
DOC_DIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	${DOC_DIR}

WRKSRC=			${WRKDIR}/xxkb

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOC_DIR}
.endfor

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
