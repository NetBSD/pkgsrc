# $NetBSD: buildlink3.mk,v 1.8 2004/10/03 00:18:31 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_DESKTOP_BUILDLINK3_MK:=	${GNOME_DESKTOP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-desktop
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-desktop}
BUILDLINK_PACKAGES+=	gnome-desktop

.if !empty(GNOME_DESKTOP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-desktop+=	gnome-desktop>=2.8.0
BUILDLINK_RECOMMENDED.gnome-desktop+=	gnome-desktop>=2.8.0nb1
BUILDLINK_PKGSRCDIR.gnome-desktop?=	../../x11/gnome-desktop

PRINT_PLIST_AWK+=	/^@dirrm share\/gnome\/vfolders$$/ \
				{ print "@comment in gnome-desktop: " $$0; \
				  next; }
.endif	# GNOME_DESKTOP_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/gnome2-pixmaps/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
