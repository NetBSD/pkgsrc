# $NetBSD: buildlink3.mk,v 1.1 2004/03/10 11:53:37 xtraeme Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_MCS_MANAGER_BUILDLINK3_MK:=	${XFCE4_MCS_MANAGER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-mcs-manager
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-mcs-manager}
BUILDLINK_PACKAGES+=	xfce4-mcs-manager

.if !empty(XFCE4_MCS_MANAGER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-mcs-manager+=	xfce4-mcs-manager>=4.0.4nb1
BUILDLINK_PKGSRCDIR.xfce4-mcs-manager?=	../../x11/xfce4-mcs-manager

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4mcs/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif	# XFCE4_MCS_MANAGER_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
