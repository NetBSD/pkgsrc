# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:11:17 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_SESSION_BUILDLINK3_MK:=	${XFCE4_SESSION_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-session
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-session}
BUILDLINK_PACKAGES+=	xfce4-session
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-session

.if !empty(XFCE4_SESSION_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xfce4-session+=	xfce4-session>=4.2.3
BUILDLINK_ABI_DEPENDS.xfce4-session?=	xfce4-session>=4.2.3nb4
BUILDLINK_PKGSRCDIR.xfce4-session?=	../../x11/xfce4-session
.endif	# XFCE4_SESSION_BUILDLINK3_MK

.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
