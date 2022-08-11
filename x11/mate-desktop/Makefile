# $NetBSD: Makefile,v 1.33 2022/08/11 05:09:30 gutteridge Exp $

PKGREVISION= 2
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-desktop-${VERSION:R}.1
CATEGORIES=	x11

COMMENT=	MATE desktop library

TOOL_DEPENDS+=		libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

PKGCONFIG_OVERRIDE+=	libmate-desktop/mate-desktop-2.0.pc.in

REPLACE_SH+=	tools/mate-gsettings-toggle

SUBST_CLASSES=		prefix
SUBST_FILES.prefix=	schemas/org.mate.background.gschema.xml
SUBST_MESSAGE.prefix=	Fixing prefix
SUBST_STAGE.prefix=	pre-install
SUBST_SED.prefix=	-e 's,$${prefix},${PREFIX},'

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
