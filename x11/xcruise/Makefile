# $NetBSD: Makefile,v 1.2 1999/12/03 14:15:39 minoura Exp $
#

DISTNAME=	xcruise-0.22
CATEGORIES=	x11 graphics
MASTER_SITES=	http://tanaka-www.cs.titech.ac.jp/%7Eeuske/prog/

MAINTAINER=	minoura@netbsd.org
HOMEPAGE=	http://tanaka-www.cs.titech.ac.jp/%7Eeuske/prog/  # in Japanese

# LICENSE=	GPL

USE_X11BASE=	yes
USE_IMAKE=	yes

post-install:
	$(MKDIR) $(PREFIX)/share/doc/xcruise
	$(INSTALL_DATA) $(WRKSRC)/README $(PREFIX)/share/doc/xcruise

.include "../../mk/bsd.pkg.mk"
