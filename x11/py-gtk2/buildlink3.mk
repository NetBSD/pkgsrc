# $NetBSD: buildlink3.mk,v 1.1 2004/02/18 16:58:36 minskim Exp $
#
# This Makefile fragment is included by packages that use py-gtk2.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PY_GTK2_BUILDLINK3_MK:=	${PY_GTK2_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	${PYPKGPREFIX}-gtk2
.endif

.if !empty(PY_GTK2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			pygtk2
BUILDLINK_DEPENDS.pygtk2+=		${PYPKGPREFIX}-gtk2>=2.0.0nb2
BUILDLINK_PKGSRCDIR.pygtk2?=		../../x11/py-gtk2

.include "../../devel/libglade2/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkglarea2/buildlink3.mk"

.endif # PY_GTK2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
