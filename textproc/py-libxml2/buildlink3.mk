# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:32 joerg Exp $

BUILDLINK_TREE+=	py-libxml2

.if !defined(PY_LIBXML2_BUILDLINK3_MK)
PY_LIBXML2_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-libxml2+=	${PYPKGPREFIX}-libxml2>=2.6.27
BUILDLINK_PKGSRCDIR.py-libxml2?=	../../textproc/py-libxml2
.endif # PY_LIBXML2_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-libxml2
