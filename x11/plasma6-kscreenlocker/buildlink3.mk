# $NetBSD: buildlink3.mk,v 1.2 2025/12/31 02:43:31 markd Exp $

BUILDLINK_TREE+=	plasma6-kscreenlocker

.if !defined(PLASMA6_KSCREENLOCKER_BUILDLINK3_MK)
PLASMA6_KSCREENLOCKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-kscreenlocker+=	plasma6-kscreenlocker>=6.5.2
BUILDLINK_PKGSRCDIR.plasma6-kscreenlocker?=	../../x11/plasma6-kscreenlocker

BUILDLINK_FILES.plasma6-kscreenlocker+=	share/dbus-1/interfaces/*.xml

.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kidletime/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../graphics/kf6-ksvg/buildlink3.mk"
.include "../../sysutils/consolekit/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../x11/kf6-kglobalaccel/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/plasma6-layer-shell-qt/buildlink3.mk"
.include "../../x11/plasma6-libkscreen/buildlink3.mk"
.include "../../x11/plasma6-libplasma/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PLASMA6_KSCREENLOCKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-kscreenlocker
