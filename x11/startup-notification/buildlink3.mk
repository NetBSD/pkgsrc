# $NetBSD: buildlink3.mk,v 1.16 2012/07/15 08:23:00 wiz Exp $

BUILDLINK_TREE+=	startup-notification

.if !defined(STARTUP_NOTIFICATION_BUILDLINK3_MK)
STARTUP_NOTIFICATION_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"
.if ${X11_TYPE} == "modular"
BUILDLINK_PKGSRCDIR.startup-notification?=	../../x11/startup-notification
BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.5
BUILDLINK_ABI_DEPENDS.startup-notification+=	startup-notification>=0.12nb2
.else
.  if ${OPSYS} == "NetBSD"
.    if !empty(OS_VERSION:M5.99.*) || !empty(OS_VERSION:M[6789].*)
BUILDLINK_PKGSRCDIR.startup-notification?=	../../x11/startup-notification
BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.5
BUILDLINK_ABI_DEPENDS.startup-notification+=	startup-notification>=0.12nb2
.    else
BUILDLINK_PKGSRCDIR.startup-notification?=	../../x11/startup-notification010
BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.5<0.12
BUILDLINK_ABI_DEPENDS.startup-notification+=	startup-notification>=0.10nb2<0.12
.    endif
.  else #!NetBSD
BUILDLINK_PKGSRCDIR.startup-notification?=	../../x11/startup-notification
.  endif
.endif

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.endif # STARTUP_NOTIFICATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-startup-notification
