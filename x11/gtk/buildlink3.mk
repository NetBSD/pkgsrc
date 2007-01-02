# $NetBSD: buildlink3.mk,v 1.17 2007/01/02 11:26:58 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTK_BUILDLINK3_MK:=	${GTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtk}
BUILDLINK_PACKAGES+=	gtk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtk

.if !empty(GTK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gtk+=		gtk+>=1.2.10
BUILDLINK_ABI_DEPENDS.gtk+=	gtk+>=1.2.10nb9
BUILDLINK_PKGSRCDIR.gtk?=	../../x11/gtk
.endif	# GTK_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
