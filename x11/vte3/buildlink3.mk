# $NetBSD: buildlink3.mk,v 1.10 2018/11/14 22:22:51 kleink Exp $

BUILDLINK_TREE+=	vte3

.if !defined(VTE3_BUILDLINK3_MK)
VTE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vte3+=	vte3>=0.52.2
BUILDLINK_ABI_DEPENDS.vte3+=	vte3>=0.52.2nb3
BUILDLINK_PKGSRCDIR.vte3?=	../../x11/vte3

.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.endif # VTE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-vte3
