# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/04 11:01:41 markd Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SOPRANO_BUILDLINK3_MK:=	${SOPRANO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	soprano
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsoprano}
BUILDLINK_PACKAGES+=	soprano
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}soprano

.if ${SOPRANO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.soprano+=	soprano>=2.0.3
BUILDLINK_PKGSRCDIR.soprano?=	../../textproc/soprano
.endif	# SOPRANO_BUILDLINK3_MK

.include "../../textproc/libclucene/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
