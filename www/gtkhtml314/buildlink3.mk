# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:25:37 joerg Exp $

BUILDLINK_TREE+=	gtkhtml314

.if !defined(GTKHTML314_BUILDLINK3_MK)
GTKHTML314_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkhtml314+=	gtkhtml314>=3.24.0
BUILDLINK_PKGSRCDIR.gtkhtml314?=	../../www/gtkhtml314

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.endif # GTKHTML314_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkhtml314
