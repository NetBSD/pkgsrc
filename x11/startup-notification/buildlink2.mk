# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/11 11:25:53 jmmv Exp $
#
# This Makefile fragment is included by packages that use startup-notification.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(STARTUP_NOTIFICATION_BUILDLINK2_MK)
STARTUP_NOTIFICATION_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			startup-notification
BUILDLINK_DEPENDS.startup-notification?=	startup-notification>=0.5
BUILDLINK_PKGSRCDIR.startup-notification?=	../../x11/startup-notification

EVAL_PREFIX+=	BUILDLINK_PREFIX.startup-notification=startup-notification
BUILDLINK_PREFIX.startup-notification_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.startup-notification+=	include/startup-notification-1.0/*
BUILDLINK_FILES.startup-notification+=	include/startup-notification-1.0/libsn/*
BUILDLINK_FILES.startup-notification+=	lib/libstartup-notification-1.*
BUILDLINK_FILES.startup-notification+=	lib/pkgconfig/libstartup-notification-1.0.pc

BUILDLINK_TARGETS+=	startup-notification-buildlink

startup-notification-buildlink: _BUILDLINK_USE

.endif	# STARTUP_NOTIFICATION_BUILDLINK2_MK
