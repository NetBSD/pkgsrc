# $NetBSD: buildlink3.mk,v 1.25 2013/10/10 14:41:50 ryoon Exp $

BUILDLINK_TREE+=	xfce4-exo

.if !defined(XFCE4_EXO_BUILDLINK3_MK)
XFCE4_EXO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-exo+=	xfce4-exo>=0.3.100
BUILDLINK_ABI_DEPENDS.xfce4-exo+=	xfce4-exo>=0.3.101nb24
BUILDLINK_PKGSRCDIR.xfce4-exo?=	../../x11/xfce4-exo

pkgbase := xfce4-exo
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.xfce4-exo:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.endif # XFCE4_EXO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-exo
