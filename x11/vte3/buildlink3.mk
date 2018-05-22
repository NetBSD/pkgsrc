# $NetBSD: buildlink3.mk,v 1.7 2018/05/22 12:21:32 youri Exp $

BUILDLINK_TREE+=	vte

.if !defined(VTE_BUILDLINK3_MK)
VTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vte+=	vte3>=0.48.3
BUILDLINK_ABI_DEPENDS.vte+=	vte3>=0.48.3
BUILDLINK_PKGSRCDIR.vte?=	../../x11/vte3

.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.endif # VTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-vte
