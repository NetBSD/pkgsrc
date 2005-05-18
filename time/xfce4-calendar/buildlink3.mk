# $NetBSD: buildlink3.mk,v 1.3 2005/05/18 06:10:30 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_CALENDAR_BUILDLINK3_MK:=	${XFCE4_CALENDAR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-calendar
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-calendar}
BUILDLINK_PACKAGES+=	xfce4-calendar

.if !empty(XFCE4_CALENDAR_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-calendar+=	xfce4-calendar>=4.2.2
BUILDLINK_PKGSRCDIR.xfce4-calendar?=	../../time/xfce4-calendar
.endif	# XFCE4_CALENDAR_BUILDLINK3_MK

.include "../../databases/dbh/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
