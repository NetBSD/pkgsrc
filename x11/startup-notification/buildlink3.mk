# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 04:43:38 xtraeme Exp $
#
# This Makefile fragment is included by packages that use startup-notification.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
STARTUP_NOTIFICATION_BUILDLINK3_MK:=	${STARTUP_NOTIFICATION_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	startup-notification
.endif

.if !empty(STARTUP_NOTIFICATION_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=				startup-notification
BUILDLINK_DEPENDS.startup-notification+=	startup-notification>=0.5
BUILDLINK_PKGSRCDIR.startup-notification?=	../../x11/startup-notification

.endif # STARTUP_NOTIFICATION_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
