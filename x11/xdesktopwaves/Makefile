# $NetBSD: Makefile,v 1.15 2013/09/03 17:54:41 shattered Exp $
#

DISTNAME=	xdesktopwaves-1.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xdesktopwaves/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xdesktopwaves.sourceforge.net/
COMMENT=	Simulates water waves on the X Windows desktop

MAKE_FLAGS+=		CFLAGS=${CFLAGS:M*:Q}
MAKE_FLAGS+=		LFLAGS=${LDFLAGS:M*:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/xdesktopwaves \
			share/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdesktopwaves ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/xdesktopwaves.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xdesktopwaves/
	${INSTALL_DATA} ${WRKSRC}/xdesktopwaves.xpm ${DESTDIR}${PREFIX}/share/pixmaps/

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
