# $NetBSD: buildlink3.mk,v 1.1 2004/03/10 11:53:37 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXFCE4GUI_BUILDLINK3_MK:=	${LIBXFCE4GUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxfce4gui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxfce4gui}
BUILDLINK_PACKAGES+=	libxfce4gui

.if !empty(LIBXFCE4GUI_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libxfce4gui+=		libxfce4gui>=4.0.4nb1
BUILDLINK_PKGSRCDIR.libxfce4gui?=	../../x11/libxfce4gui

.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif	# LIBXFCE4GUI_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
