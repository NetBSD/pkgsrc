# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/12/24 17:17:49 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OCAML_GRAPHICS_BUILDLINK3_MK:=	${OCAML_GRAPHICS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ocaml-graphics
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nocaml-graphics}
BUILDLINK_PACKAGES+=	ocaml-graphics

.if !empty(OCAML_GRAPHICS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ocaml-graphics+=	ocaml-graphics>=3.06
BUILDLINK_PKGSRCDIR.ocaml-graphics?=	../../x11/ocaml-graphics
.endif	# OCAML_GRAPHICS_BUILDLINK3_MK

.include "../../lang/ocaml/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
