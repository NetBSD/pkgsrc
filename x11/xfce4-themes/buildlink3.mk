# $NetBSD: buildlink3.mk,v 1.1 2004/03/10 11:53:38 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_THEMES_BUILDLINK3_MK:=	${XFCE4_THEMES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-themes
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-themes}
BUILDLINK_PACKAGES+=	xfce4-themes

.if !empty(XFCE4_THEMES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-themes+=	xfce4-themes>=4.0.4nb1
BUILDLINK_PKGSRCDIR.xfce4-themes?=	../../x11/xfce4-themes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif	# XFCE4_THEMES_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
