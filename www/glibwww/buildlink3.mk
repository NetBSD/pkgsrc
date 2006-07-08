# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:11:12 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLIBWWW_BUILDLINK3_MK:=	${GLIBWWW_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	glibwww
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nglibwww}
BUILDLINK_PACKAGES+=	glibwww
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}glibwww

.if !empty(GLIBWWW_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.glibwww?=	glibwww>=0.2nb5
BUILDLINK_ABI_DEPENDS.glibwww+=	glibwww>=0.2nb9
BUILDLINK_PKGSRCDIR.glibwww?=	../../www/glibwww
.endif	# GLIBWWW_BUILDLINK3_MK

.include "../../www/libwww/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
