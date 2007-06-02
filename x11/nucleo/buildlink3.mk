# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/06/02 08:27:43 agc Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NUCLEO_BUILDLINK3_MK:=	${NUCLEO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	nucleo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnucleo}
BUILDLINK_PACKAGES+=	nucleo
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}nucleo

.if ${NUCLEO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.nucleo+=	nucleo>=0.6
BUILDLINK_PKGSRCDIR.nucleo?=	../../x11/nucleo
.endif	# NUCLEO_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
