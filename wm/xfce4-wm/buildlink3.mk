# $NetBSD: buildlink3.mk,v 1.1 2004/03/10 11:53:37 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_WM_BUILDLINK3_MK:=	${XFCE4_WM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-wm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-wm}
BUILDLINK_PACKAGES+=	xfce4-wm

.if !empty(XFCE4_WM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-wm+=	xfce4-wm>=4.0.4nb1
BUILDLINK_PKGSRCDIR.xfce4-wm?=	../../wm/xfce4-wm

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif	# XFCE4_WM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
