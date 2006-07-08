# $NetBSD: buildlink3.mk,v 1.16 2006/07/08 23:11:16 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_MCS_MANAGER_BUILDLINK3_MK:=	${XFCE4_MCS_MANAGER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-mcs-manager
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-mcs-manager}
BUILDLINK_PACKAGES+=	xfce4-mcs-manager
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-mcs-manager

.if !empty(XFCE4_MCS_MANAGER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xfce4-mcs-manager+=	xfce4-mcs-manager>=4.2.3
BUILDLINK_ABI_DEPENDS.xfce4-mcs-manager?=	xfce4-mcs-manager>=4.2.3nb4
BUILDLINK_PKGSRCDIR.xfce4-mcs-manager?=	../../x11/xfce4-mcs-manager
.endif	# XFCE4_MCS_MANAGER_BUILDLINK3_MK

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4mcs/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
