# $NetBSD: buildlink3.mk,v 1.8 2020/01/18 21:48:27 jperkin Exp $

BUILDLINK_TREE+=	qore-json-module

.if !defined(QORE_JSON_MODULE_BUILDLINK3_MK)
QORE_JSON_MODULE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore-json-module+=	qore-json-module>=1.4
BUILDLINK_ABI_DEPENDS.qore-json-module?=	qore-json-module>=1.7nb1
BUILDLINK_PKGSRCDIR.qore-json-module?=		../../textproc/qore-json-module

.include "../../lang/qore/buildlink3.mk"
.endif	# QORE_JSON_MODULE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore-json-module
