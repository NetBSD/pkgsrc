# $NetBSD: Makefile,v 1.42 2012/09/15 10:06:46 obache Exp $

DISTNAME=	kdewebdev-${_KDE_VERSION}
PKGREVISION=	15
CATEGORIES=	www
COMMENT=	HTML editor and tools suitable for experienced web developers

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=		perl
REPLACE_PERL+=		kommander/working/extractkmdr \
			quanta/scripts/TemplateMagic.pl \
			quanta/scripts/dwt.pl

SUBST_CLASSES+=		xmlpath
SUBST_STAGE.xmlpath=	post-patch
SUBST_MESSAGE.xmlpath=	Fix broken libxml2 path.
SUBST_FILES.xmlpath=	klinkstatus/src/utils/Makefile.in
SUBST_SED.xmlpath=	-e s:/usr/include/libxml2:${PREFIX}/include/libxml2:

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
