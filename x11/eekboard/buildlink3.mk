# $NetBSD: buildlink3.mk,v 1.27 2016/08/03 10:22:21 adam Exp $
#

BUILDLINK_TREE+=	eekboard

.if !defined(EEKBOARD_BUILDLINK3_MK)
EEKBOARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eekboard+=	eekboard>=1.0.6
BUILDLINK_ABI_DEPENDS.eekboard?=	eekboard>=1.0.8nb9
BUILDLINK_PKGSRCDIR.eekboard?=	../../x11/eekboard

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.endif	# EEKBOARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-eekboard
