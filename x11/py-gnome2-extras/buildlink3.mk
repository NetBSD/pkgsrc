# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/05/03 13:19:19 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_GNOME2EX_BUILDLINK3_MK:=	${PY_GNOME2EX_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pygnome2ex
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npygnome2ex}
BUILDLINK_PACKAGES+=	pygnome2ex

.if !empty(PY_GNOME2EX_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pygnome2ex+=	${PYPKGPREFIX}-gnome2-extras>=2.10.1
BUILDLINK_RECOMMENDED.pygnome2ex?=	${PYPKGPREFIX}-gnome2-extras>=2.10.1
BUILDLINK_PKGSRCDIR.pygnome2ex?=	../../x11/py-gnome2-extras
.endif	# PY_GNOME2EX_BUILDLINK3_MK

.include "../../x11/py-gnome2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
