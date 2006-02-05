# $NetBSD: buildlink3.mk,v 1.4 2006/02/05 23:11:43 joerg Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
STARTUP_NOTIFICATION_BUILDLINK3_MK:=	${STARTUP_NOTIFICATION_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	startup-notification
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nstartup-notification}
BUILDLINK_PACKAGES+=	startup-notification

.if !empty(STARTUP_NOTIFICATION_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.startup-notification+=	startup-notification>=0.5
BUILDLINK_RECOMMENDED.startup-notification+=	startup-notification>=0.8nb1
BUILDLINK_PKGSRCDIR.startup-notification?=	../../x11/startup-notification
.endif	# STARTUP_NOTIFICATION_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
