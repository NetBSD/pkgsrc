# $NetBSD: buildlink3.mk,v 1.1 2004/03/10 11:53:37 xtraeme Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_GTK2_ENGINE_BUILDLINK3_MK:=	${XFCE4_GTK2_ENGINE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-gtk2-engine
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-gtk2-engine}
BUILDLINK_PACKAGES+=	xfce4-gtk2-engine

.if !empty(XFCE4_GTK2_ENGINE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-gtk2-engine+=	xfce4-gtk2-engine>=2.1.9nb1
BUILDLINK_PKGSRCDIR.xfce4-gtk2-engine?=	../../x11/xfce4-gtk2-engines

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif	# XFCE4_GTK2_ENGINE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
