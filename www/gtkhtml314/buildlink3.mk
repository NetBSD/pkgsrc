# $NetBSD: buildlink3.mk,v 1.21 2018/11/27 20:32:06 bsiegert Exp $

BUILDLINK_TREE+=	gtkhtml314

.if !defined(GTKHTML314_BUILDLINK3_MK)
GTKHTML314_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkhtml314+=	gtkhtml314>=3.24.0
BUILDLINK_ABI_DEPENDS.gtkhtml314+=	gtkhtml314>=3.32.2nb9
BUILDLINK_PKGSRCDIR.gtkhtml314?=	../../www/gtkhtml314

.include "../../devel/GConf/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.endif # GTKHTML314_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkhtml314
