# $NetBSD: buildlink3.mk,v 1.20 2007/12/07 19:43:24 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_WM_THEMES_BUILDLINK3_MK:=	${XFCE4_WM_THEMES_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-wm-themes
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-wm-themes}
BUILDLINK_PACKAGES+=	xfce4-wm-themes
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-wm-themes

.if ${XFCE4_WM_THEMES_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-wm-themes+=	xfce4-wm-themes>=4.4.2
BUILDLINK_PKGSRCDIR.xfce4-wm-themes?=	../../wm/xfce4-wm-themes
.endif	# XFCE4_WM_THEMES_BUILDLINK3_MK

.include "../../wm/xfce4-wm/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
