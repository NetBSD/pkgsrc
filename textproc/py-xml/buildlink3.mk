# $NetBSD: buildlink3.mk,v 1.1 2004/02/23 12:36:25 recht Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PYXML_BUILDLINK3_MK:=	${PYXML_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyxml
.endif

.if !empty(PYXML_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			pyxml
BUILDLINK_DEPENDS.pyxml+=		${PYPKGPREFIX}-xml>=0.8.3nb1
BUILDLINK_PKGSRCDIR.pyxml?=		../../textproc/py-xml

.include "../../textproc/expat/buildlink3.mk"

.endif # PYXML_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
