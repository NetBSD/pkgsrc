# $NetBSD: Makefile,v 1.10 2005/09/29 14:11:36 adam Exp $

DISTNAME=	kdewebdev-${_KDE_VERSION}
CATEGORIES=	www
COMMENT= 	HTML editor and tools suitable for experienced web developers

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=		perl
REPLACE_PERL=		quanta/scripts/TemplateMagic.pl \
			quanta/scripts/dwt.pl

# a fix for qt-3.3.5, please remove if qt-3.3.6 (or newer) solves the problem
SUBST_CLASSES+=		hints
SUBST_STAGE.hints=	post-patch
SUBST_MESSAGE.hints=	"Fix includehints."
SUBST_FILES.hints=	quanta/parts/kafka/htmldocumentpropertiesui.ui
SUBST_FILTER_CMD.hints=	${GREP} -v includehint

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
