# $NetBSD: buildlink3.mk,v 1.20 2021/04/27 17:07:36 wiz Exp $

BUILDLINK_TREE+=	startup-notification

.if !defined(STARTUP_NOTIFICATION_BUILDLINK3_MK)
STARTUP_NOTIFICATION_BUILDLINK3_MK:=

BUILDLINK_PKGSRCDIR.startup-notification?=	../../x11/startup-notification
BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.5
BUILDLINK_ABI_DEPENDS.startup-notification+=	startup-notification>=0.12nb2
.include "../../x11/xcb-util/buildlink3.mk"

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.endif # STARTUP_NOTIFICATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-startup-notification
