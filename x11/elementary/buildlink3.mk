# $NetBSD: buildlink3.mk,v 1.20 2020/05/06 14:04:15 adam Exp $

BUILDLINK_TREE+=	elementary

.if !defined(ELEMENTARY_BUILDLINK3_MK)
ELEMENTARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.elementary+=	elementary>=1.7.10
BUILDLINK_ABI_DEPENDS.elementary?=	elementary>=1.7.10nb1
BUILDLINK_PKGSRCDIR.elementary?=	../../x11/elementary

.include "../../devel/ecore/buildlink3.mk"
.include "../../graphics/edje/buildlink3.mk"
.include "../../sysutils/edbus/buildlink3.mk"
.include "../../sysutils/efreet/buildlink3.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../graphics/evas-png/buildlink3.mk"
.include "../../graphics/evas-jpeg/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../devel/eio/buildlink3.mk"
.endif	# ELEMENTARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-elementary
