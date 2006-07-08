# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:15 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OCAML_GRAPHICS_BUILDLINK3_MK:=	${OCAML_GRAPHICS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ocaml-graphics
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nocaml-graphics}
BUILDLINK_PACKAGES+=	ocaml-graphics
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ocaml-graphics

.if !empty(OCAML_GRAPHICS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.ocaml-graphics+=	ocaml-graphics>=3.08.2
BUILDLINK_ABI_DEPENDS.ocaml-graphics?=	ocaml-graphics>=3.09.1
BUILDLINK_PKGSRCDIR.ocaml-graphics?=	../../x11/ocaml-graphics
.endif	# OCAML_GRAPHICS_BUILDLINK3_MK

.include "../../lang/ocaml/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
