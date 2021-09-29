# $NetBSD: buildlink3.mk,v 1.25 2021/09/29 19:00:16 adam Exp $

BUILDLINK_TREE+=	enlightenment

.if !defined(ENLIGHTENMENT_BUILDLINK3_MK)
ENLIGHTENMENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.enlightenment+=	enlightenment>=0.17.6
BUILDLINK_ABI_DEPENDS.enlightenment?=	enlightenment>=0.17.6nb5
BUILDLINK_PKGSRCDIR.enlightenment?=	../../x11/enlightenment

.include "../../devel/ecore/buildlink3.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../graphics/edje/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/evas-buffer/buildlink3.mk"
.include "../../graphics/evas-eet/buildlink3.mk"
.include "../../graphics/evas-jpeg/buildlink3.mk"
.include "../../graphics/evas-png/buildlink3.mk"
.include "../../sysutils/edbus/buildlink3.mk"
.include "../../sysutils/efreet/buildlink3.mk"
.include "../../devel/eio/buildlink3.mk"
.include "../../x11/elementary/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.endif # ENLIGHTENMENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-enlightenment
