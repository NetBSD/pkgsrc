# $NetBSD: Makefile,v 1.17 2004/04/05 11:52:31 markd Exp $

DISTNAME=	quanta-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	www
COMMENT= 	HTML editor suitable for experienced web developers

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

USE_PERL5=		build
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES

REPLACE_PERL=		quanta/data/scripts/TemplateMagic.pl \
			quanta/data/scripts/dwt.pl

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
