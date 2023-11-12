# $NetBSD: buildlink3.mk,v 1.27 2023/11/12 13:24:32 wiz Exp $

BUILDLINK_TREE+=	vte3

.if !defined(VTE3_BUILDLINK3_MK)
VTE3_BUILDLINK3_MK:=

USE_CXX_FEATURES+=		c++20

BUILDLINK_API_DEPENDS.vte3+=	vte3>=0.52.2
BUILDLINK_ABI_DEPENDS.vte3+=	vte3>=0.72.3nb2
BUILDLINK_PKGSRCDIR.vte3?=	../../x11/vte3

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # VTE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-vte3
