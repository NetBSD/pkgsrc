# $NetBSD: buildlink3.mk,v 1.1 2004/02/19 21:36:39 minskim Exp $
#
# This Makefile fragment is included by packages that use py-gnome2.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PY_GNOME2_BUILDLINK3_MK:=	${PY_GNOME2_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	${PYPKGPREFIX}-gnome2
.endif

.if !empty(PY_GNOME2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			pygnome2
BUILDLINK_DEPENDS.pygnome2+=		${PYPKGPREFIX}-gnome2>=2.0.0nb4
BUILDLINK_PKGSRCDIR.pygnome2?=		../../x11/py-gnome2

.include "../../net/py-ORBit/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../x11/libzvt/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

.endif # PY_GNOME2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
