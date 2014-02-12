# $NetBSD: Makefile,v 1.27 2014/02/12 23:18:42 tron Exp $

DISTNAME=		rsibreak-0.8.0
PKGNAME=		rsibreak-0.8.0
PKGREVISION=		30
CATEGORIES=		time kde
MASTER_SITES=		http://www.rsibreak.org/files/
EXTRACT_SUFX=           .tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rsibreak.org/
COMMENT=		RSI management tool

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=		msgfmt perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
