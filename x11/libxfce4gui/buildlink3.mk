# $NetBSD: buildlink3.mk,v 1.19 2006/10/12 09:24:20 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXFCE4GUI_BUILDLINK3_MK:=	${LIBXFCE4GUI_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libxfce4gui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxfce4gui}
BUILDLINK_PACKAGES+=	libxfce4gui
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libxfce4gui

.if ${LIBXFCE4GUI_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libxfce4gui+=	libxfce4gui>=4.2.3nb4
BUILDLINK_PKGSRCDIR.libxfce4gui?=	../../x11/libxfce4gui
.endif	# LIBXFCE4GUI_BUILDLINK3_MK

.include "../../databases/dbh/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
