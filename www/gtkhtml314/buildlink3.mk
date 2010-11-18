# $NetBSD: buildlink3.mk,v 1.14 2010/11/18 23:59:15 obache Exp $

BUILDLINK_TREE+=	gtkhtml314

.if !defined(GTKHTML314_BUILDLINK3_MK)
GTKHTML314_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkhtml314+=	gtkhtml314>=3.24.0
BUILDLINK_ABI_DEPENDS.gtkhtml314?=	gtkhtml314>=3.32.1
BUILDLINK_PKGSRCDIR.gtkhtml314?=	../../www/gtkhtml314

.include "../../devel/GConf/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.endif # GTKHTML314_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkhtml314
