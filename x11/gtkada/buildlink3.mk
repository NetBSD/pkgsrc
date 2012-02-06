# $NetBSD: buildlink3.mk,v 1.4 2012/02/06 12:42:01 wiz Exp $

BUILDLINK_TREE+=	gtkada

.if !defined(GTKADA_BUILDLINK3_MK)
GTKADA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkada+=	gtkada>=2.22
BUILDLINK_ABI_DEPENDS.gtkada?=	gtkada>=2.22nb3
BUILDLINK_PKGSRCDIR.gtkada?=	../../x11/gtkada

.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/gnat-aux/buildlink3.mk"
.endif	# GTKADA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkada
