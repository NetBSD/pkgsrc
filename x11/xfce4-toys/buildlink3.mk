# $NetBSD: buildlink3.mk,v 1.9 2006/01/24 07:33:01 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_TOYS_BUILDLINK3_MK:=	${XFCE4_TOYS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-toys
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-toys}
BUILDLINK_PACKAGES+=	xfce4-toys

.if !empty(XFCE4_TOYS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-toys+=	xfce4-toys>=4.2.3
BUILDLINK_RECOMMENDED.xfce4-toys?=	xfce4-toys>=4.2.3nb1
BUILDLINK_PKGSRCDIR.xfce4-toys?=	../../x11/xfce4-toys
.endif	# XFCE4_TOYS_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
