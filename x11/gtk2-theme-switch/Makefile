# $NetBSD: Makefile,v 1.8 2004/10/03 00:18:33 tv Exp $
#

DISTNAME=		gtk-theme-switch-2.0.0rc2
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		http://www.muhri.net/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.muhri.net/
COMMENT=		Allows quick & easy switching of GTK+ 2.x themes

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/switch2 \
		${PREFIX}/bin/gtk2-theme-switch
	${INSTALL_MAN} ${WRKSRC}/switch.1 \
		${PREFIX}/man/man1/gtk2-theme-switch.1

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
