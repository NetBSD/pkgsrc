# $NetBSD: buildlink3.mk,v 1.17 2010/12/08 00:42:16 abs Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	Xfixes

.if !defined(XFIXES_BUILDLINK3_MK)
XFIXES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Xfixes+=	Xfixes>=2.0.0
BUILDLINK_ABI_DEPENDS.Xfixes+=	Xfixes>=2.0.1nb2
BUILDLINK_PKGSRCDIR.Xfixes?=	../../x11/Xfixes

.include "../../mk/x11.buildlink3.mk"
.include "../../x11/fixesproto4/buildlink3.mk"
.endif # XFIXES_BUILDLINK3_MK

BUILDLINK_TREE+=	-Xfixes
