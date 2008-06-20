# $NetBSD: Makefile,v 1.11 2008/06/20 01:09:40 joerg Exp $
#

DISTNAME=	weewm-0.0.2
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	http://weewm.flashtux.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://weewm.flashtux.org/
COMMENT=	Fast and ultra light windowmanager with total keyboard control

PKG_DESTDIR_SUPPORT=	user-destdir

EXAMPLESDIR=	${PREFIX}/share/examples/weewm
DOCDIR=		${PREFIX}/share/doc/weewm

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/weewm \
			share/doc/weewm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/weewm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/weewm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/examples/config.rc ${DESTDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/keys.rc ${DESTDIR}${EXAMPLESDIR}
.for f in AUTHORS FAQ README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
