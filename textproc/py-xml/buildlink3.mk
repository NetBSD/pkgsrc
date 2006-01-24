# $NetBSD: buildlink3.mk,v 1.6 2006/01/24 07:32:38 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PYXML_BUILDLINK3_MK:=	${PYXML_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyxml
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyxml}
BUILDLINK_PACKAGES+=	pyxml

.if !empty(PYXML_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pyxml+=	${PYPKGPREFIX}-xml>=0.8.3nb1
BUILDLINK_RECOMMENDED.pyxml?=	${PYPKGPREFIX}-xml>=0.8.4nb1
BUILDLINK_PKGSRCDIR.pyxml?=	../../textproc/py-xml
.endif	# PYXML_BUILDLINK3_MK

.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
