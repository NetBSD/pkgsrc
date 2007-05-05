# $NetBSD: Makefile,v 1.1.1.1 2007/05/05 22:07:59 markd Exp $

DISTNAME=		Rsibreak-0.8.0
PKGNAME=		rsibreak-0.8.0
CATEGORIES=		time kde
MASTER_SITES=		http://www.rsibreak.org/images/e/e0/
EXTRACT_SUFX=           .tar.bz2

MAINTAINER=		markd@NetBSD.org
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

.include "../../mk/bsd.pkg.mk"
