# $NetBSD: Makefile,v 1.29 2012/09/15 10:07:03 obache Exp $

DISTNAME=	kde-i18n-ko-${_KDE_VERSION}
PKGREVISION=	13
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_KDE_I18N}

COMMENT=	Language bindings for the KDE desktop

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=		msgfmt
BUILDLINK_DEPMETHOD.qt3-libs=	build
BUILDLINK_DEPMETHOD.kdelibs=	build

SUBST_CLASSES+=		common
SUBST_STAGE.common=	post-patch
SUBST_MESSAGE.common=	Fix common documentation path.
SUBST_FILES.common=	docs/common/Makefile.in
SUBST_SED.common=	-e s:/docs/common:/common:

SUBST_CLASSES+=		msgctxt
SUBST_STAGE.msgctxt=	post-patch
SUBST_MESSAGE.msgctxt=	Delete msgctxt lines.
SUBST_FILES.msgctxt=	messages/kdenetwork/krfb.po \
			messages/kdenetwork/knewsticker.po \
			messages/kdebase/kcmicons.po \
			messages/kdebase/drkonqi.po \
			messages/kdebase/filetypes.po \
			messages/kdebase/kcmcgi.po \
			messages/kdebase/kcmbackground.po \
			messages/kdebase/kcmcomponentchooser.po
SUBST_SED.msgctxt=	-e "/ msgctxt /d"

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
