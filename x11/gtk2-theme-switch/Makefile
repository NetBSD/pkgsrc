# $NetBSD: Makefile,v 1.1.1.1 2003/12/05 18:08:06 xtraeme Exp $
#

DISTNAME=		gtk-theme-switch-2.0.0rc2
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
CATEGORIES=		x11
MASTER_SITES=		http://www.muhri.net/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.muhri.net/
COMMENT=		Allows quick & easy switching of GTK+ 2.x themes

USE_BUILDLINK2=		YES
USE_GMAKE=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/switch2 \
		${PREFIX}/bin/gtk2-theme-switch
	${INSTALL_MAN} ${WRKSRC}/switch.1 \
		${PREFIX}/man/man1/gtk2-theme-switch.1
	
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
