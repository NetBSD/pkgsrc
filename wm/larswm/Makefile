# $NetBSD: Makefile,v 1.14 2006/12/27 13:37:41 joerg Exp $
#

DISTNAME=	larswm-7.5.3
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	http://home.earthlink.net/~lab1701/larswm/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DOCFILES}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://home.earthlink.net/~lab1701/larswm/
COMMENT=	9wm-like window manager

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

DOCFILES=	keyboard_refcard.pdf mouse_refcard.pdf

USE_IMAKE=	YES

EGDIR=		${PREFIX}/share/examples/larswm
CONF_FILES=	${EGDIR}/sample.larswmrc ${PKG_SYSCONFDIR}/larswmrc

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=	-DPKG_SYSCONFDIR=\"${PKG_SYSCONFDIR:Q}\"

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	larswm.man
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-patch

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/larswm
.for pdf in ${DOCFILES}
	${INSTALL_DATA} ${DISTDIR}/${pdf} ${PREFIX}/share/doc/larswm
.endfor
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.* ${EGDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
