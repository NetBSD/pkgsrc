# $NetBSD: buildlink3.mk,v 1.1 2004/03/11 17:22:55 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FOX_BUILDLINK3_MK:=	${FOX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fox
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfox}
BUILDLINK_PACKAGES+=	fox

.if !empty(FOX_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.fox+=		fox>=1.0.43nb2
BUILDLINK_PKGSRCDIR.fox?=	../../x11/fox

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"

BUILDLINK_CPPFLAGS.fox+=	-I${BUILDLINK_PREFIX.fox}/include/fox
CPPFLAGS+=			${BUILDLINK_CPPFLAGS.fox}

.endif	# FOX_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
