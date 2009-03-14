# $NetBSD: buildlink3.mk,v 1.2 2009/03/14 12:06:49 abs Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FLTK2_BUILDLINK3_MK:=	${FLTK2_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	fltk2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfltk2}
BUILDLINK_PACKAGES+=	fltk2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}fltk2

.if ${FLTK2_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.fltk2?=	build
BUILDLINK_API_DEPENDS.fltk2+=	fltk2>=2.0pre6129
BUILDLINK_PKGSRCDIR.fltk2?=	../../x11/fltk2
.endif	# FLTK2_BUILDLINK3_MK

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
