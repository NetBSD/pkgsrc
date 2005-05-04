# $NetBSD: Makefile,v 1.7 2005/05/04 13:49:50 markd Exp $

DISTNAME=	kdewebdev-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	www
COMMENT= 	HTML editor and tools suitable for experienced web developers

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_PERL5=		build

REPLACE_PERL=		quanta/scripts/TemplateMagic.pl \
			quanta/scripts/dwt.pl

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
