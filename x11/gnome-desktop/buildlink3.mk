# $NetBSD: buildlink3.mk,v 1.21 2006/07/08 23:11:13 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_DESKTOP_BUILDLINK3_MK:=	${GNOME_DESKTOP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-desktop
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-desktop}
BUILDLINK_PACKAGES+=	gnome-desktop
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-desktop

.if !empty(GNOME_DESKTOP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnome-desktop+=	gnome-desktop>=2.14.0
BUILDLINK_ABI_DEPENDS.gnome-desktop?=	gnome-desktop>=2.14.1.1nb1
BUILDLINK_PKGSRCDIR.gnome-desktop?=	../../x11/gnome-desktop
.endif	# GNOME_DESKTOP_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
