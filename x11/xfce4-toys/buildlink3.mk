# $NetBSD: buildlink3.mk,v 1.4 2005/01/17 12:56:14 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_TOYS_BUILDLINK3_MK:=	${XFCE4_TOYS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-toys
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-toys}
BUILDLINK_PACKAGES+=	xfce4-toys

.if !empty(XFCE4_TOYS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-toys+=		xfce4-toys>=4.2.0
BUILDLINK_PKGSRCDIR.xfce4-toys?=	../../x11/xfce4-toys
.endif	# XFCE4_TOYS_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
