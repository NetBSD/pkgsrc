# $NetBSD: buildlink3.mk,v 1.16 2007/12/07 19:43:30 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_SESSION_BUILDLINK3_MK:=	${XFCE4_SESSION_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-session
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-session}
BUILDLINK_PACKAGES+=	xfce4-session
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-session

.if ${XFCE4_SESSION_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-session+=	xfce4-session>=4.4.2
BUILDLINK_PKGSRCDIR.xfce4-session?=	../../x11/xfce4-session
.endif	# XFCE4_SESSION_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
