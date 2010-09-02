# $NetBSD: buildlink3.mk,v 1.6 2010/09/02 09:18:10 drochner Exp $

BUILDLINK_TREE+=	py-sip

.if !defined(PY_SIP_BUILDLINK3_MK)
PY_SIP_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-sip+=	${PYPKGPREFIX}-sip>=4.11
BUILDLINK_PKGSRCDIR.py-sip?=	../../x11/py-sip
.endif # PY_SIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-sip
