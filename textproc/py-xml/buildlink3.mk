# $NetBSD: buildlink3.mk,v 1.4 2004/03/18 09:12:15 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PYXML_BUILDLINK3_MK:=	${PYXML_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyxml
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyxml}
BUILDLINK_PACKAGES+=	pyxml

.if !empty(PYXML_BUILDLINK3_MK:M+)
BUILDLINK_PKGBASE.pyxml?=	${PYPKGPREFIX}-xml
BUILDLINK_DEPENDS.pyxml+=	${PYPKGPREFIX}-xml>=0.8.3nb1
BUILDLINK_PKGSRCDIR.pyxml?=	../../textproc/py-xml
.endif	# PYXML_BUILDLINK3_MK

.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
