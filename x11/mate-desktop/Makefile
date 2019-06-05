# $NetBSD: Makefile,v 1.20 2019/06/05 01:13:27 gutteridge Exp $

.include "../../meta-pkgs/mate/Makefile.common"

PKGREVISION=	2
DISTNAME=	mate-desktop-${VERSION:R}.1
CATEGORIES=	x11

COMMENT=	MATE desktop library

TOOL_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=		libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

PKGCONFIG_OVERRIDE+=	libmate-desktop/mate-desktop-2.0.pc.in

REPLACE_SH+=	tools/mate-gsettings-toggle

SUBST_CLASSES=		prefix
SUBST_FILES.prefix=	schemas/org.mate.background.gschema.xml
SUBST_MESSAGE.prefix=	Fixing prefix
SUBST_STAGE.prefix=	pre-install
SUBST_SED.prefix=	-e 's,$${prefix},${PREFIX},'

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
# librsvg is required as a tool dependency, to provide rsvg-convert.
# Since it's now a "split" package, where a choice depends on the
# environment, or on a user-defined option, the dependency must be
# expressed this way, pending further structural changes.
BUILDLINK_DEPMETHOD.librsvg?=	build
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
