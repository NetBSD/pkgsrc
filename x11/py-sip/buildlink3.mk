# $NetBSD: buildlink3.mk,v 1.4 2009/11/24 17:17:35 drochner Exp $

BUILDLINK_TREE+=	py-sip

.if !defined(PY_SIP_BUILDLINK3_MK)
PY_SIP_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-sip+=	${PYPKGPREFIX}-sip>=4.9.1
BUILDLINK_PKGSRCDIR.py-sip?=	../../x11/py-sip
.endif # PY_SIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-sip
