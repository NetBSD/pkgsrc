# $NetBSD: Makefile,v 1.12 2012/09/15 10:06:41 obache Exp $

DISTNAME=		rsibreak-0.8.0
PKGNAME=		rsibreak-0.8.0
PKGREVISION=		17
CATEGORIES=		time kde
MASTER_SITES=		http://www.rsibreak.org/files/
EXTRACT_SUFX=           .tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.rsibreak.org/
COMMENT=		RSI management tool

PKG_DESTDIR_SUPPORT=	user-destdir

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
