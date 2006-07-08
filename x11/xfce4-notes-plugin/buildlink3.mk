# $NetBSD: buildlink3.mk,v 1.14 2006/07/08 23:11:16 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_NOTES_PLUGIN_BUILDLINK3_MK:=	${XFCE4_NOTES_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-notes-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-notes-plugin}
BUILDLINK_PACKAGES+=	xfce4-notes-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-notes-plugin

.if !empty(XFCE4_NOTES_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xfce4-notes-plugin+=	xfce4-notes-plugin>=0.11.1
BUILDLINK_ABI_DEPENDS.xfce4-notes-plugin?=	xfce4-notes-plugin>=0.11.1nb3
BUILDLINK_PKGSRCDIR.xfce4-notes-plugin?=	../../x11/xfce4-notes-plugin
.endif	# XFCE4_NOTES_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
