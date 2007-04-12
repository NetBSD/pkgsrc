# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/04/12 09:49:16 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_ORAGE_BUILDLINK3_MK:=	${XFCE4_ORAGE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-orage
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-orage}
BUILDLINK_PACKAGES+=	xfce4-orage
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-orage

.if ${XFCE4_ORAGE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-orage+=	xfce4-orage>=4.4.1
BUILDLINK_PKGSRCDIR.xfce4-orage?=	../../time/xfce4-orage
.endif	# XFCE4_ORAGE_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
