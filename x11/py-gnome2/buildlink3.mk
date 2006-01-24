# $NetBSD: buildlink3.mk,v 1.12 2006/01/24 07:32:59 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_GNOME2_BUILDLINK3_MK:=	${PY_GNOME2_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pygnome2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npygnome2}
BUILDLINK_PACKAGES+=	pygnome2

.if !empty(PY_GNOME2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pygnome2+=	${PYPKGPREFIX}-gnome2>=2.10.0
BUILDLINK_RECOMMENDED.pygnome2?=	${PYPKGPREFIX}-gnome2>=2.12.1nb2
BUILDLINK_PKGSRCDIR.pygnome2?=	../../x11/py-gnome2
.endif	# PY_GNOME2_BUILDLINK3_MK

.include "../../net/py-ORBit/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
