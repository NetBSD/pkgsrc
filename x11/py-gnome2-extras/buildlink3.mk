# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:11:15 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PYGNOME2EX_BUILDLINK3_MK:=	${PYGNOME2EX_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	pygnome2ex
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npygnome2ex}
BUILDLINK_PACKAGES+=	pygnome2ex
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pygnome2ex

.if ${PYGNOME2EX_BUILDLINK3_MK} == "+"
.include "../../lang/python/pyversion.mk"
BUILDLINK_API_DEPENDS.pygnome2ex+=	${PYPKGPREFIX}-gnome2-extras>=2.12.0nb3
BUILDLINK_ABI_DEPENDS.pygnome2ex+=	${PYPKGPREFIX}-gnome2-extras>=2.12.0nb7
BUILDLINK_PKGSRCDIR.pygnome2ex?=	../../x11/py-gnome2-extras
.endif	# PYGNOME2EX_BUILDLINK3_MK

.include "../../x11/py-gnome2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
