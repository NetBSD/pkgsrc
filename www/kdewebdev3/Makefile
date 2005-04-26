# $NetBSD: Makefile,v 1.6 2005/04/26 19:01:28 drochner Exp $

DISTNAME=	kdewebdev-${_KDE_VERSION}
PKGREVISION=	1
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
