# $NetBSD: buildlink3.mk,v 1.4 2004/02/14 22:10:46 recht Exp $
#
# This Makefile fragment is included by packages that use gtk2+.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTK2+_BUILDLINK3_MK:=	${GTK2+_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtk2
.endif

.if !empty(GTK2+_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gtk2
BUILDLINK_DEPENDS.gtk2+=		gtk2+>=2.2.4nb2
BUILDLINK_PKGSRCDIR.gtk2?=		../../x11/gtk2

USE_X11= yes

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.endif # GTK2+_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
