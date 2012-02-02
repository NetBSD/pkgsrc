# $NetBSD: buildlink3.mk,v 1.12 2012/02/02 11:33:32 wiz Exp $

BUILDLINK_TREE+=	startup-notification

.if !defined(STARTUP_NOTIFICATION_BUILDLINK3_MK)
STARTUP_NOTIFICATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.5
BUILDLINK_ABI_DEPENDS.startup-notification+=	startup-notification>=0.8nb1

.include "../../mk/bsd.fast.prefs.mk"
.if ${X11_TYPE} == "modular"
BUILDLINK_PKGSRCDIR.startup-notification?=	../../x11/startup-notification
.else
.if ${OPSYS} == "NetBSD"
.if !empty(OS_VERSION:M5.99.*) || !empty(OS_VERSION:M[6789].*)
BUILDLINK_PKGSRCDIR.startup-notification?=	../../x11/startup-notification
.else
BUILDLINK_PKGSRCDIR.startup-notification?=	../../x11/startup-notification010
.endif
.else #!NetBSD
BUILDLINK_PKGSRCDIR.startup-notification?=	../../x11/startup-notification
.endif
.endif

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.endif # STARTUP_NOTIFICATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-startup-notification
