# $NetBSD: Makefile,v 1.59 2023/11/14 14:03:10 wiz Exp $
#

DISTNAME=		gtk-theme-switch-2.0.0rc2
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
PKGREVISION=		44
CATEGORIES=		x11
MASTER_SITES=		http://www.muhri.net/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.muhri.net/
COMMENT=		Allows quick & easy switching of GTK+ 2.x themes

USE_TOOLS+=		gmake pkg-config

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/switch2 \
		${DESTDIR}${PREFIX}/bin/gtk2-theme-switch
	${INSTALL_MAN} ${WRKSRC}/switch.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gtk2-theme-switch.1

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
