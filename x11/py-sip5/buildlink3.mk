# $NetBSD: buildlink3.mk,v 1.1 2022/11/26 09:49:43 wiz Exp $

BUILDLINK_TREE+=	py-sip5

.if !defined(PY_SIP5_BUILDLINK3_MK)
PY_SIP5_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-sip5+=	${PYPKGPREFIX}-sip5>=5.0
BUILDLINK_PKGSRCDIR.py-sip5?=	../../x11/py-sip5
.endif # PY_SIP5_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-sip5
