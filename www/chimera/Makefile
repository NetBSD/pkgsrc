# $NetBSD: Makefile,v 1.27 2011/01/13 13:39:37 wiz Exp $
#

DISTNAME=	chimera-2.0a19
PKGREVISION=	10
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cs.unlv.edu/pub/chimera-alpha/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.chimera.org/
COMMENT=	World Wide Web Browser for X Windows

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

pre-configure:
	cd ${WRKSRC} && ${SED}					\
	    -e 's|@@LOCALBASE@@|${LOCALBASE}|'			\
	    -e 's|@@PREFIX@@|${PREFIX}|'			\
	    -e 's|@@X11BASE@@|${X11BASE}|'			\
	    Common.tmpl.dist > Common.tmpl

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/chimera
	cd ${WRKSRC}/doc && ${INSTALL_DATA}			\
	    HINTS INFO LICENSE ${DESTDIR}${PREFIX}/share/doc/chimera

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
