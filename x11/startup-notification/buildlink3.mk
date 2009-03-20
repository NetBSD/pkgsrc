# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:25:51 joerg Exp $

BUILDLINK_TREE+=	startup-notification

.if !defined(STARTUP_NOTIFICATION_BUILDLINK3_MK)
STARTUP_NOTIFICATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.5
BUILDLINK_ABI_DEPENDS.startup-notification+=	startup-notification>=0.8nb1
BUILDLINK_PKGSRCDIR.startup-notification?=	../../x11/startup-notification

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # STARTUP_NOTIFICATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-startup-notification
