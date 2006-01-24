# $NetBSD: buildlink3.mk,v 1.9 2006/01/24 07:33:01 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_MCS_MANAGER_BUILDLINK3_MK:=	${XFCE4_MCS_MANAGER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-mcs-manager
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-mcs-manager}
BUILDLINK_PACKAGES+=	xfce4-mcs-manager

.if !empty(XFCE4_MCS_MANAGER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-mcs-manager+=	xfce4-mcs-manager>=4.2.3
BUILDLINK_RECOMMENDED.xfce4-mcs-manager?=	xfce4-mcs-manager>=4.2.3nb1
BUILDLINK_PKGSRCDIR.xfce4-mcs-manager?=	../../x11/xfce4-mcs-manager
.endif	# XFCE4_MCS_MANAGER_BUILDLINK3_MK

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4mcs/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
