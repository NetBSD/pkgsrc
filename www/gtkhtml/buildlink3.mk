# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:11:12 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTKHTML_BUILDLINK3_MK:=	${GTKHTML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkhtml
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkhtml}
BUILDLINK_PACKAGES+=	gtkhtml
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtkhtml

.if !empty(GTKHTML_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gtkhtml?=	gtkhtml>=1.1.10nb5
BUILDLINK_ABI_DEPENDS.gtkhtml?=	gtkhtml>=1.1.10nb8
BUILDLINK_PKGSRCDIR.gtkhtml?=	../../www/gtkhtml
.endif	# GTKHTML_BUILDLINK3_MK

.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../www/glibwww/buildlink3.mk"
.include "../../www/libghttp/buildlink3.mk"
.include "../../x11/control-center/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
