# $NetBSD: Makefile,v 1.42 2024/03/22 12:16:40 pin Exp $

DISTNAME=	evilwm-1.4.3
CATEGORIES=	wm x11
MASTER_SITES=	http://www.6809.org.uk/evilwm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.6809.org.uk/evilwm/
COMMENT=	Minimalist Window Manager for X
LICENSE=	evilwm-license

USE_TOOLS+=	gmake

CPPFLAGS.NetBSD+=	-D_NETBSD_SOURCE

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/applications share/doc/evilwm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/evilwm ${DESTDIR}${PREFIX}/bin/evilwm
	${INSTALL_MAN} ${WRKSRC}/evilwm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/evilwm.1
	for docfile in ChangeLog README TODO; do \
		${INSTALL_DATA} ${WRKSRC}/$$docfile \
			${DESTDIR}${PREFIX}/share/doc/evilwm/; \
	done
	${INSTALL_DATA} ${WRKSRC}/evilwm.desktop \
		${DESTDIR}${PREFIX}/share/applications/evilwm.desktop

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
