# $NetBSD: buildlink3.mk,v 1.7 2004/03/16 18:23:28 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTK2_BUILDLINK3_MK:=	${GTK2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtk2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtk2}
BUILDLINK_PACKAGES+=	gtk2

.if !empty(GTK2_BUILDLINK3_MK:M+)
BUILDLINK_PKGBASE.gtk2?=	gtk2+
BUILDLINK_DEPENDS.gtk2+=	gtk2+>=2.2.4nb2
BUILDLINK_PKGSRCDIR.gtk2?=	../../x11/gtk2

USE_X11= 	yes

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/Xrandr/buildlink3.mk"

.endif	# GTK2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
