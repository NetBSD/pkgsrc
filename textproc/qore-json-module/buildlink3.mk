# $NetBSD: buildlink3.mk,v 1.1 2014/12/30 15:50:28 wiz Exp $

BUILDLINK_TREE+=	qore-json-module

.if !defined(QORE_JSON_MODULE_BUILDLINK3_MK)
QORE_JSON_MODULE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore-json-module+=	qore-json-module>=1.4
BUILDLINK_PKGSRCDIR.qore-json-module?=	../../textproc/qore-json-module

.include "../../lang/qore/buildlink3.mk"
.endif	# QORE_JSON_MODULE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore-json-module
