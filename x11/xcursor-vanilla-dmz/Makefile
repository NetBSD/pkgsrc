# $NetBSD: Makefile,v 1.2 2018/11/24 15:04:04 nia Exp $

DISTNAME=	dmz-cursor-theme_${PKGVERSION_NOREV}
PKGNAME=	xcursor-vanilla-dmz-0.4.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/d/dmz-cursor-theme/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://salsa.debian.org/gnome-team/dmz-cursor-theme
COMMENT=	Style neutral, scalable cursor theme
LICENSE=	cc-by-sa-v3.0

WRKSRC=		${WRKDIR}/dmz-cursor-theme-${PKGVERSION_NOREV}

BUILD_DEPENDS+=	xcursorgen-[0-9]*:../../x11/xcursorgen

ICON_THEMES=	yes

INSTALLATION_DIRS+=	share/icons/Vanilla-DMZ
INSTALLATION_DIRS+=	share/icons/Vanilla-DMZ/cursors
INSTALLATION_DIRS+=	share/icons/Vanilla-DMZ-AA
INSTALLATION_DIRS+=	share/icons/Vanilla-DMZ-AA/cursors

do-build:
	cd ${WRKSRC}/DMZ-Black/pngs && ./make.sh
	cd ${WRKSRC}/DMZ-White/pngs && ./make.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/DMZ-White/index.theme \
	    ${DESTDIR}${PREFIX}/share/icons/Vanilla-DMZ
	${INSTALL_DATA} ${WRKSRC}/DMZ-White/xcursors/* \
	    ${DESTDIR}${PREFIX}/share/icons/Vanilla-DMZ/cursors
	${INSTALL_DATA} ${WRKSRC}/DMZ-Black/index.theme \
	    ${DESTDIR}${PREFIX}/share/icons/Vanilla-DMZ-AA
	${INSTALL_DATA} ${WRKSRC}/DMZ-Black/xcursors/* \
	    ${DESTDIR}${PREFIX}/share/icons/Vanilla-DMZ-AA/cursors

.include "../../mk/bsd.pkg.mk"
