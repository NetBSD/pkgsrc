# $NetBSD: buildlink3.mk,v 1.13 2006/10/12 09:24:20 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_CALENDAR_BUILDLINK3_MK:=	${XFCE4_CALENDAR_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-calendar
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-calendar}
BUILDLINK_PACKAGES+=	xfce4-calendar
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-calendar

.if ${XFCE4_CALENDAR_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-calendar+=	xfce4-calendar>=4.2.3nb4
BUILDLINK_PKGSRCDIR.xfce4-calendar?=	../../time/xfce4-calendar
.endif	# XFCE4_CALENDAR_BUILDLINK3_MK

.include "../../databases/dbh/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
