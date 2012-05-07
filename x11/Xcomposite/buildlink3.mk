# $NetBSD: buildlink3.mk,v 1.14 2012/05/07 01:54:06 dholland Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	Xcomposite

.if !defined(XCOMPOSITE_BUILDLINK3_MK)
XCOMPOSITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Xcomposite+=		Xcomposite>=1.0.1
BUILDLINK_ABI_DEPENDS.Xcomposite+=	Xcomposite>=1.0.1nb2
BUILDLINK_PKGSRCDIR.Xcomposite?=	../../x11/Xcomposite

.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.endif # XCOMPOSITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-Xcomposite
