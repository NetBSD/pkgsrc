# $NetBSD: Makefile,v 1.7 2003/08/05 13:40:33 drochner Exp $

DISTNAME=	quanta-3.1.3
PKGREVISION=	1
CATEGORIES=	www
COMMENT= 	HTML editor suitable for experienced web developers

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

USE_PERL5=		build
USE_GMAKE=              YES
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
