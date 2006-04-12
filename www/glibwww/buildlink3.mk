# $NetBSD: buildlink3.mk,v 1.5 2006/04/12 10:27:39 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLIBWWW_BUILDLINK3_MK:=	${GLIBWWW_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	glibwww
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nglibwww}
BUILDLINK_PACKAGES+=	glibwww

.if !empty(GLIBWWW_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.glibwww?=	glibwww>=0.2nb5
BUILDLINK_ABI_DEPENDS.glibwww+=	glibwww>=0.2nb8
BUILDLINK_PKGSRCDIR.glibwww?=	../../www/glibwww
.endif	# GLIBWWW_BUILDLINK3_MK

.include "../../www/libwww/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
