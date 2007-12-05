# $NetBSD: buildlink3.mk,v 1.17 2007/12/05 07:50:47 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_NOTES_PLUGIN_BUILDLINK3_MK:=	${XFCE4_NOTES_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-notes-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-notes-plugin}
BUILDLINK_PACKAGES+=	xfce4-notes-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-notes-plugin

.if ${XFCE4_NOTES_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-notes-plugin+=	xfce4-notes-plugin>=1.6.0
BUILDLINK_PKGSRCDIR.xfce4-notes-plugin?=	../../x11/xfce4-notes-plugin
.endif	# XFCE4_NOTES_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
