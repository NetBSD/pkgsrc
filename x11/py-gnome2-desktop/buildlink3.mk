# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/02/04 09:33:42 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PY_GNOME2_DESKTOP_BUILDLINK3_MK:=	${PY_GNOME2_DESKTOP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	py-gnome2-desktop
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-gnome2-desktop}
BUILDLINK_PACKAGES+=	py-gnome2-desktop
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}py-gnome2-desktop

.if ${PY_GNOME2_DESKTOP_BUILDLINK3_MK} == "+"
.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-gnome2-desktop+=	${PYPKGPREFIX}-gnome2-desktop>=2.16.0
BUILDLINK_PKGSRCDIR.py-gnome2-desktop?=		../../x11/py-gnome2-desktop
.endif	# PY_GNOME2_DESKTOP_BUILDLINK3_MK

.include "../../x11/py-gnome2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
